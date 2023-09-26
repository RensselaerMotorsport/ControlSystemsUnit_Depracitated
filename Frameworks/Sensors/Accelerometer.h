//
// Created by kyle on 7/11/23.
//

#ifndef RENNSMOTORSPORT_ACCELEROMETER_H
#define RENNSMOTORSPORT_ACCELEROMETER_H

#include "../AnalogSensor.h"

class Accelerometer : public AnalogSensor<std::vector<double>>{
public:
    //Constructors
    Accelerometer() : AnalogSensor<std::vector<double>>("Accelerometer",
        DataLogger<std::vector<double>>(), -1, -1, -1)
        { x = -1; y = -1; z = -1; }
    Accelerometer(int port, int channel, int hZ) :
        AnalogSensor<std::vector<double>>("Accelerometer",
        DataLogger<std::vector<double>>(), port, channel, hZ)
        { x = -1; y = -1; z = -1; }

    //Member Functions
    double get_x(){ return x; }
    double get_y(){ return y; }
    double get_z(){ return z; } //TODO: these all need to be properly implemented

private:
    //Member Variables
    float x;
    float y;
    float z;

    //Helper functions:

    //These take the raw signal and return the actual value:
    //To be implemented later
    float transfer_function_x(float rawVal);
    float transfer_function_y(float rawVal);
    float transfer_function_z(float rawVal);
};

// Overloading << operator for std::vector<double>
std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

#endif //RENNSMOTORSPORT_ACCELEROMETER_H
