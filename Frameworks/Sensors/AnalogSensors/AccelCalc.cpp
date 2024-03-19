/*
 *                       _  _____      _
 *     /\               | |/ ____|    | |
 *    /  \   ___ ___ ___| | |     __ _| | ___
 *   / /\ \ / __/ __/ _ \ | |    / _` | |/ __|
 *  / ____ \ (_| (_|  __/ | |___| (_| | | (__
 * /_/    \_\___\___\___|_|\_____\__,_|_|\___|
 *
 * This file is used for approximating the second derivative of position values
 */
#include <vector>
#include <cmath>



//The vector should be of the form <least_recent_value, less_recent_value, most_recent_value, time_diff>

inline float acceleration(std::vector<float> f){
    if (f.size() != 4) {
        return std::nan("");
    }
    //This is the three-point midpoint formula for the 2nd derivative
    //TODO:figure out what the three-point endpoint formula for the 2nd derivative is
    return (f[0] - 2*f[1] + f[2])/(f[3]*f[3]);
}
