#ifndef RENNSMOTORSPORT_CURRENT_H
#define RENNSMOTORSPORT_CURRENT_H

#include "../AnalogSensor.h"


class Current : public AnalogSensor<double>{
public:
    //Constructors
    Current() : AnalogSensor<double>("Current", DataLogger<double>(), -1, -1, -1) {}
    Current(int port, int channel, int hZ) : AnalogSensor<double>("Current", DataLogger<double>(), port, channel, hZ){}

    //function to find current I_p using member variables
    double transfer_function(double v_out, double v_in);

    //update function
    void update(double v_out, double v_in);

    //acessors
    float getCurrent() {return current;}
private:
    //member variables
    double current;
};


#endif