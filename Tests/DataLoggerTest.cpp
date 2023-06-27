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
        highResTime time;
        highResTime preTime;
        preTime = std::chrono::system_clock::now();
        for (int i = 1; i < 10; ++i) {
            value = (double) (i);
            usleep(5000);
            time = std::chrono::system_clock::now();
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
        std::map<highResTime, double>::const_iterator itr;
        itr = dl.getMap();
        if (itr->first != knownTime){
            return false;
        }
    }
    highResTime knownTime;
    DataLogger<double> dl;
};