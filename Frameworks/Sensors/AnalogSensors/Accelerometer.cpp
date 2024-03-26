/*
 * -----------------------------------------------------------------------
 *                         _                               _
 *       /\               | |                             | |
 *      /  \   ___ ___ ___| | ___ _ __ ___  _ __ ___   ___| |_ ___ _ __
 *     / /\ \ / __/ __/ _ \ |/ _ \ '__/ _ \| '_ ` _ \ / _ \ __/ _ \ '__|
 *    / ____ \ (_| (_|  __/ |  __/ | | (_) | | | | | |  __/ ||  __/ |
 *   /_/    \_\___\___\___|_|\___|_|  \___/|_| |_| |_|\___|\__\___|_|
 *
 * -----------------------------------------------------------------------
 *
 */

#include <iostream>
#include <fstream>
#include "Accelerometer.h"

const float kOffsetVolts = 2.5; // 2.5 V at 0 g
const float kVoltsPerG = 0.440; // 440 mV/g

float Accelerometer::transfer_function(UDOUBLE rawVal){
    return (rawVal - kOffsetVolts) / kVoltsPerG;
}

void Accelerometer::update() {
    UDOUBLE var = this->getData();
    highResTime callTime = std::chrono::system_clock::now();
    this->value = transfer_function(var);
    this->dataLog.addValue(callTime, this->value);
}

#ifdef TEST_MODE
void Accelerometer::update(UDOUBLE rawVal) {
    highResTime callTime = std::chrono::system_clock::now();
    this->value = transfer_function(rawVal);
    this->dataLog.addValue(callTime, this->value);
}
#endif
