#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/Sensors/AnalogSensors/App.h"
#include "../Frameworks/Sensors/AnalogSensors/App.cpp"

#ifndef RENNSMOTORSPORT_APP_TEST_CPP
#define RENNSMOTORSPORT_APP_TEST_CPP

class AppTest{
public:
    AppTest() : a(0,0,0) {}
    void RunTests() {
        std::cout<<"Running PedalPosition Tests"<<std::endl;
        std::cout<<"Test Get Position 1 volt: "<< (getPosition(1, -33.75) ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Get Position 2 volts: "<< (getPosition(2, -11.25) ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Get Position 3 volts: "<< (getPosition(3, 11.25) ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Get Position 4 volts: "<< (getPosition(4, 33.75) ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getPosition(UDOUBLE rawVal, float expectedPos){
        a.update(rawVal);
        if((a.get_position() - expectedPos) < error){
            return true;
        }
        return false;
    }

    float error = 2.0; //This might need adjusting when we calibrate the actual car

    App a;
};

#endif