#ifndef RENNSMOTORSPORT_SCHEDULER_H
#define RENNSMOTORSPORT_SCHEDULER_H

#include <iostream>

#include <queue>
#include <chrono>
#include <memory>
#include <thread>
#include "Sensor.h"
#include "DataLogger.h" // For highResTime

template <typename T>
struct Task {
    int id;
    int frequency; // in Hz
    highResTime nextExecTime;
    std::shared_ptr<Sensor<T>> sensor;

    Task(int id, int freq, std::shared_ptr<Sensor<T>> sen)
        : id(id), frequency(freq), nextExecTime{}, sensor(std::move(sen)) {}

    // Used by the priority_queue to sort the tasks.
    auto operator<(const Task& rhs) const -> bool {
        return nextExecTime > rhs.nextExecTime;
    }
};

template <typename T>
class Scheduler {
public:
    Scheduler() = default;
    template <typename SensorType>
    void registerSensorTask(int id, int frequency, SensorType& sensor);
    void run();

private:
    std::priority_queue<Task<T>> tasks; // TODO: Need to switch to a better thing for simutanuous running of sensors

    auto getCurrentTime() const -> highResTime {
        return std::chrono::high_resolution_clock::now();
    }
};

template <typename T>
template <typename SensorType>
void Scheduler<T>::registerSensorTask(int id, int frequency, SensorType& sensor) {
    std::shared_ptr<SensorType> sensorPtr = std::make_shared<SensorType>(sensor);
    std::shared_ptr<Sensor<T>> basePtr = std::static_pointer_cast<Sensor<T>>(sensorPtr);

    Task<T> newTask(id, frequency, basePtr);
    newTask.nextExecTime = getCurrentTime();
    tasks.push(newTask);
}

template <typename T>
void Scheduler<T>::run() {
    if (tasks.empty()) return;

    while (true) {  // Endless for now
        auto currentTime = getCurrentTime();
        auto task = tasks.top();

        if (currentTime >= task.nextExecTime) {
            const T sensorData = task.sensor->getDataLog().getDataAtTime(currentTime);
            // TODO: do something with data
            std::cout << task.sensor->getSensorName() << " Sensor Data: " << sensorData << std::endl;

            // Update the next execution time for this task
            auto nextTime = task.nextExecTime + std::chrono::milliseconds(1000 / task.frequency);
            task.nextExecTime = nextTime;

            // Since std::priority_queue doesn't allow for reordering, we'll have to make a new task and push it back.
            tasks.pop();
            tasks.push(task);
        } else {
            // Not time to run this task yet; maybe sleep for a bit before checking again
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}


#endif // RENNSMOTORSPORT_SCHEDULER_H

/* Amar List of things to do:
 * need a queue ✓
 * link to pull data ✓
 * register stuff func (& to sensor obj), addTask ✓
 * id ✓
 * ignore bms and imd for now ✓
*/

/*
 * Compile, and bug fix
 * print data somehow
 * ask amar about the simutanious running thing
*/