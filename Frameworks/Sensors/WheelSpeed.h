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

class WheelSpeed : public AnalogSensor<float, float>{
public:
    /*Constructors:*/
    WheelSpeed(int port, int channel, int hZ, float r, WHEEL_LOCATION w) :
        AnalogSensor<float>("WheelSpeed", DataLogger<float>(), port, channel, hZ) {
        speed = -1;
        radius = r;
        wheel_location = w;
    }

    float getSpeed(){ return speed; }
    float getRadius() { return radius; }
    WHEEL_LOCATION get_wheel_location(){ return wheel_location; }

    void update(float var) override;

private:
    //variables
    float speed;
    float radius;
    WHEEL_LOCATION wheel_location;

    //functions:
    float transfer_function(float rawVal);

};


#endif //RENNSMOTORSPORT_WHEELSPEED_H
