//
// Created by harshk on 7/21/2023.
//

#include "ShockPot.h"
#include "AccelCalc.cpp"

float ShockPot::get_acceleration(){
    std::map<highResTime, float>::const_iterator it = dataLog.getEnd();
    std::vector<float> points;
    it--;
    highResTime pre = it->first;
    points.push_back(it->second);
    it--;
    highResTime post = it->first;
    points.push_back(it->second);
    it--;
    points.push_back(it->second);
    points.push_back((pre - post).count()); //The time diff
    return acceleration(points);
}

float ShockPot::transfer_function(UDOUBLE rawVal) {
    //TODO: this will need to be updated to work with UDOUBLEs
    if (rawVal < 15) {
        return -1;
        std::cerr << "ShockPot::transfer_function rawValue is too low" << std::endl;
    } else if (rawVal > 135) {
        return -1;
        std::cerr << "ShockPot::transfer_function rawValue is too high" << std::endl;
    }
    return 2.71965*(pow(rawVal,0.837683)) - 16.2622;
}

void ShockPot::update() {
    UDOUBLE var = this->getData();
    highResTime callTime = std::chrono::system_clock::now();
    this->distance = transfer_function(var);
    this->dataLog.addValue(callTime, this->distance);
}

#ifdef TEST_MODE
void ShockPot::update(UDOUBLE rawVal) {
    highResTime callTime = std::chrono::system_clock::now();
    this->distance = transfer_function(rawVal);
    this->dataLog.addValue(callTime, this->distance);
}
#endif
