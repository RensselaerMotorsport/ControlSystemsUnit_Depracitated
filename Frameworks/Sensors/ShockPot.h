//
// Created by harshk on 7/21/2023.
//

#ifndef CONTROLSYSTEMSUNIT_SHOCKPOT_H
#define CONTROLSYSTEMSUNIT_SHOCKPOT_H

#include "WheelFlux.h"

class ShockPot : public AnalogSensor<float>{
public:
    ShockPot(int channel, int hZ, WHEEL_LOCATION w)
        : AnalogSensor<float>("ShockPot", DataLogger<float>(), channel, hZ)
        { distance = -1; shock_location = w; }

    float get_distance(){ return distance; }
    float get_acceleration();
    WHEEL_LOCATION get_wheel_location(){ return shock_location; }

    void update(UDOUBLE var) override;

private:
    //variables
    float distance;
    WHEEL_LOCATION shock_location; //front left, front right, back left, back right


    //functions:
    float transfer_function(UDOUBLE rawVal);
};


#endif //CONTROLSYSTEMSUNIT_SHOCKPOT_H
