//
// Created by kyle on 7/11/23.
//

#include <iostream>
#include <fstream>
#include "Accelerometer.h"

//Implementation TBD:
    float Accelerometer::transfer_function_x(float rawVal){
        return rawVal;
    }
    float Accelerometer::transfer_function_y(float rawVal){
        return rawVal;
    }
    float Accelerometer::transfer_function_z(float rawVal){
        return rawVal;
    }


float Accelerometer::transfer_function(UDOUBLE rawVal){
    return (rawVal - kOffsetVolts) / kVoltsPerG;
}

void Accelerometer::update(UDOUBLE var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->x = transfer_function_x(var[0]);
    this->y = transfer_function_y(var[1]);
    this->z = transfer_function_y(var[2]);
    std::vector<float> vec = std::vector<float>(3);
    vec[0] = this->x;
    vec[1] = this->y;
    vec[2] = this->z;
    this->dataLog.addValue(callTime, vec);
}