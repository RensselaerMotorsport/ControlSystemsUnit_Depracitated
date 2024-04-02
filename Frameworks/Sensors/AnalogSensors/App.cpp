//
// Created by harshk on 11/3/2023.
//

#include "App.h"
// Temp inxlude for testing app sensor
#include <iostream>

float App::transfer_function(UDOUBLE rawVal) {
    //This is a +-45 degree sensor
    if (rawVal < 0.5) {
        std::cerr << "App::transfer_function rawValue is too low" << std::endl;
        return -1;
    } else if (rawVal > 4.5) {
        std::cerr << "App::transfer_function rawValue is too high" << std::endl;
        return -1;
    }
    return (22.5*rawVal)-56.25;
}

void App::update() {
    UDOUBLE var = this->getData();
    std::cout << "App data: " << var << std::endl;
    highResTime callTime = std::chrono::system_clock::now();
    this->position = transfer_function(var);
    this->dataLog.addValue(callTime, this->position);
}

#ifdef TEST_MODE
void App::update(UDOUBLE rawVal) {
    highResTime callTime = std::chrono::system_clock::now();
    this->position = transfer_function(rawVal);
    this->dataLog.addValue(callTime, this->position);
}
#endif
