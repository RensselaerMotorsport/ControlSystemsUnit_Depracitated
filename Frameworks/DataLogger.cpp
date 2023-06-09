//
// Created by kyle on 6/9/23.
//

#include "DataLogger.h"

template<typename T>
T DataLogger<T>::getDataAtTime(std::time_t time){
    return dataMap[time];
}