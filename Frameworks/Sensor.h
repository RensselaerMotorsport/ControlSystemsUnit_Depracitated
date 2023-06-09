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


    //We can either use a map of times and data as the storage medium
    //Or we could just store data and then have a large map with all the sensors at every time

};


#endif //RENNSMOTORSPORT_SENSOR_H
