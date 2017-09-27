//
//  proj1_b.cpp
//  MATH3316-Project1
//
//  Created by andy on 9/25/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cfloat>
#include <cmath>
#include <iostream>

#include "Vector.h"

double f(const double& x) {
    return std::log(x);
}

double f1(const double& x) {
    return (1 / x);
}

double f2(const double& x) {
    return -(1 / std::pow(x, 2.0));
}

double forward_difference_estimate(const double& a, const double& h) {
    return (f(a+h) - f(a)) / h;
}

double relative_error(const double& a, const double& h) {
    
    auto f1_a = f1(a);
    auto fde = forward_difference_estimate(a, h);
    
    return std::abs((f1_a - fde)/f1_a);
    
}

double relative_error_upper_bound(const double& a, const double& h) {
    
    auto f_a = f(a);
    auto f1_a = f1(a);
    auto f2_a = f2(a);
    
    auto c_1 = std::abs(f2_a / (2 * f1_a));
    auto c_2 = std::abs((f_a * DBL_EPSILON) / f1_a);
    
    return ((c_1 * h) + (c_2 * (1.0 / h)));
    
}

int main(int argc, const char * argv[]) {

    // Generate increments for
    // h = 2^(-n), n = (1, 2, 3, ... , 52)
    auto n = PH::Vector::linSpace(1, 52, 52);
    PH::Vector h = 2 ^ -n;
    
    auto a = 3.0;
    PH::Vector approximations(52), r_e(52), r_u(52);
    
    for(Index i = 0; i <= 52; i++) {
        
        r_e[i] = relative_error(a, h[i]);
        
        r_u[i] = relative_error_upper_bound(a, h[i]);
        
    }
    
    /*
     * Output files
     *
     */
    
    // output array n = (1, 2, 3, ... , 52)
    n.saveTo("res/part2/n.txt");
    
    // output array h = 2^(-n), n = (1, 2, 3, ... , 52)
    h.saveTo("res/part2/h.txt");
    
    // output array r (relative error of approximation)
    r_e.saveTo("res/part2/r_e.txt");
    
    // output array R (upper bound of relative error)
    r_u.saveTo("res/part2/r_u.txt");
    
    return 0;
    
}
