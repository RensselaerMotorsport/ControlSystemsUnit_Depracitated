//
// Created by kyle on 6/9/23.
//

#ifndef RENNSMOTORSPORT_DATALOGGER_H
#define RENNSMOTORSPORT_DATALOGGER_H

#include <ctime>
#include <map>

template<typename T>
class DataLogger {
public:
    T getDataAtTime(std::time_t time);
private:
    //member variables
    std::map<std::time_t, T> dataMap;
};



#endif //RENNSMOTORSPORT_DATALOGGER_H
