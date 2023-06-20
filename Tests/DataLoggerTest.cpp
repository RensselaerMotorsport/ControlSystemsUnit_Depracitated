/*
 * -------------------------------------------------------------------------------------------------------------------------------
 *
 *  ██████╗  █████╗ ████████╗ █████╗     ██╗      ██████╗  ██████╗  ██████╗ ███████╗██████╗     ████████╗███████╗███████╗████████╗
 *  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗    ██║     ██╔═══██╗██╔════╝ ██╔════╝ ██╔════╝██╔══██╗    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
 *  ██║  ██║███████║   ██║   ███████║    ██║     ██║   ██║██║  ███╗██║  ███╗█████╗  ██████╔╝       ██║   █████╗  ███████╗   ██║
 *  ██║  ██║██╔══██║   ██║   ██╔══██║    ██║     ██║   ██║██║   ██║██║   ██║██╔══╝  ██╔══██╗       ██║   ██╔══╝  ╚════██║   ██║
 *  ██████╔╝██║  ██║   ██║   ██║  ██║    ███████╗╚██████╔╝╚██████╔╝╚██████╔╝███████╗██║  ██║       ██║   ███████╗███████║   ██║
 *  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚══════╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
 *
 * -------------------------------------------------------------------------------------------------------------------------------
 *
 *  Test Functions:
 *  Test immutableRefTest:
 *      Expected behavior: Tests that no returned dataLogger map can be modified in any way
 *
 *  Test (insert function of test):
 *      Expected behavior:
 *
 */

#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "../Frameworks/DataLogger.h"
#include "../Frameworks/DataLogger.cpp"

class DataLoggerTest{

public:
    DataLoggerTest(){ dl = DataLogger<double>(); std::time(&knownTime); }

    void RunTests() {
        std::cout<<"Running DataLogger Tests"<<std::endl;
        std::cout<<"Test Insert status: "<< (insertTest() ? "Passed" : "Failed") <<std::endl;
        std::cout<<"Test Immutable Reference status: "<< (immutableRefTest() ? "Passed" : "Failed") <<std::endl;
    }

private:
    //Tests the inserting of values.
    bool insertTest(){
        bool t = dl.addValue(knownTime, 10.2);
        if (!t) return false;

        double value;
        std::time_t time;
        std::time_t preTime;
        std::time(&preTime);
        for (int i = 1; i < 10; ++i) {
            value = (double) (i);
            sleep(1);
            std::time(&time);
            t = dl.addValue(time, value);
            if (!t) return false;
        }
        //try to insert a value before the others
        value = 21;
        t = dl.addValue(preTime, value);
        if (t) return false;
        return true;
    }

    //This is to make sure that by calling getMap, we cannot edit the values.
    bool immutableRefTest() {
        std::map<std::time_t, double> map;
        dl.getMap(map);
        //should throw an error maybe
        map[knownTime] = 13;
        if (map[knownTime] == 10.2){
            return true;
        } else {
            return false;
        }
    }
    std::time_t knownTime;
    DataLogger<double> dl;
};