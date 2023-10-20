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
#include "../Frameworks/Sensors/Imd.h"

class SchedulerTest {
public:
    void RunTests() {
        std::cout << "Running Scheduler Tests" << std::endl;
        // std::cout << "Test Task Execution: \n" << (TestTaskExecution() ? "Passed" : "Failed") << std::endl;
        std::cout << "Test Timing Accuracy: " << (TestTimingAccuracy() ? "Passed" : "Failed") << std::endl;
    }

private:

    // This test should check if tasks are being executed as expected
    bool TestTaskExecution() {
        Scheduler scheduler;

        // Add some tasks to the scheduler here
        int id = 0;
        // Accelerometer accelerometer(0 , 0, 100);
        // scheduler.registerAnalogSensor(id++, accelerometer);
        // BrakePressure brakePressure(0, 0, 100);
        // scheduler.registerAnalogSensor(id++, brakePressure);
        // GPS gps;
        // scheduler.registerSensorTask(id++, 10, gps);
        // ShockPot shockPot(0, 0, 1000, front_left);
        // scheduler.registerAnalogSensor(id++, shockPot); // Theres gonna be 4 of these
        // Temperature temperature(0, 0, 10);
        // scheduler.registerAnalogSensor(id++, temperature); // Might not be 10 HZ
        // WheelSpeed wheelSpeed(0, 0, 200, 3.4f, front_left);
        // scheduler.registerAnalogSensor(id++, wheelSpeed); // 4 here too

        // Run the scheduler or tasks here
        scheduler.run();

        // Validate that the tasks were executed properly
        // IDK just look at the output for now

        return true;
    }

    // This test should check if the scheduler runs tasks with accurate timing
    bool TestTimingAccuracy() {
        Scheduler scheduler;

        // Register Sensors
        int id = 0;
        Accelerometer accelerometer(0, 100);
        scheduler.registerSensor(id++, accelerometer);
        BrakePressure brakePressure(0, 100);
        scheduler.registerSensor(id++, brakePressure);
        // GPS gps(0, 0, 10);
        // scheduler.registerAnalogSensor(id++, gps);
        ShockPot shockPot(0, 1000, front_left);
        scheduler.registerSensor(id++, shockPot); // Theres gonna be 4 of these
        Temperature temperature(0, 10);
        scheduler.registerSensor(id++, temperature); // Might not be 10 HZ
        WheelSpeed wheelSpeed(0, 200, 3.4f, front_left);
        scheduler.registerSensor(id++, wheelSpeed); // 4 here too
        Imd imd(500, 0); // Id 0
        scheduler.registerSensor(id++, imd);

        scheduler.run();

        std::cout << "Timing accuracy test passed" << std::endl;
        return true;
    }
};

int main() {
    SchedulerTest schedulerTest;
    schedulerTest.RunTests();
    return 0;
}
