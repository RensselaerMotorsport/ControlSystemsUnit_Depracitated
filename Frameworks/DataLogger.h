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
#include <chrono>
#include <map>
#include <iterator>
#include <iomanip>
#include <iostream>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> highResTime;

std::string time_point_to_string(const std::chrono::system_clock::time_point& tp) {
    auto ttime_t = std::chrono::system_clock::to_time_t(tp);
    auto tm = *std::localtime(&ttime_t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");

    auto duration = tp.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 1000;
    oss << '.' << std::setfill('0') << std::setw(3) << millis;

    oss << " " << std::put_time(&tm, "%Y-%m-%d");

    return oss.str();
}

template<typename T>
class DataLogger {
public:
    DataLogger(){ lastTime = std::chrono::system_clock::now(); }
    T getDataAtTime(highResTime time) const { // TODO: Maybe put back in .cpp at some point maybe???
        auto it = dataMap.find(time);
        if (it != dataMap.end()) {
            return it->second;
        }
        std::cout << "DataLogger: No data at time " << time_point_to_string(time) << std::endl;
        return T{}; // returning defualt-construted value of T
    }
    bool addValue(highResTime time, T value);
    typename std::map<highResTime, T>::const_iterator getMap();
private:
    //member autoiables
    std::map<highResTime, T> dataMap;

    //Used to ensure that it does not accidentally edit old times
    highResTime lastTime;
};

#endif //RENNSMOTORSPORT_DATALOGGER_H
