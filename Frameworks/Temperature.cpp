//
// Created by harshk on 6/13/2023.
//

#include "Temperature.h"
float Temperature::getCelsius(){
    return temp;
}
float Temperature::getFahrenheit(){
    return temp * (9/5) + 32;
}