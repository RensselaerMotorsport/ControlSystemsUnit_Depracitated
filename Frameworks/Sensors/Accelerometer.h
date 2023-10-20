//
// Created by kyle on 7/11/23.
//

#ifndef RENNSMOTORSPORT_ACCELEROMETER_H
#define RENNSMOTORSPORT_ACCELEROMETER_H

#include "../AnalogSensor.h"
#include <vector>

class Accelerometer : public AnalogSensor<std::vector<float>, std::vector<float>>{
public:
    //Constructors
    Accelerometer() : AnalogSensor<std::vector<float>, std::vector<float>>("Accelerometer",
        DataLogger<std::vector<float>>(), -1, -1, -1)
        { x = -1; y = -1; z = -1; }
    Accelerometer(int port, int channel, int hZ) :
        AnalogSensor<std::vector<float>, std::vector<float>>("Accelerometer",
        DataLogger<std::vector<float>>(), port, channel, hZ)
        { x = -1; y = -1; z = -1; }

    //Member Functions
    float get_x(){ return x; }
    float get_y(){ return y; }
    float get_z(){ return z; }

    void update(std::vector<float> var) override;

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
    float transfer_function_z(float rawVal); //TODO: these all need to be properly implemented
};

// Overloading << operator for std::vector<double>
inline std::ostream& operator<<(std::ostream& os, const std::vector<float>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    return os;
}

#endif //RENNSMOTORSPORT_ACCELEROMETER_H
