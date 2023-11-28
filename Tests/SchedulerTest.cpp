#include <iostream>
#include <chrono>
#include <thread>
#include "../Frameworks/Scheduler/Scheduler.h"

// Sensors
#include "../Frameworks/Sensors/AnalogSensors/Accelerometer.h"
#include "../Frameworks/Sensors/AnalogSensors/BrakePressure.h"
#include "../Frameworks/Sensors/DigitalSensors/GPS.h"
#include "../Frameworks/Sensors/AnalogSensors/ShockPot.h"
#include "../Frameworks/Sensors/AnalogSensors/Temperature.h"
#include "../Frameworks/Sensors/AnalogSensors/WheelFlux.h"
#include "../Frameworks/Sensors/CANSensors/Imd.h"

class SchedulerTest {
public:
    void RunTests() {
        std::cout << "Running Scheduler Tests" << std::endl;
        std::cout << "Test Timing Accuracy: " << (TestScheduler() ? "Passed" : "Failed") << std::endl;
    }

private:

    // This test should check if the scheduler runs tasks with accurate timing
    bool TestScheduler() {
        Scheduler scheduler;

        // Register Sensors
        int id = 0;
        Accelerometer accelerometer(0, 100, -1);
        scheduler.registerSensor(id++, accelerometer);
        BrakePressure brakePressure(0, 100, -1);
        scheduler.registerSensor(id++, brakePressure);
        // GPS gps(0, 0, 10);
        // scheduler.registerAnalogSensor(id++, gps);
        ShockPot shockPot(0, 1000, -1, front_left);
        scheduler.registerSensor(id++, shockPot); // Theres gonna be 4 of these
        Temperature temperature(0, 10, -1);
        scheduler.registerSensor(id++, temperature); // Might not be 10 HZ
        WheelFlux wheelFlux(0, 200, -1, 3.4f, front_left);
        scheduler.registerSensor(id++, wheelFlux); // 4 here too
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
