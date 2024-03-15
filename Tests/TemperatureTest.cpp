/*
 * --------------------------------------------------------------------------------------------------------------------------------------
 *
 *  ████████╗███████╗███╗   ███╗██████╗ ███████╗██████╗  █████╗ ████████╗██╗   ██╗██████╗ ███████╗    ████████╗███████╗███████╗████████╗
 *  ╚══██╔══╝██╔════╝████╗ ████║██╔══██╗██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██╔══██╗██╔════╝    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
 *     ██║   █████╗  ██╔████╔██║██████╔╝█████╗  ██████╔╝███████║   ██║   ██║   ██║██████╔╝█████╗         ██║   █████╗  ███████╗   ██║
 *     ██║   ██╔══╝  ██║╚██╔╝██║██╔═══╝ ██╔══╝  ██╔══██╗██╔══██║   ██║   ██║   ██║██╔══██╗██╔══╝         ██║   ██╔══╝  ╚════██║   ██║
 *     ██║   ███████╗██║ ╚═╝ ██║██║     ███████╗██║  ██║██║  ██║   ██║   ╚██████╔╝██║  ██║███████╗       ██║   ███████╗███████║   ██║
 *     ╚═╝   ╚══════╝╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
 *
 * --------------------------------------------------------------------------------------------------------------------------------------
 *
 * Test Functions:
 *      Test (insert function of test):
 *          Expected behavior:
 *
 *      Test (insert function of test):
 *          Expected behavior:
 *
 */

#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/Sensors/AnalogSensors/Temperature.h"
#include "../Frameworks/Sensors/AnalogSensors/Temperature.cpp"

class TemperatureTest{
public:
    TemperatureTest() { tmp = Temperature(0, 0, 0); }
    void RunTests() {
        tmp.update()
        std::cout<<"Running Temperature Tests"<<std::endl;
        std::cout<<"Test Get Celsius status: "<< (getCel() ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Get Fahrenheit  status: "<< (getFer() ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getCel(){
        if((tmp.getCelsius() - expectedCel) < 0.01){
            return true;
        }
        return false;
    }
    bool getFer(){
        if((tmp.getFahrenheit() - expectedFer) < 0.01){
            return true;
        }
        return false;
    }
    Temperature tmp;
    int expectedCel = 0.0; //TODO: This is currently freezing because the transfer function in Tempurature.cpp is not implemented
    float expectedFer = 32.0;
};