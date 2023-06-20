/*
 * -----------------------------------------------------------------
 *  _____        _          _
 * |  __ \      | |        | |
 * | |  | | __ _| |_ __ _  | |     ___   __ _  __ _  ___ _ __
 * | |  | |/ _` | __/ _` | | |    / _ \ / _` |/ _` |/ _ \ '__|
 * | |__| | (_| | || (_| | | |___| (_) | (_| | (_| |  __/ |
 * |_____/ \__,_|\__\__,_| |______\___/ \__, |\__, |\___|_|
 *                                       __/ | __/ |
 *                                      |___/ |___/
 *
 * ------------------------------------------------------------------
 *
 * Class Function: The function of this class is to act as a high level class for lower level classes (sensor specific) to extend
 *                      This class will allow the various sensors to log the data that they receive for later retrieval
 *                          *** EACH SENSOR OBJECT HAS EXACTLY ONE DATA LOGGER OBJECT ***
 *
 * Member Variables:
 * dataMap - This variable is a map with a key of type time to log certain input values at specific times
 *              this function uses a generic type as the value, this is done to allow various sensors to all use this high level class
 *
 * Member functions:
 * getDataAtTime - This function returns the data value at the specified time by (time_t time)
 *
 */

#ifndef RENNSMOTORSPORT_DATALOGGER_H
#define RENNSMOTORSPORT_DATALOGGER_H

#include <ctime>
#include <map>

template<typename T>
class DataLogger {
public:
    DataLogger(){ lastTime = std::time_t(0); }
    T getDataAtTime(std::time_t time);
    bool addValue(std::time_t time, T value);
    void getMap(const std::map<std::time_t, T> &map);
private:
    //member variables
    std::map<std::time_t, T> dataMap;

    //Used to ensure that it does not accidentally edit old times
    std::time_t lastTime;
};



#endif //RENNSMOTORSPORT_DATALOGGER_H
