/*
 *  _____ __  __ _____
 * |_   _|  \/  |  __ \
 *   | | | \  / | |  | |
 *   | | | |\/| | |  | |
 *  _| |_| |  | | |__| |
 * |_____|_|  |_|_____/
 *
 * Ignition Monitor Detector
 * Monitors whether the car is an electric chair
 */

#ifndef CONTROLSYSTEMSUNIT_IMD_H
#define CONTROLSYSTEMSUNIT_IMD_H

#include "../CANSensor.h"
#include <vector>

class Imd : public CANSensor<std::vector<bool>, float> {
public:
    Imd(int hz, int id):
        // NOTE: Changed std::vector<float> to float
        CANSensor<std::vector<bool>, float>("Imd", DataLogger<std::vector<bool>>(), hz, id)
    {
        imd_status = false;
        running_flag = false;
    }

    bool get_status() { return imd_status; }
    bool get_running_flag() { return running_flag; }
    void reset_running_flag() { running_flag = true; } //TODO: ask ammar if reset means true or false

    void update() override;

private:

    std::string toString(std::vector<bool> v) override;

    bool imd_status_transfer_function(float x); // TODO: Implement
    bool running_flag_transfer_function(float x); // TODO: Implement

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
        if (i != vec.size() - 1) os << ",";
    }
    return os;
}

#endif //CONTROLSYSTEMSUNIT_IMD_H
