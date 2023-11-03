/*
 * -----------------------------------------------------------------
 *   _____      _              _       _
 *  / ____|    | |            | |     | |
 * | (___   ___| |__   ___  __| |_   _| | ___ _ __
 *  \___ \ / __| '_ \ / _ \/ _` | | | | |/ _ \ '__|
 *  ____) | (__| | | |  __/ (_| | |_| | |  __/ |
 * |_____/ \___|_| |_|\___|\__,_|\__,_|_|\___|_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: The Scheduler class is responsible for managing and
 *                 executing tasks in a timely manner. It utilizes a
 *                 priority queue to manage tasks and ensures they are
 *                 executed at the appropriate times, facilitating the
 *                 coordination and management of sensor data and tasks
 *                 in the control system.
 *
 * Member Variables:
 * - tasks: A priority queue that manages tasks based on their next
 *          execution time.
 * - running: A boolean flag indicating whether the scheduler is running.
 *
 * Member functions:
 * - registerSensor: Registers a sensor with the scheduler, creating a
 *                   task for it in the priority queue.
 * - run: Begins the scheduler's execution, managing and executing tasks.
 * - stop: Stops the scheduler from running.
 * - getCurrentTime: Retrieves the current high-resolution time.
 *
 */
#ifndef RENNSMOTORSPORT_SCHEDULER_H
#define RENNSMOTORSPORT_SCHEDULER_H

#include <iostream>
#include <queue>
#include <memory>
#include "Task.h"
#include "../Sensors/Sensor.h"
#include "../Sensors/AnalogSensor.h"
#include "../Sensors/DataLogger.h" // For highResTime

class Scheduler {
public:
    Scheduler() = default;
    ~Scheduler();
    template <typename T,
              typename I>
    void registerSensor(int id, Sensor<T, I>& sensor);
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

template <typename T
         ,typename I>
void Scheduler::registerSensor(int id, Sensor<T, I>& sensor) {
    auto sensorPtr = std::make_shared<Sensor<T, I>>(sensor);
    auto task = std::make_shared<Task<T, I>>(id, sensor.getHZ(), sensorPtr);
    tasks.push(task);
}

#endif //RENNSMOTORSPORT_SCHEDULER_H