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

void Sensor::writeDataToFile(std::string filename){
    std::ofStream file;
    file.open(filename);
    typename std::map<highResTime, T>::const_iterator it;
    typename std::map<highResTime, T>::const_iterator endIt = this.dataLog.getEnd();

    for (it = this.dataLog.getStart(); it < endIt; it++){
        file << it.first << "," << it.second << "\n";
    }

    file.close();

}
