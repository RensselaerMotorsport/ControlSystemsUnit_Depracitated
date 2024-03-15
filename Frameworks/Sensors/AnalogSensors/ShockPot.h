/*
 *   _____ _                _    _____      _
 *  / ____| |              | |  |  __ \    | |
 * | (___ | |__   ___   ___| | _| |__) |__ | |_
 *  \___ \| '_ \ / _ \ / __| |/ /  ___/ _ \| __|
 *  ____) | | | | (_) | (__|   <| |  | (_) | |_
 * |_____/|_| |_|\___/ \___|_|\_\_|   \___/ \__|
 *
 * Measures the position of the shock on a given wheel
 * Acceleration can be estimated by using the previous 3 position values (function in AccelCalc.cpp)
 */

#ifndef CONTROLSYSTEMSUNIT_SHOCKPOT_H
#define CONTROLSYSTEMSUNIT_SHOCKPOT_H

#include "WheelFlux.h"

class ShockPot : public AnalogSensor<float>{
public:
    ShockPot(int channel, int hZ, int muxChannel , WHEEL_LOCATION w)
        : AnalogSensor<float>("ShockPot", DataLogger<float>(), channel, hZ, muxChannel)
        { distance = -1; shock_location = w; }

    float get_distance(){ return distance; }
    float get_acceleration();
    WHEEL_LOCATION get_wheel_location(){ return shock_location; }

    void update() override;

private:
    #ifdef TEST_MODE
    UDOUBLE getData() override;
    #endif

    //variables
    float distance;
    WHEEL_LOCATION shock_location; //front left, front right, back left, back right


    //functions:
    float transfer_function(UDOUBLE rawVal);
    std::string toString(float v) override { return std::to_string(v); }
};


#endif //CONTROLSYSTEMSUNIT_SHOCKPOT_H
