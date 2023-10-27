//
// Created by harshk on 9/29/2023.
//

#include "SteeringColumn.h"

void SteeringColumn::update(UDOUBLE var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->rotation_angle = transfer_function(var);
    this->dataLog.addValue(callTime, this->rotation_angle);
}