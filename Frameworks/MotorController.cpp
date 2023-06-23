//
// Created by harshk on 6/13/2023.
//
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
#include "MotorController.h"
MotorController::MotorController(float to, float te){
    torque = te;
    temp = Temperature(te);
}
