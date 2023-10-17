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
 * Member function implementation
 * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
 */
#include "Sensor.h"
#include <fstream>

template <typename T>
void Sensor<T>::writeDataToFile(std::string filename){
    std::ofstream file;
    file.open(filename);
    typename std::map<highResTime, T>::const_iterator it;
    typename std::map<highResTime, T>::const_iterator endIt = dataLog.end();

    for (it = dataLog.begin(); it != endIt; ++it){
        file << it->first << "," << it->second << "\n";
    }

    file.close();
}
