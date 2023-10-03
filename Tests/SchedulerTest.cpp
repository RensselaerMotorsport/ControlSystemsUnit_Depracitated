#include <iostream>
#include <chrono>
#include <thread>
#include "../Frameworks/Scheduler.h"

// Sensors
#include "../Frameworks/Sensors/Accelerometer.h"
#include "../Frameworks/Sensors/BrakePressure.h"
#include "../Frameworks/Sensors/GPS.h"
#include "../Frameworks/Sensors/ShockPot.h"
#include "../Frameworks/Sensors/Temperature.h"
#include "../Frameworks/Sensors/WheelSpeed.h"

class SchedulerTest {
public:
    void RunTests() {
        std::cout << "Running Scheduler Tests" << std::endl;
        std::cout << "Test Task Execution: \n" << (TestTaskExecution() ? "Passed" : "Failed") << std::endl;
        // std::cout << "Test Timing Accuracy: " << (TestTimingAccuracy() ? "Passed" : "Failed") << std::endl;
    }

private:

    // This test should check if tasks are being executed as expected
    bool TestTaskExecution() {
        Scheduler scheduler;

        // Add some tasks to the scheduler here
        int id = 0;
        //Accelerometer accelerometer(0 , 0, 100);
        //scheduler.registerAnalogSensor(id++, accelerometer);
        //BrakePressure BrakePressure;
        //scheduler.registerSensorTask(id++, 100, BrakePressure);
        //GPS gps;
        //scheduler.registerSensorTask(id++, 10, gps);
        //ShockPot shockPot;
        //scheduler.registerSensorTask(id++, 1000, shockPot); // Theres gonna be 4 of these
        Temperature temperature(0, 0, 10);
        scheduler.registerAnalogSensor(id++, temperature); // Might not be 10 HZ
        //WheelSpeed wheelSpeed;
        //scheduler.registerSensorTask(id++, 200, wheelSpeed); // 4 here too


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
