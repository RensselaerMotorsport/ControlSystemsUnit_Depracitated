/*
 *
 *
 *
 * Wrapper class for WheelFlux
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
