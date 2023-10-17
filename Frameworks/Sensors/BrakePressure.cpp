/*
 *
 *   ____            _          _____
 *  |  _ \          | |        |  __ \
 *  | |_) |_ __ __ _| | _____  | |__) | __ ___  ___ ___ _   _ _ __ ___
 *  |  _ <| '__/ _` | |/ / _ \ |  ___/ '__/ _ \/ __/ __| | | | '__/ _ \
 *  | |_) | | | (_| |   <  __/ | |   | | |  __/\__ \__ \ |_| | | |  __/
 *  |____/|_|  \__,_|_|\_\___| |_|   |_|  \___||___/___/\__,_|_|  \___|
 *
 *
 */

#include "BrakePressure.h"
float BrakePressure::transfer_function(float rawVal){
    return rawVal; //TODO: implement
}
float BrakePressure::get_pressure(){ return pressure; }

void BrakePressure::update(float var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->pressure = transfer_function(var);
    this->dataLog.addValue(callTime, this->pressure);
}
