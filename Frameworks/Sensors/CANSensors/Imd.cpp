//
// Created by harshk on 9/29/2023.
//

#include "Imd.h"

void Imd::update(float var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->imd_status = imd_status_transfer_function(var);
    this->running_flag = running_flag_transfer_function(var);
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

std::string Imd::toString(std::vector<bool> v){
    std::string os = "";
    for (int i = 0; i < v.size(); ++i) {
        if (v[i]){
            os += "1";
        } else {
            os += "0";
        }
        if (i != v.size() - 1) os += ",";
    }
    return os;
}