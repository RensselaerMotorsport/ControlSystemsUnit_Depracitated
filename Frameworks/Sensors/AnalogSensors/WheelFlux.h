/*
 * __          ___               _   ______ _
 * \ \        / / |             | | |  ____| |
 *  \ \  /\  / /| |__   ___  ___| | | |__  | |_   ___  __
 *   \ \/  \/ / | '_ \ / _ \/ _ \ | |  __| | | | | \ \/ /
 *    \  /\  /  | | | |  __/  __/ | | |    | | |_| |>  <
 *     \/  \/   |_| |_|\___|\___|_| |_|    |_|\__,_/_/\_\
 *
 * Logs weather at any given point in time the flux value indicates that a hole has been seen
 * Used to calculate wheel speed
 */

#ifndef RENNSMOTORSPORT_WHEELflux_H
#define RENNSMOTORSPORT_WHEELflux_H

#include "../AnalogSensor.h"

enum WHEEL_LOCATION{ front_left, front_right, back_left, back_right };

class WheelFlux : public AnalogSensor<float> {
public:
    /*Constructors:*/
    WheelFlux(int channel, int hZ, float r, WHEEL_LOCATION w) :
        AnalogSensor<float>("WheelFlux", DataLogger<float>(), channel, hZ)
    {
        flux = -1;
        radius = r;
        wheel_location = w;
    }

    float getFlux(){ return flux; }
    float getRadius() { return radius; }
    WHEEL_LOCATION get_wheel_location(){ return wheel_location; }

    void update(UDOUBLE var) override;

private:
    //variables
    bool flux; //This stores whether a hole was seen in the wheel.
               //There will be a wrapper which will calculate the speed.
    float radius;
    WHEEL_LOCATION wheel_location;

    //functions:
    float transfer_function(UDOUBLE rawVal);

};


#endif //RENNSMOTORSPORT_WHEELflux_H
