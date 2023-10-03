#ifndef RENNSMOTORSPORT_SCHEDULER_H
#define RENNSMOTORSPORT_SCHEDULER_H

#include <iostream>
#include <queue>
#include <memory>
#include "Task.h"
#include "Sensor.h"
#include "AnalogSensor.h"
#include "DataLogger.h" // For highResTime

class Scheduler {
public:
    Scheduler() = default;
    template <typename T>
    void registerAnalogSensor(int id, AnalogSensor<T>& sensor);
    void run();
    void stop() { running = false; }

private:
    std::priority_queue<std::shared_ptr<TaskBase>,
        std::vector<std::shared_ptr<TaskBase>>, TaskComparator> tasks;
    bool running = false;

    auto getCurrentTime() const -> highResTime {
        return std::chrono::high_resolution_clock::now();
    }
};

// Template definitions

template <typename T>
void Scheduler::registerAnalogSensor(int id, AnalogSensor<T>& sensor) {
    auto sensorPtr = std::make_shared<AnalogSensor<T>>(sensor);
    auto task = std::make_shared<Task<T>>(id, sensor.getHZ(), sensorPtr);
    tasks.push(task);
}

#endif //RENNSMOTORSPORT_SCHEDULER_H