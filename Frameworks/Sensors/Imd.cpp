//
// Created by harshk on 9/29/2023.
//

#include "Imd.h"

void Imd::update(std::vector<bool> var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->imd_status = var[0];
    this->running_flag = var[1];
    std::vector<bool> vec = std::vector<bool>(2);
    vec[0] = this->imd_status;
    vec[1] = this->running_flag;
    this->dataLog.addValue(callTime, vec);
}