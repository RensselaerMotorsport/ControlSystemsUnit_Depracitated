//
// Created by harshk on 7/21/2023.
//

#include "ShockPot.h"
#include "./AccelCalc.cpp"

float ShockPot::get_acceleration(){
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