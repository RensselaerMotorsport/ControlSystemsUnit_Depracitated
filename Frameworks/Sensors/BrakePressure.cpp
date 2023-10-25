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

const float kOffsetVoltage = 0.201; // Volts
const float kVoltsPerPSIA = 0.03738;
const float kLowOutputSaturation = 0.35;  // Output saturation for undersupplied sensor*
const float kHighOutputSaturation = 4.65; // Output saturation for oversupplied sensor*
// *These are very conservative saturation values; if we expect to regularly approach these, more thought needs to be put into these

float BrakePressure::transfer_function(float rawVal)
{
    if (rawVal < kLowOutputSaturation)
    {
        std::cerr << "BrakePressure::transfer_function rawVal is too low" << std::endl;
        return 0;
    }
    else if (rawVal > kHighOutputSaturation)
    {
        std::cerr << "BrakePressure::transfer_function rawVal is too high" << std::endl;
        return 115;
    }
    else
        return ((rawVal - kOffsetVoltage) / kVoltsPerPSIA);
    // TODO if we ever read supply voltage, change the "5/kSupplyVoltage"
    // in the above equation. Otherwise, remove it as it is dividing by 1.
}
float BrakePressure::get_pressure() { return pressure; }

void BrakePressure::update(float var)
{
    highResTime callTime = std::chrono::system_clock::now();
    this->pressure = transfer_function(var);
    this->dataLog.addValue(callTime, this->pressure);
}
