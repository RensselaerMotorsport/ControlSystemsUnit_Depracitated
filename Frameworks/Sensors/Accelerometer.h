//
// Created by kyle on 7/11/23.
//

#ifndef RENNSMOTORSPORT_ACCELEROMETER_H
#define RENNSMOTORSPORT_ACCELEROMETER_H

#include "../AnalogSensor.h"

class Accelerometer : public AnalogSensor<float>{
public:
    //Constructors
    Accelerometer() : AnalogSensor<float>("Accelerometer") { raw_signal_x = -1; raw_signal_y = -1; raw_signal_z = -1; }
    //Member Functions
    double get_x(){ return transfer_function_x(); }
    double get_y(){ return transfer_function_y(); }
    double get_z(){ return transfer_function_z(); }
private:
    //Member Variables
    float raw_signal_x;
    float raw_signal_y;
    float raw_signal_z;

    //Helper functions:

    //These take the raw signal and return the actual value:
    //To be implemented later
    float transfer_function_x();
    float transfer_function_y();
    float transfer_function_z();
};


#endif //RENNSMOTORSPORT_ACCELEROMETER_H
