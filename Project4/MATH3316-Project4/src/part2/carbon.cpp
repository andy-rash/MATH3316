//
//  carbon.cpp
//  Project4-Part2
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>

#include "../part1/gauss/composite_Gauss2.cpp"

using Fcn = std::function<double(double)>;

double erf(const double& y, const int& n) {
    
    Fcn f = [&](double z) -> double {
        return std::exp(-std::pow(z, 2));
    };

    return (2 / std::sqrt(M_PI)) * composite_Gauss2(f, 0, y, n);

}

double carbon(const double& x, const double& t) {
    
    double c_0(0.002);
    double c_s(0.07);
    double d(1.75e-11);
    
    return c_s - (c_s - c_0) * erf((x / std::sqrt(4 * d * t)), 1000);
    
}
