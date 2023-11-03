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
 * Member function implementation
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
 */
#include "MotorController.h"
#include "Temperature.h"

float MotorController::getSensorValue(){
    //function not implemented properly
    /*plans??
     *  call function to get sensor value
     *  translate it??
     *  return an encoded value
     *
     */
    return torque;
}

MotorController::MotorController(float to, float te){
    torque = to;
    temp = 0.0;
}

MotorController::MotorController() {
    torque = 0.0;
    temp = 0.0;
}
