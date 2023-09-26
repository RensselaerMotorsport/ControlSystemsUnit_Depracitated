//
// Created by kyle on 7/11/23.
//

#include <iostream>
#include <fstream>
#include "Accelerometer.h"

//Implementation TBD:
    float Accelerometer::transfer_function_x(float rawVal){
        return rawVal;
    }
    float Accelerometer::transfer_function_y(float rawVal){
        return rawVal;
    }
    float Accelerometer::transfer_function_z(float rawVal){
        return rawVal;
    }

void Accelerometer::update(std::vector<double> var) {
    highResTime callTime = std::chrono::system_clock::now();
    this->x = transfer_function_x(var[0]);
    this->y = transfer_function_y(var[1]);
    this->z = transfer_function_y(var[2]);
    this->dataLog.addValue(callTime, std::vector<float>(){x, y, z})
}

void Accelerometer::writeDataToFile(std::string filename) {
    std::ofStream file;
    file.open(filename);
    //const iterator it = this.dataLog.getMap()
}