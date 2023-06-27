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

#include <string>
#include <iostream>
#include "../Frameworks/DataLogger.h"
#include "DataLoggerTest.cpp"
#include "../Frameworks/Temperature.h"
#include "TemperatureTest.cpp"

int main(int argc, char* argv[]) {
    std::string input = argv[1];
    if (input == "All") {
        DataLoggerTest dlt = DataLoggerTest();
        dlt.RunTests();
        TemperatureTest tmpTest = TemperatureTest();
        tmpTest.RunTests();
    } else if (input == "DataLogger") {
        DataLoggerTest dlt = DataLoggerTest();
        dlt.RunTests();
    } else if (input == "Temperature") {
        TemperatureTest tmpTest = TemperatureTest();
        tmpTest.RunTests();
    }
    else {
        std::cerr << "INCORRECT USAGE:\n" <<
                  "USAGE: ./MainTest.o \"Test\"\n" <<
                  "Available Tests:\n" <<
                  "All\n" <<
                  "DataLogger\n" << std::endl;
    }
}