/*
 *  __          ___               _    _____                     _
 *  \ \        / / |             | |  / ____|                   | |
 *   \ \  /\  / /| |__   ___  ___| | | (___  _ __   ___  ___  __| |
 *    \ \/  \/ / | '_ \ / _ \/ _ \ |  \___ \| '_ \ / _ \/ _ \/ _` |
 *     \  /\  /  | | | |  __/  __/ |  ____) | |_) |  __/  __/ (_| |
 *      \/  \/   |_| |_|\___|\___|_| |_____/| .__/ \___|\___|\__,_|
 *                                          | |
 *                                          |_|
 */

#include "WheelFlux.h"

float WheelFlux::transfer_function(UDOUBLE rawVal) {
    return 0.0f; //TODO: implement
}

void WheelFlux::update(UDOUBLE var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->flux = transfer_function(var);
    this->dataLog.addValue(callTime, this->flux);
}