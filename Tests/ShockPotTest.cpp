//
// Created by glynne on 9/25/2023.
//


#include <iostream>
#include <random>
#include "../Frameworks/Sensors/ShockPot.h"
#include "../Frameworks/Sensors/ShockPot.cpp"

class ShockPotTest{
public:
    ShockPotTest(){ sp = ShockPot(); }
    void runTests(){
        std::cout << "Running ShotPot tests" << std::endl;
        std::cout << "Testing 15 volts: " << (testShockPot(10, 15) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 30 volts: " << (testShockPot(30, 30) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 45 volts: " << (testShockPot(50, 45) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 65 volts: " << (testShockPot(75, 65) ? "Passed" : "Failed") << std::endl;
        std::cout << "Testing 135 volts: " << (testShockPot(150, 135) ? "Passed" : "Failed") << std::endl;

    }
private:
    bool testShockPot(float expectedDistance_, float rawVal_){
        sp.update(rawVal_);
        //the error can be +- 2.5mm in some of the worst cases; more data needed for better accuracy
        if(sp.get_distance() - expectedDistance_ < 2.5){
            return true;
        }
        return false;
    }
    float expectedDistance;
    ShockPot sp;
};

int main(){
    ShockPotTest spt;
    spt.runTests();
    return 0;
}
