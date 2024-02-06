/*
 *     /\
 *    /  \   _ __  _ __
 *   / /\ \ | '_ \| '_ \
 *  / ____ \| |_) | |_) |
 * /_/    \_\ .__/| .__/
 *          | |   | |
 *          |_|   |_|
 *
 * Absolute Pedal Position
 * The position of the accelerator pedal. Used to tell the MotorControllers how much current to draw
 */

#ifndef CONTROLSYSTEMSUNIT_APP_H
#define CONTROLSYSTEMSUNIT_APP_H

#include "../AnalogSensor.h"

class App {
public:
    App(int channel, int hZ, int muxChannel)
            : AnalogSensor<float>("APP", DataLogger<float>(), channel, hZ, muxChannel)
    { position = -1; }

    float get_position(){ return position; }

    void update() override;

private:
    //variables
    float position;


    //functions:
    float transfer_function(UDOUBLE rawVal);
    std::string toString(float v) override { return std::to_string(v); }
};


#endif //CONTROLSYSTEMSUNIT_APP_H
