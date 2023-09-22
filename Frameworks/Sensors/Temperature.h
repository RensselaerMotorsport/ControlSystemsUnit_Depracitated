/*
 * -----------------------------------------------------------------
 *   _______                                  _
 *  |__   __|                                | |
 *     | | ___ _ __ ___  _ __   ___ _ __ __ _| |_ _   _ _ __ ___
 *     | |/ _ \ '_ ` _ \| '_ \ / _ \ '__/ _` | __| | | | '__/ _ \
 *     | |  __/ | | | | | |_) |  __/ | | (_| | |_| |_| | | |  __/
 *     |_|\___|_| |_| |_| .__/ \___|_|  \__,_|\__|\__,_|_|  \___|
 *                      | |
 *                      |_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: This class is the controller/handler class for the various temperature sensors that will be used
 *
 *
 * Member Variables:
 *
 *
 * Member functions:
 *
 *
 */

#ifndef CONTROLSYSTEMSUNIT_TEMPERATURE_H
#define CONTROLSYSTEMSUNIT_TEMPERATURE_H
#include "../../Frameworks/AnalogSensor.h"

class Temperature : public AnalogSensor<float> {
public:
    Temperature(int port, int channel, int hZ): 
        AnalogSensor<float>("Temperature", DataLogger<float>(), port, channel, hZ)
            { temp = 0.0; number = 0; }

    float getCelsius();
    float getFahrenheit();

private:
    float transfer_function(float rawVal); //TODO: needs to be implemented

    //Member Variables:
    //Stored in Celsius:
    float temp;
    int number;
};


#endif //CONTROLSYSTEMSUNIT_TEMPERATURE_H
