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
    void RunTests(float exCel, float exFer) {
        tmp.update()
        std::cout<<"Running Temperature Tests"<<std::endl;
        std::cout<<"Test Get Celsius status: "<< (getCel(exCel) ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Get Fahrenheit  status: "<< (getFer(exFer) ? "Passed" : "Failed") <<std::endl;
    }
private:
    bool getCel(float expectedCel){
        if((tmp.getCelsius() - expectedCel) < 0.01){
            return true;
        }
        return false;
    }
    bool getFer(float expectedFer){
        if((tmp.getFahrenheit() - expectedFer) < 0.01){
            return true;
        }
        return false;
    }
    Temperature tmp;
};