//
// Created by glynne on 9/25/2023.
//


#include <iostream>
#include <random>
#include "../Frameworks/Sensors/AnalogSensors/ShockPot.h"
#include "../Frameworks/Sensors/AnalogSensors/ShockPot.cpp"

class ShockPotTest{
public:
    ShockPotTest() : sp(0, 0, 0, front_left) {} //These are default testing values
    void runTests(){
        std::cout << "Running ShotPot tests" << std::endl;
        std::cout << "Testing 15 volts: " << (testShockPot(15, 10) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 30 volts: " << (testShockPot(30, 30) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 45 volts: " << (testShockPot(45, 50) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 65 volts: " << (testShockPot(65, 75) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 135 volts: " << (testShockPot(135, 150) ? "Passed" : "Failed") << std::endl;

    }
private:
    bool testShockPot(UDOUBLE rawVal, float expectedDist){

        //TODO: figure out how testing will work because we cannot define a raw value to input to the sensor

        sp.update(rawVal);
        //the error can be +- 2.5mm in some of the worst cases; more data needed for better accuracy
        if(sp.get_distance() - expectedDist < 2.5){
            return true;
        }
        return false;
    }
    ShockPot sp;
};

int main(){
    ShockPotTest spt;
    spt.runTests();
    return 0;
}
