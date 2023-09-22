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

// template<typename T>
// T DataLogger<T>::getDataAtTime(highResTime time) const {
//     auto it = dataMap.find(time);
//     if (it != dataMap.end()) {
//         return it->second;
//     }
//     std::cout << "Error in DataLogger: No data at time " << time_point_to_string(time) << std::endl;
//     return T{}; // returning default-constructed value of T
// }

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
typename std::map<highResTime, T>::const_iterator DataLogger<T>::getMap() {
    typename std::map<highResTime, T>::const_iterator it = dataMap.begin();

    return it;
}