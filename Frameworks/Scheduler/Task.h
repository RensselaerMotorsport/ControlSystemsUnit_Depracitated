/*
 * -----------------------------------------------------------------
 *  _______        _
 * |__   __|      | |
 *    | | __ _ ___| | __
 *    | |/ _` / __| |/ /
 *    | | (_| \__ \   <
 *    |_|\__,_|___/_|\_\
 *
 * ------------------------------------------------------------------
 *
 * Class Function: The Task class, and its base class TaskBase, manage the
 *                 execution of tasks related to sensor data retrieval and
 *                 logging in the control system. Task utilizes a template
 *                 to accommodate different sensor data types and ensures
 *                 tasks are executed with consideration to timing and
 *                 sensor type.
 *
 * TaskBase - an abstract base class for Task.
 *
 * Member Variables (Task):
 * - id: An identifier for the task.
 * - hZ: The frequency (in Hz) at which the task should be executed.
 * - sensor: A shared pointer to the sensor associated with the task.
 * - nextExecTime: The next scheduled execution time for the task.
 *
 * Member functions (Task):
 * - execute: Executes the task, retrieving and logging sensor data.
 * - getNextExecTime: Retrieves the next scheduled execution time.
 * - setNextExecTime: Sets the next scheduled execution time.
 * - WriteDataToFile: Calls the sensor function under the same name.
 * - getHZ: Retrieves the execution frequency of the task.
 * - getId: Retrieves the identifier of the task.
 * - operator<: Compares this task with another based on next execution time.
 *
 */
#ifndef RENNSMOTORSPORT_TASK_H
#define RENNSMOTORSPORT_TASK_H

// TODO: Filter the ones used
#include <iostream>
#include <queue>
#include <memory>
#include "../Sensors/Sensor.h"
#include "../Sensors/AnalogSensor.h"
#include "../Sensors/DataLogger.h" // For highResTime

class TaskBase {
public:
    virtual ~TaskBase() = default;
    virtual bool operator<(const TaskBase& rhs) const = 0;
    virtual void execute(highResTime startTime, highResTime enqueueTime) = 0;
    virtual auto getNextExecTime() const -> highResTime = 0;
    virtual auto setNextExecTime(highResTime time) -> void = 0;
    virtual void writeDataToFile(std::string filename) = 0;
    virtual auto getHZ() const -> int = 0;
    virtual auto getId() const -> int = 0;
};

template <typename T,
          typename I>
class Task : public TaskBase {
public:
    Task(int id, int hZ, std::shared_ptr<Sensor<T, I>> sensorPtr)
        : id(id), hZ(hZ), sensor(sensorPtr) {
            nextExecTime = std::chrono::high_resolution_clock::now();
        }

    void execute(highResTime startTime, highResTime enqueueTime) override {
        // Read data from sensor and update the sensor's data log
        I sensorData = sensor->getData();
        // std::cout << sensor->getSensorName() << " Sensor Data: " << sensorData << std::endl;
        sensor->update(sensorData);

        auto delay = startTime - enqueueTime;
        if (delay > std::chrono::microseconds(1000)) {
            std::cout << "\033[31m"  // Set text color to red
                    << "Execution delay: "
                    << std::chrono::duration_cast<std::chrono::microseconds>(delay).count()
                    << " microseconds"
                    << "\033[0m" << std::endl;  // Reset text color
        }
    }

    auto getNextExecTime() const -> highResTime { return nextExecTime; }
    auto setNextExecTime(highResTime time) -> void { nextExecTime = time; }
    void writeDataToFile(std::string filename) { sensor->writeDataToFile(filename); }
    auto getHZ() const -> int { return hZ; }
    auto getId() const -> int { return id; }

    bool operator<(const TaskBase& rhs) const override {
        const Task& derivedRhs = static_cast<const Task&>(rhs);
        return nextExecTime > derivedRhs.nextExecTime;
    }

private:
    int id;
    int hZ;
    std::shared_ptr<Sensor<T, I>> sensor;
    highResTime nextExecTime;
};

struct TaskComparator {
    bool operator()(const std::shared_ptr<TaskBase>& lhs,
        const std::shared_ptr<TaskBase>& rhs) const {
        return *lhs < *rhs;
    }
};

#endif //RENNSMOTORSPORT_TASK_H