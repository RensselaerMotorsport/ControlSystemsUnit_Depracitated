/*
 *  __          ___               _    _____                     _
 *  \ \        / / |             | |  / ____|                   | |
 *   \ \  /\  / /| |__   ___  ___| | | (___  _ __   ___  ___  __| |
 *    \ \/  \/ / | '_ \ / _ \/ _ \ |  \___ \| '_ \ / _ \/ _ \/ _` |
 *     \  /\  /  | | | |  __/  __/ |  ____) | |_) |  __/  __/ (_| |
 *      \/  \/   |_| |_|\___|\___|_| |_____/| .__/ \___|\___|\__,_|
 *                                          | |
 *                                          |_|
 */

#ifndef RENNSMOTORSPORT_WHEELSPEED_H
#define RENNSMOTORSPORT_WHEELSPEED_H

#include "../AnalogSensor.h"

enum WHEEL_LOCATION{ front_left, front_right, back_left, back_right };

class WheelSpeed : AnalogSensor<float>{
public:
    /*Constructors:*/
    WheelSpeed() : AnalogSensor<float>() {raw_signal = -1; speed = -1; radius = -1; wheel_location = front_right; }

    float get_speed(){ return speed; }
    WHEEL_LOCATION get_wheel_location(){ return wheel_location; }
private:
    //variables
    float raw_signal;
    float speed;
    float radius;
    WHEEL_LOCATION wheel_location;

    //functions:
    void transfer_function();

};


#endif //RENNSMOTORSPORT_WHEELSPEED_H
