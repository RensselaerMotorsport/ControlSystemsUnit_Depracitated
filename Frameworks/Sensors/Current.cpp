#include "../AnalogSensor.h"
#include "Current.h"
#include "../DataLogger.h"

#include <iostream>
#include <ctime>
#include <chrono>


double Current::transfer_function(double v_out, double v_in){
    double curr;
    if(this->channel == 1){
        curr = ((5.0/v_in) * v_out - 2.5) * (1.0/26.7);
        curr = (-75 <= curr) && (curr <= 75)  ? curr : NULL;
    } else if(this->channel == 2){
        curr = ((5.0/v_in) * v_out - 2.5) * (1.0/4);
        curr = (-500 <= curr) && (curr <= 500)  ? curr : NULL;
    } else {
        curr = NULL;
    }
    if(!curr){std::cerr << "Error reading current" << std::endl;}
}

void Current::update(double v_out, double v_in) {
    highResTime callTime = std::chrono::system_clock::now();
    this->current = transfer_function(v_out, v_in);
    this->dataLog.addValue(callTime, this->current);
}