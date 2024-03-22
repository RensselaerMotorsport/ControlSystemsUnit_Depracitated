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
#include "../AnalogSensor.h"

class Temperature : public AnalogSensor<float> {
public:
    Temperature(int channel, int hZ, int muxChannel):
        AnalogSensor<float>("Temperature", DataLogger<float>(), channel, hZ, muxChannel)
            { temp = 0.0; number = 0; }

    float getCelsius();
    float getFahrenheit();

    void update() override;

    #ifdef TEST_MODE
    void update(UDOUBLE rawVal) override;
    #endif
private:

    float transfer_function(UDOUBLE rawVal);
    std::string toString(float v) override { return std::to_string(v); }

    //Member Variables:
    //Stored in Celsius:
    float temp;
    int number;
};


#endif //CONTROLSYSTEMSUNIT_TEMPERATURE_H
