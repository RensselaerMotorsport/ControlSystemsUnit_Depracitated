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

#include "WheelSpeed.h"

float WheelSpeed::transfer_function(float rawVal) {
    return rawVal; //TODO: implement
}

void WheelSpeed::update(float var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->speed = transfer_function(var);
    this->dataLog.addValue(callTime, this->speed);
}