#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/Sensors/AnalogSensors/App.h"
#include "../Frameworks/Sensors/AnalogSensors/App.cpp"

class AppTest{
public:
    AppTest() : a(0,0,0) {}
    void RunTests() {
        a.update();
        std::cout<<"Running PedalPosition Tests"<<std::endl;
        std::cout<<"Test Get Position status: "<< (getPosition() ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getPosition(){
        if((a.get_position() - expectedPos) < 0.01){
            return true;
        }
        return false;
    }

    float expectedPos = 10;

    uint32_t inputValue = 0.0; //TODO: once the transfer function is implemented in Temperature.cpp,
                               //      this should be updated to acurately test the transfer function
    App a;
};
