/*
 *  __          ___               _    _____                     _
 *  \ \        / / |             | |  / ____|                   | |
 *   \ \  /\  / /| |__   ___  ___| | | (___  _ __   ___  ___  __| |
 *    \ \/  \/ / | '_ \ / _ \/ _ \ |  \___ \| '_ \ / _ \/ _ \/ _` |
 *     \  /\  /  | | | |  __/  __/ |  ____) | |_) |  __/  __/ (_| |
 *      \/  \/   |_| |_|\___|\___|_| |_____/| .__/ \___|\___|\__,_|
 *                                          | |
 *                                          |_|
 *
 * Wrapper class for WheelFlux
 * Calculates wheel speed based on number of times a hole was seen (boolean true) per second
 */

#ifndef CONTROLSYSTEMSUNIT_WHEELSPEED_H
#define CONTROLSYSTEMSUNIT_WHEELSPEED_H

#include "WheelFlux.h"

class WheelSpeed {
public:
    WheelSpeed(WheelFlux f) : flux(f), speedLog(DataLogger<float>()) {}

private:
    float translate_flux_to_speed();

    WheelFlux flux;
    DataLogger<float> speedLog;
};


#endif //CONTROLSYSTEMSUNIT_WHEELSPEED_H
