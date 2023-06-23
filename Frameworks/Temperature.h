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


class Temperature {
public:
    Temperature(float t){ temp = t; }
    float getCelsius();
    float getFahrenheit();
private:
    //Member Variables:

    //Stored in Celsius:
    float temp;
};


#endif //CONTROLSYSTEMSUNIT_TEMPERATURE_H
