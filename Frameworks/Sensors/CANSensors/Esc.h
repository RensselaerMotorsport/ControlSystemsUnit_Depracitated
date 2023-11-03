//
// Created by harshk on 11/3/2023.
//

#ifndef CONTROLSYSTEMSUNIT_ESC_H
#define CONTROLSYSTEMSUNIT_ESC_H

#include "../CANSensor.h"
#include <vector>

class Esc : public CANSensor<std::vector<float>, int/*will be 11 bits*/> {
public:
    Esc(int hz, int id)
            : CANSensor<std::vector<float>, int>("Imd", DataLogger<std::vector<float>>(), hz, id)
    { temp = 0.0; motor_revolutions = 0.0; }

    float get_temp() { return temp; }
    float get_motor_revolutions() { return motor_revolutions; }

    void update(int var) override;

private:
    float temp_transfer_function(int x);
    float motor_revolutions_transfer_function(int x);

    float temp;
    float motor_revolutions;
    // Stored in datalogger as [temp, motor_revolutions]

};


#endif //CONTROLSYSTEMSUNIT_ESC_H
