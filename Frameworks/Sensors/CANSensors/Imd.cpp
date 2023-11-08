//
// Created by harshk on 9/29/2023.
//

#include "Imd.h"

void Imd::update(std::vector<float> var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->imd_status = imd_status_transfer_function(var[0]);
    this->running_flag = running_flag_transfer_function(var[1]);
    std::vector<bool> vec = std::vector<bool>(2);
    vec[0] = this->imd_status;
    vec[1] = this->running_flag;
    this->dataLog.addValue(callTime, vec);
}

bool Imd::imd_status_transfer_function(float x) {
    return x > 0.5; // TODO: Implement
}

bool Imd::running_flag_transfer_function(float x) {
    return x > 0.5; // TODO: Implement
}