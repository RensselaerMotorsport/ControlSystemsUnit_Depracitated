/*
 * -----------------------------------------------------------------
 *  _______            _                    _   _______        _
 * |__   __|          | |                  | | |__   __|      | |
 *    | | ___  _ __   | |     _____   _____| |    | | ___  ___| |_
 *    | |/ _ \| '_ \  | |    / _ \ \ / / _ \ |    | |/ _ \/ __| __|
 *    | | (_) | |_) | | |___|  __/\ V /  __/ |    | |  __/\__ \ |_
 *    |_|\___/| .__/  |______\___| \_/ \___|_|    |_|\___||___/\__|
 *            | |
 *            |_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: This classes function is to act as a top level class to call all sub-tests for all classes in the project
 *
 * Sub-test classes:
 * DataLoggerTest
 * MotorControllerTest
 * SensorTest
 * TemperatureTest
 *
 */
#include <string>

class TopLevelTest{
public:
    void runTests(){
        std::string errorMessage;
        //run every class's error class and add to the error string
    }
};