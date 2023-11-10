//
// Created by harshk on 11/3/2023.
//

#include "Esc.h"

void Esc::update(int var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->temp = temp_transfer_function(int);
    this->motor_revolutions = motor_revolutions_transfer_function(int);
    std::vector<float> vec = std::vector<float>(2);
    vec[0] = this->temp;
    vec[1] = this->motor_revolutions;
    this->dataLog.addValue(callTime, vec);
}

float Esc::temp_transfer_function(int x){
    return x + 0.0;
}
float Esc::motor_revolutions_transfer_function(int x){
    return x + 0.0
}

std::string Esc::toString(std::vector<float> v){
    std::string os = "";
    for (int i = 0; i < v.size(); ++i) {
        os += v[i];
        if (i != vec.size() - 1) os += ",";
    }
    return os;
}