#include "Scheduler.h"
#include <thread> // For Sleep
#include "ThreadPool.h" // Complile with -lpthread

void Scheduler::run() {
    if (tasks.empty()) return;
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::cout << "Number of threads: " << numThreads << std::endl; // TODO: Remove this later
    ThreadPool pool(numThreads);
    std::mutex tasksMutex;

    running = true;
    while (running) {
        auto currentTime = getCurrentTime();
        // Buffer to hold tasks that are ready to be executed
        std::vector<std::shared_ptr<TaskBase>> taskBuffer;

        // Lock the tasks priority queue while we're modifying it
        std::unique_lock<std::mutex> lock(tasksMutex);

        while (!tasks.empty() && currentTime >= tasks.top()->getNextExecTime()) {
            std::shared_ptr<TaskBase> task = tasks.top();
            task->execute(currentTime);

            // Update the next execution time for this task
            highResTime nextTime = task->getNextExecTime()
                + std::chrono::milliseconds(1000 / task->getHZ());
            task->setNextExecTime(nextTime);

            // Since std::priority_queue doesn't allow for reordering.
            tasks.pop();
            tasks.push(task);

            // Immediatly check the next task. Maybe two task are at the same time.
            continue;
        }

        // Unlock the tasks priority queue
        lock.unlock();

        // Submit all tasks in the task buffer to the thread pool for execution
        for (auto& task : taskBuffer) {
            pool.enqueue([task, currentTime] {
                task->execute(currentTime);
            });
        }

        // If there are no tasks ready to be executed, sleep until the next task is ready
        if (taskBuffer.empty() && !tasks.empty()) {
            std::chrono::milliseconds sleepTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                tasks.top()->getNextExecTime() - currentTime);
            std::this_thread::sleep_for(sleepTime);
        }
    }
}