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
 * Member function implementation
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
 */

#include "DataLogger.h"

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
T DataLogger<T>::getDataAtTime(highResTime time) const {
    auto it = dataMap.find(time);
    if (it != dataMap.end()) {
        return it->second;
    }
    std::cout << "Error in DataLogger: No data at time " << time_point_to_string(time) << std::endl;
    return T{}; // returning default-constructed value of T
}

template<typename T>
bool DataLogger<T>::addValue(highResTime time, T value){
    if (time > lastTime) {
        dataMap[time] = value;
        lastTime = time;
        return true;
    }
    return false;
}

template<typename T>
typename std::map<highResTime, T>::const_iterator DataLogger<T>::getStart() {
    typename std::map<highResTime, T>::const_iterator it = dataMap.begin();

    return it;
}

template<typename T>
typename std::map<highResTime, T>::const_iterator DataLogger<T>::getEnd() {
    typename std::map<highResTime, T>::const_iterator it = dataMap.end();

    return it;
}