#include "Scheduler.h"
#include <thread> // For Sleep
#include "ThreadPool.h" // Complile with -lpthread

void Scheduler::run() {
    if (tasks.empty()) return;

    running = true;
    while (running) {
        auto currentTime = getCurrentTime();
        std::shared_ptr<TaskBase> task = tasks.top();

        if (currentTime >= task->getNextExecTime()) {
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

        // Calculate the time until the next task and sleep for that duration
        auto sleepTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            task->getNextExecTime() - currentTime);
        std::this_thread::sleep_for(sleepTime);

    }
}