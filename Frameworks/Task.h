#ifndef RENNSMOTORSPORT_TASK_H
#define RENNSMOTORSPORT_TASK_H

// TODO: Filter the ones used
#include <iostream>
#include <queue>
#include <memory>
#include "Task.h"
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

#endif //RENNSMOTORSPORT_TASK_H