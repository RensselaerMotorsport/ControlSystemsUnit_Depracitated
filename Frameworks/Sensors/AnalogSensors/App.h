//
// Created by harshk on 11/3/2023.
//

#ifndef CONTROLSYSTEMSUNIT_APP_H
#define CONTROLSYSTEMSUNIT_APP_H


class App {
public:
    App(int channel, int hZ)
            : AnalogSensor<float>("APP", DataLogger<float>(), channel, hZ)
    { position = -1; }

    float get_position(){ return position; }

    void update(UDOUBLE var) override;

private:
    //variables
    float position;


    //functions:
    float transfer_function(UDOUBLE rawVal);
};


#endif //CONTROLSYSTEMSUNIT_APP_H
