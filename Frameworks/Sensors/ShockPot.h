//
// Created by harshk on 7/21/2023.
//

#ifndef CONTROLSYSTEMSUNIT_SHOCKPOT_H
#define CONTROLSYSTEMSUNIT_SHOCKPOT_H

#include "WheelSpeed.h"

class ShockPot : AnalogSensor<float>{
public:
    ShockPot(int port, int channel, int hZ, WHEEL_LOCATION w) : AnalogSensor<float>("ShockPot", DataLogger<float>(), port, channel, hZ) { raw_signal = -1; distance = -1; shock_location = w; }

    float get_distance(){ return distance; }
    float get_acceleration();
    WHEEL_LOCATION get_wheel_location(){ return shock_location; }

    //TODO: Implement update()
private:
    //variables
    float raw_signal;
    float distance;
    WHEEL_LOCATION shock_location; //front left, front right, back left, back right


    //functions:
    void transfer_function(){

    }
};


#endif //CONTROLSYSTEMSUNIT_SHOCKPOT_H
