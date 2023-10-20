#include "Scheduler.h"
#include <thread> // For Sleep
#include "ThreadPool.h" // Complile with -lpthread
#include "../High-Pricision_AD_HAT/c/lib/Driver/ADS1263.h" // For Analog Sensor Read

void Scheduler::run() {
    if (tasks.empty()) return;
    // Init
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::cout << "Number of threads: " << numThreads << std::endl; // TODO: Remove this later
    ThreadPool pool(numThreads);
    std::mutex tasksMutex;

    // ADC 1 & 2 Initilization
    try {
        // Initializing ADC's at 1200 Samples Per Secons (SPS)
        if (ADS1263_init_ADC1(ADS1263_1200SPS) != 0)
            throw "ADC1 Initialization failed.";
        // TODO: Maybe dont need or need to change refreshrate?
        if (ADS1263_init_ADC2(ADS1263_ADC2_800SPS) != 0)
            throw "ADC2 Initialization failed.";
    } catch (const char* errorMsg) {
        std::cerr << errorMsg << std::endl;
        return;
    }

    running = true;
    while (running) {
        auto currentTime = getCurrentTime();
        // Buffer to hold tasks that are ready to be executed
        std::vector<std::shared_ptr<TaskBase>> taskBuffer;

        // Lock the tasks priority queue while we're modifying it
        std::unique_lock<std::mutex> lock(tasksMutex);

        while (!tasks.empty() && currentTime >= tasks.top()->getNextExecTime()) {
            std::shared_ptr<TaskBase> task = tasks.top();

            // Update the next execution time for this task
            highResTime nextTime = task->getNextExecTime()
                + std::chrono::milliseconds(1000 / task->getHZ());
            task->setNextExecTime(nextTime);

            taskBuffer.push_back(task);
            // Since std::priority_queue doesn't allow for reordering.
            tasks.pop();
            tasks.push(task);
        }

        // Unlock the tasks priority queue
        lock.unlock();

        // Submit all tasks in the task buffer to the thread pool for execution
        auto enqueueTime = std::chrono::system_clock::now();
        for (auto& task : taskBuffer) {
            pool.enqueue([task, enqueueTime] {
                auto startTime = std::chrono::system_clock::now();
                task->execute(startTime, enqueueTime);
            });
        }

        // If there are no tasks ready to be executed, sleep until the next task is ready
        // if (taskBuffer.empty() && !tasks.empty()) {
        //     std::chrono::milliseconds sleepTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        //         tasks.top()->getNextExecTime() - currentTime);
        //     std::this_thread::sleep_for(sleepTime);
        // }

        // Sleep for 1 millisecond
        if (taskBuffer.empty() && !tasks.empty()) {
            std::chrono::milliseconds sleepTime(1);  // sleep for 1 millisecond
            std::this_thread::sleep_for(sleepTime);
        }
    }
}

Scheduler::~Scheduler() {
    while(!tasks.empty()) {
        auto task = tasks.top();
        // TODO: Maybe add sensor name when function is made for that.
        std::string filename = std::to_string(task->getId()) + "_output.csv";
        task->writeDataToFile(filename);
        tasks.pop();
    }
}