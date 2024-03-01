#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/Sensors/AnalogSensors/Accelerometer.h"
#include "../Frameworks/Sensors/AnalogSensors/Accelerometer.cpp"

class AccelerometerTest{
public:
    AccelerometerTest() { a = Accelerometer(); }
    void RunTests(float expectedVal) {
        a.update()
        std::cout<<"Running Accelerometer Tests"<<std::endl;
        std::cout<<"Test Get Position status: "<< (getAccel(expectedVal) ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getAccel(float expectedVal){
        if((a.get_value() - expectedVal) < 0.01){
            return true;
        }
        return false;
    }

    uint32_t inputValue = 0.0; //TODO: once the transfer function is implemented in Temperature.cpp,
                               //      this should be updated to acurately test the transfer function
    Accelerometer a;
};