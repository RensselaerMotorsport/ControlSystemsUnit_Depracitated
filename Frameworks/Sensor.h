//
// Created by kyle on 6/9/23.
//

#ifndef RENNSMOTORSPORT_SENSOR_H
#define RENNSMOTORSPORT_SENSOR_H
#include <string>

class Sensor {
public:
    /*
    bool operator==(Sensor s);
    bool operator>(Sensor s);
    bool operator<(Sensor s);

    //clears stored data
    void clear();
    */
private:
    //member variables:

    //Contains name of the input sensor
    std::string sensorName;

    //Sample rate of the sensor in Hz
    int sampleRate;




};


#endif //RENNSMOTORSPORT_SENSOR_H
