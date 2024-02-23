/*
 * -----------------------------------------------------------------
 *
 *   __  __       _                _____            _             _ _
 *  |  \/  |     | |              / ____|          | |           | | |
 *  | \  / | ___ | |_ ___  _ __  | |     ___  _ __ | |_ _ __ ___ | | | ___ _ __
 *  | |\/| |/ _ \| __/ _ \| '__| | |    / _ \| '_ \| __| '__/ _ \| | |/ _ \ '__|
 *  | |  | | (_) | || (_) | |    | |___| (_) | | | | |_| | | (_) | | |  __/ |
 *  |_|  |_|\___/ \__\___/|_|     \_____\___/|_| |_|\__|_|  \___/|_|_|\___|_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: This class acts as a controller for all motor functions, including all sensors that will be used
 *                     This class will dictate how other classes interact with each other
 *
 * Member Variables:
 *
 *
 * Member functions:
 *
 *
 */

#ifndef CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H
#define CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H

#include "../AnalogSensors/App.h"
#include "Esc.h"

enum SYSTEM_STATE{ off , charging , chargedDisabled , chargedEnabled };
enum MOTOR_STATE{ forward , reverse , disabled };

class MotorController {
public:
    MotorController(Esc* e, App* a);

    float getPedalPosition();
    float getMotorTemp();
private:
    Esc* esc;
    App* app;

    SYSTEM_STATE system_state = off;
    MOTOR_STATE motor_state = disabled;
};


#endif //CONTROLSYSTEMSUNIT_MOTORCONTROLLER_H
