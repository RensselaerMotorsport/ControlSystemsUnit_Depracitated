//
// Created by harshk on 7/21/2023.
//

#include "ShockPot.h"
#include "./AccelCalc.cpp"

float ShockPot::get_acceleration(){
    //TODO: fix this mess
    std::Map<highResTime, float>::Iterator it = dataLog.end();
    std::vector<std::pair<float, float>> points;
    it--;
    highResTime pre = it.first;
    float firstVal = it.second;
    it--;
    points.push_back((pre - it.first).count());
    points.pudh_back(firstVal);
    for (int i = 0; i < 4; i ++){
        points.push_back(it.second));
        it--;
    }
    return acceleration(points);
}

float ShockPot::transfer_function(float rawVal) {
    if (rawVal < 15) {
        return -1;
        std::err << "ShockPot::transfer_function rawValue is too low" << std::endl;
    } else if (rawVal > 135) {
        return -1;
        std::err << "ShockPot::transfer_function rawValue is too high" << std::endl;
    }
    return 2.71965*(pow(rawVal,0.837683)) - 16.2622;
}

void ShockPot::update(float var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->distance = transfer_function(var);
    this->dataLog.addValue(callTime, this->distance);
}
