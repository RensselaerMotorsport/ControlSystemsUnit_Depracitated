/*
 * -------------------------------------------------------------------------
 *
 *  ███╗   ███╗ █████╗ ██╗███╗   ██╗    ████████╗███████╗███████╗████████╗
 *  ████╗ ████║██╔══██╗██║████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝
 *  ██╔████╔██║███████║██║██╔██╗ ██║       ██║   █████╗  ███████╗   ██║
 *  ██║╚██╔╝██║██╔══██║██║██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║
 *  ██║ ╚═╝ ██║██║  ██║██║██║ ╚████║       ██║   ███████╗███████║   ██║
 *  ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝
 *
 * -------------------------------------------------------------------------
 *
 *
 *
 */

#include <cstring>
#include <iostream>
#include "../Frameworks/Sensors/DataLogger.h"
#include "../Frameworks/Sensors/AnalogSensors/Temperature.h"
#include "DataLoggerTest.cpp"
#include "TemperatureTest.cpp"
#include "MotorControllerTest.cpp"
#include "SensorTest.cpp"
#include "ShockPotTest.cpp"

void DataLoggerT(){
    DataLoggerTest dlt = DataLoggerTest();
    dlt.RunTests();
}

void TemperatureT(){
    TemperatureTest tmpTest = TemperatureTest();
    tmpTest.RunTests();
}

void MotorControllerT(){
    MotorControllerTest mct = MotorControllerTest();
    mct.RunTests(0.0f); // FIXME: Expected position placeholder
}

void SensorT(){
    SensorTest st = SensorTest();
    st.RunTests();
}

void ShockPotT(){
    ShockPotTest spt = ShockPotTest();
    spt.runTests();
}

//Complie with -D TEST_MODE in order to run these tests
int main(int argc, char* argv[]) {
    #ifndef TEST_MODE
    std::cerr << "ERROR: Test mode is not enabled\nPlease compile with '-D TEST_MODE' to enable test mode" << std::endl;
    return 0;
    #endif
    for(int i = 1; i < argc; i++) {
        if (0 == strcmp(argv[i], "All")) {
            DataLoggerT();
            TemperatureT();
            MotorControllerT();
            SensorT();
            ShockPotT();
        } else if (0 == strcmp(argv[i], "DataLogger")) {
            DataLoggerT();
        } else if (0 == strcmp(argv[i], "Temperature")) {
            TemperatureT();
        } else if (0 == strcmp(argv[i], "MotorController")) {
            MotorControllerT();
        } else if (0 == strcmp(argv[i], "Sensor")) {
            SensorT();
        } else if (0 == strcmp(argv[i], "ShockPot")) {
            ShockPotT();
        } else {
            std::cerr << "INCORRECT USAGE:\n" <<
                      "USAGE: ./MainTest.o \"Test\"\n" <<
                      "Available Tests:\n" <<
                      "All\n" <<
                      "DataLogger\n" <<
                      "Temperature\n" <<
                      "MotorController\n" <<
                      "Sensor\n" <<
                      "ShockPot\n";
        }
    }
}


