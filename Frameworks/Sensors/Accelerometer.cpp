//
// Created by kyle on 7/11/23.
//

#include <iostream>
#include <fstream>
#include "Accelerometer.h"

const float kOffsetVolts = 2.5; // 2.5 V at 0 g
const float kVoltsPerG = 0.440; // 440 mV/g

float Accelerometer::transfer_function_x(float rawVal){
    return (rawVal - kOffsetVolts) / kVoltsPerG;
}
float Accelerometer::transfer_function_y(float rawVal){
    return (rawVal - kOffsetVolts) / kVoltsPerG;
}
float Accelerometer::transfer_function_z(float rawVal){
    return (rawVal - kOffsetVolts) / kVoltsPerG;
}

void Accelerometer::update(std::vector<float> var) {
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