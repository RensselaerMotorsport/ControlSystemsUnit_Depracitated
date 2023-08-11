//
// Created by harshk on 7/25/2023.
//
#include <vector>

//The vector should be of the form <time_diff, least_recent_value, less_recent_value, most_recent_value>
float threePointEndPointDeriv(const std::vector<float>& points){
    if (points.size() < 4) {
        std::cerr << "invalid size vector" << std::endl;
        return NULL;
    }
    int s = points.size()
    return (3*points[s-1]-4*points[s-2]+points[s-3])/(2*points[0])
}

float acceleration(std::vector<float> points){
    if (points.size() < 6) {
        return NULL;
    }
    //array of points and first derivatives
    std::vector<float> thing;
    thing.push_back(points[0]);
    for (int i = 0; i < 3; i++) {
        thing.push_back(threePointEndPointDeriv(points));
        points.pop_back();
    }
    assert(thing.size() == 4);
    return threePointEndPointDeriv(thing);
}

//It is assumed that functions are stored in the form <a0, a1, a2, a3> = a0 + a1*x + a2*x^2 + a3*x^3
/*
std::vector<float> interpoalte(std::vector<std::pair<float, float>> points){

}

std::vector<float> derive(std::vector<float> function){

}

float evaluate(std::vector<float> function){

}
*/