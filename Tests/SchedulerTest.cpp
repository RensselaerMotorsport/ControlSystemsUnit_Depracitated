#include <iostream>
#include <chrono>
#include <thread>
#include "../Frameworks/Scheduler.h"

// Sensors
#include "../Frameworks/Sensors/Accelerometer.h"
#include "../Frameworks/Sensors/Temperature.h"

class SchedulerTest {
public:
    void RunTests() {
        std::cout << "Running Scheduler Tests" << std::endl;
        std::cout << "Test Task Execution: " << (TestTaskExecution() ? "Passed" : "Failed") << std::endl;
        // std::cout << "Test Timing Accuracy: " << (TestTimingAccuracy() ? "Passed" : "Failed") << std::endl;
    }

private:

    // This test should check if tasks are being executed as expected
    bool TestTaskExecution() {
        Scheduler<float> scheduler;

        // Add some tasks to the scheduler here
        int id = 0;
        Accelerometer accelerometer;
        scheduler.registerSensorTask(id++, 100, accelerometer);
        Temperature temperature;
        scheduler.registerSensorTask(id++, 10, temperature); // Might not be 10 HZ

        // Run the scheduler or tasks here
        scheduler.run();

        // Validate that the tasks were executed properly
        // IDK just look at the output for now

        return true;
    }

    // This test should check if the scheduler runs tasks with accurate timing
    bool TestTimingAccuracy() {
        // Init scheduler

        // Add some time-sensitive tasks to the scheduler here

        // Run the scheduler or tasks here

        // Validate the timing of task executions

        return true;  // return false if the test fails
    }
};

int main() {
    SchedulerTest schedulerTest;
    schedulerTest.RunTests();
    return 0;
}
