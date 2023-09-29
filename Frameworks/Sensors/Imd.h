//
// Created by harshk on 9/29/2023.
//

#ifndef CONTROLSYSTEMSUNIT_IMD_H
#define CONTROLSYSTEMSUNIT_IMD_H

#include "./CANSensor.h"

class Imd : CANSensor<bool>{
public:
    Imd(int frequency, int id)
            : CANSensor<bool>("Imd", DataLogger<bool>(), frequency, id)
    { imd_status = false; running_flag = false; }

    //TODO: ask Ammar about implementation
    int get_status();
    int get_running_flag();
    int reset_running_flag();

private:
    bool imd_status;
    bool running_flag;

};


#endif //CONTROLSYSTEMSUNIT_IMD_H
