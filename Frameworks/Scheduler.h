#ifndef RENNSMOTORSPORT_SCHEDULER_H
#define RENNSMOTORSPORT_SCHEDULER_H

#include <iostream>
#include <queue>
#include <chrono>
#include <memory>
#include <thread>
#include "Sensor.h"
#include "AnalogSensor.h"
#include "DataLogger.h" // For highResTime

class TaskBase {
public:
    virtual ~TaskBase() = default;
    virtual bool operator<(const TaskBase& rhs) const = 0;
    virtual void execute(highResTime currentTime) = 0;
    virtual auto getNextExecTime() const -> highResTime = 0;
    virtual auto setNextExecTime(highResTime time) -> void = 0;
    virtual auto getHZ() const -> int = 0;
    virtual auto getId() const -> int = 0;
};

template <typename T>
class Task : public TaskBase {
public:
    Task(int id, int hZ, std::shared_ptr<Sensor<T>> sensorPtr)
        : id(id), hZ(hZ), sensor(sensorPtr) {
            nextExecTime = std::chrono::high_resolution_clock::now();
        }

    void execute(highResTime currentTime) override {
        const T sensorData = sensor->getDataLog().getDataAtTime(currentTime);
        // TODO: do something with data
        std::cout << sensor->getSensorName() << " Sensor Data: " << sensorData << std::endl;
    }
    auto getNextExecTime() const -> highResTime {
        return nextExecTime;
    }
    auto setNextExecTime(highResTime time) -> void {
        nextExecTime = time;
    }
    auto getHZ() const -> int {
        return hZ;
    }
    auto getId() const -> int {
        return id;
    }

    bool operator<(const TaskBase& rhs) const override {
        const Task& derivedRhs = static_cast<const Task&>(rhs);
        return nextExecTime > derivedRhs.nextExecTime;
    }
private:
    int id;
    int hZ;
    std::shared_ptr<Sensor<T>> sensor;
    highResTime nextExecTime;
};

struct TaskComparator {
    bool operator()(const std::shared_ptr<TaskBase>& lhs,
        const std::shared_ptr<TaskBase>& rhs) const {
        return *lhs < *rhs;
    }
};

class Scheduler {
public:
    Scheduler() = default;
    template <typename T>
    void registerAnalogSensor(int id, AnalogSensor<T>& sensor);
    void run();

private:
    // TODO: Need to switch to a better thing for simutanuous running of sensors
    std::priority_queue<std::shared_ptr<TaskBase>,
        std::vector<std::shared_ptr<TaskBase>>, TaskComparator> tasks;

    auto getCurrentTime() const -> highResTime {
        return std::chrono::high_resolution_clock::now();
    }
};

template <typename T>
void Scheduler::registerAnalogSensor(int id, AnalogSensor<T>& sensor) {
    auto sensorPtr = std::make_shared<AnalogSensor<T>>(sensor);
    auto task = std::make_shared<Task<T>>(id, sensor.getHZ(), sensorPtr);
    tasks.push(task);
}

void printPriorityQueue(std::priority_queue<std::shared_ptr<TaskBase>>& tasks) {
    std::priority_queue<std::shared_ptr<TaskBase>> temp;

    // Print and transfer tasks to the temporary priority queue
    while (!tasks.empty()) {
        std::shared_ptr<TaskBase> task = tasks.top();
        tasks.pop();

        // Print the task details here. For example:
        // Ensure that you use the "->" operator to access members of the shared_ptr object.
        std::cout << "Task Next Execution Time: " 
                  << task->getNextExecTime().time_since_epoch().count() << '\n';

        // Push the task to the temporary priority queue
        temp.push(task);
    }

    // Restore the tasks to the original priority queue
    while (!temp.empty()) {
        tasks.push(temp.top());
        temp.pop();
    }
}

void Scheduler::run() {
    if (tasks.empty()) return;

    while (true) {  // Endless for now
        auto currentTime = getCurrentTime();
        std::shared_ptr<TaskBase> task = tasks.top();

        if (currentTime >= task->getNextExecTime()) {
            task->execute(currentTime);

            // Update the next execution time for this task
            highResTime nextTime = task->getNextExecTime() + std::chrono::milliseconds(1000 / task->getHZ());
            task->setNextExecTime(nextTime);

            // Since std::priority_queue doesn't allow for reordering,
            // we'll have to make a new task and push it back.
            tasks.pop();
            tasks.push(task);
        } else {
            // Not time to run this task yet; maybe sleep for a bit before checking again
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

#endif // RENNSMOTORSPORT_SCHEDULER_H