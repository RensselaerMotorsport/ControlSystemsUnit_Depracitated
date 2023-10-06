//
// Created by harshk on 9/29/2023.
//

#ifndef CONTROLSYSTEMSUNIT_IMD_H
#define CONTROLSYSTEMSUNIT_IMD_H

#include "../CANSensor.h"
#include <vector>

class Imd : public CANSensor<std::vector<bool>>{
public:
    Imd(int frequency, int id, int port)
            : CANSensor<std::vector<bool>>("Imd", DataLogger<std::vector<bool>>(), port, frequency, id)
    { imd_status = false; running_flag = false; }

    int get_status() { return imd_status; }
    int get_running_flag() { return running_flag; }
    int reset_running_flag() { running_flag = true; } //TODO: ask ammar if reset means true or false

    //TODO: figure out what input type is
    void update(std::vector<bool> var) override;

private:
    bool imd_status;
    bool running_flag;
    // Stored in datalogger as [imd_status, running_flag]

};

// Overloading << operator for std::vector<bool>
inline std::ostream& operator<<(std::ostream& os, const std::vector<bool>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i]){
            os << 1;
        } else {
            os << 0;
        }
        if (i != vec.size() - 1) os << ", ";
    }
    return os;
}

#endif //CONTROLSYSTEMSUNIT_IMD_H
