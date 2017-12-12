//
//  carbon.cpp
//  Project4-Part2
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>

#include "../part1/gauss/composite_Gauss2.cpp"

// Error function
//
// erf(y) = (2 / pi) * \integral_{0}^{y} e^(-z^2) dz
//
// * the 'n' parameter is used in composite_Gauss2()
//
double erf(const double& y, const int& n) {
    
    Fcn f = [&](double z) -> double {
        return std::exp(-std::pow(z, 2));
    };

    return (2 / std::sqrt(M_PI)) * composite_Gauss2(f, 0, y, n);

}

// Carbon concentration
//
// calculated using C(x,t) where
//
//     C(x,t) = C_s - (C_s - C_0) * erf(x / sqrt(4 * D * t))
//
//     C_s = carbon concentration in gas
//     C_0 = initial carbon concentration
//     n   = number of iterations to pass to composite_Gauss2
//     x   = value at which to evaluate the function
//     D   = diffusion coefficient
//     t   = time
//
double carbon(const double& x, const double& t) {
    
    double c_0(0.002);
    double c_s(0.07);
    double d(1.75e-11);
    int n(1000);
    
    return c_s - (c_s - c_0) * erf((x / std::sqrt(4 * d * t)), n);
    
}
