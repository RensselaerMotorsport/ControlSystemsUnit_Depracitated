
/*
 * -----------------------------------------------------------------
 *    _____
 *   / ____|
 *  | (___   ___ _ __  ___  ___  _ __
 *   \___ \ / _ \ '_ \/ __|/ _ \| '__|
 *   ____) |  __/ | | \__ \ (_) | |
 *  |_____/ \___|_| |_|___/\___/|_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: The function of this class is to act as a high level class for lower level classes to extend
 *                      This class will allow the various sensors to work and communicate with the motor controller class
 *                          This class will dictate how sensors behave and fetch/store data that is received from the physical sensors
 *
 *
 * Member Variables:
 * sensorName - name of the sensor to denote its function
 * sample rate - an integer value representing the sample rate of the sensor in Hz
 *
 * Member functions:
 * clear - clears the data of this sensor
 *
 */

#ifndef RENNSMOTORSPORT_SENSOR_H
#define RENNSMOTORSPORT_SENSOR_H
#include <string>
#include "DataLogger.h"
#include "IO.h"

template<typename T>
class Sensor: public IO {
public:
    Sensor(): IO() { sensorName = "UNNAMED"; dataLog = DataLogger<T>(); port = 0; }
    Sensor(std::string name): IO() { sensorName = name; dataLog = DataLogger<T>(); port = 0; }
    Sensor(std::string name, DataLogger<T> log, int p): IO() { sensorName = name; dataLog = log; port = p; }
    /*
    //clears stored data
    void clear();
    */

   const DataLogger<T>& getDataLog() const { return dataLog; }
   std::string getSensorName() { return sensorName; }

   //Setter
   void update(T var); //This will be implemented in each individual sensor

private:
    //member variables:
    //New values should be stored in the dataLog when they are gotten
    DataLogger<T> dataLog;

    //Contains name of the input sensor
    std::string sensorName;

    int port;
};

float timeToFloat(highResTime){
    return 1.0;
}

#endif //RENNSMOTORSPORT_SENSOR_H
