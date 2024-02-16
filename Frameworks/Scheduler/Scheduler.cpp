#include "Scheduler.h"
#include <thread> // For Sleep
#include "SensorADC.h"
#include "ThreadPool.h" // Complile with -lpthread

void Scheduler::run() {
    if (tasks.empty()) return;
    // Init
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::cout << "Number of threads: " << numThreads << std::endl;
    ThreadPool pool(numThreads);
    std::mutex tasksMutex;

    // InitADC();

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
            pool.enqueue([this, task, enqueueTime] {
                task->execute();

                auto endTime = std::chrono::system_clock::now();
                auto delay = endTime - enqueueTime;
                // If a callback is set, call it with the delay
                if (delayCallback) {
                    delayCallback(delay);
                }
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
        running = false;
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
    std::cout << "Scheduler Shutdown Successful." << std::endl;
}

void Scheduler::setDelayCallback(DelayCallback callback) {
    delayCallback = std::move(callback);
}
