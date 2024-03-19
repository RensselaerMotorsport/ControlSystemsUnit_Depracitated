#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/Sensors/AnalogSensors/Accelerometer.h"
#include "../Frameworks/Sensors/AnalogSensors/Accelerometer.cpp"

class AccelerometerTest{
public:
    AccelerometerTest() { a = Accelerometer(); }
    void RunTests() {
        a.update();
        std::cout<<"Running Accelerometer Tests"<<std::endl;
        std::cout<<"Test Get Position status: "<< (getAccel() ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getAccel(){
        if((a.get_value() - expectedVal) < 0.01){
            return true;
        }
        return false;
    }

    float expectedVal = 17.045;

    uint32_t inputValue = 0.0; //TODO: once the transfer function is implemented in Temperature.cpp,
                               //      this should be updated to acurately test the transfer function
    Accelerometer a;
};
