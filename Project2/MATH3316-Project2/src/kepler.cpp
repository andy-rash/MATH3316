//
//  kepler.cpp
//  MATH3316-Project2
//
//  Created by andy on 10/16/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>

#include "newton.cpp"
#include "Vector.h"

double df(double angle, double ecc) {
    return ((ecc * std::cos(angle)) - 1.0);
}

double eccentricity(double a, double b) {
    return std::sqrt(1 - (std::pow(b, 2) / std::pow(a, 2)));
}

double f(double angle, double t, double ecc) {
    return ((ecc * std::sin(angle)) - angle - t);
}

double radial_pos(double angle, double a, double b) {
    return ( (a * b) / std::sqrt(std::pow((b * std::cos(angle)), 2) + std::pow((a * std::sin(angle)), 2)) );
}

int main(int argc, char* argv[]) {
    
    double a = 2.0;
    double b = 1.25;
    double ecc = eccentricity(a, b);
    std::size_t max_iter = 6;
    double tol = 1.e-5;
    
    auto results = PH::Vector(10000);
    auto t   = PH::Vector::linSpace(0, 10, 10000);
    auto x_t = PH::Vector(10000);
    auto y_t = PH::Vector(10000);
    
    double guess = 0.0;
    t.mapElements([&](double t, double idx) {
        
        Fcn _f = [&](double angle){ return f(angle, t, ecc); };
        Fcn _df = [&](double angle){ return df(angle, ecc); };
        
        double angle = newton(_f, _df, guess, max_iter, tol, false);
        guess = angle;
        results[idx] = angle;
        
        double _radial_pos = radial_pos(angle, a, b);
        x_t[idx] = _radial_pos * std::cos(angle);
        y_t[idx] = _radial_pos * std::sin(angle);
        
    });
    
    std::string path = "../res/part2/";
    t.saveTo(path + "t.txt");
    x_t.saveTo(path + "x_t.txt");
    y_t.saveTo(path + "y_t.txt");
    
    return 0;
    
}
