//
// Created by harshk on 7/25/2023.
//
#include <vector>

//The vector should be of the form <least_recent_value, less_recent_value, most_recent_value, time_diff>

float acceleration(std::vector<float> f){
    if (points.size() != 4) {
        return NULL;
    }
    //This is the three-point midpoint formula for the 2nd derivative
    //TODO:figure out what the three-point endpoint formula for the 2nd derivative is
    return (f[0] - 2*f[1] + f[2])/(f[3]*f[3]);
}