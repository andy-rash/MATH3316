//
//  test_newton.cpp
//  MATH3316-Project2
//
//  Created by andy on 10/12/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>

#include "newton.cpp"

int main(int argc, const char* argv[]) {
    
    // calculate f(x)
    Fcn f = [](double x) -> double {
        return (std::pow(x, 2) * (x - 3) * (x + 2));
    };
    
    // calculate df(x)
    Fcn df = [](double x) -> double {
        return ((4 * std::pow(x, 3)) - (3 * std::pow(x, 2)) - (12 * x));
    };
    
    std::size_t max_iter = 50;
    for(double x_0 : {-3.0, 1.0, 2.0}) {
        
        for(double eps : {1.e-1, 1.e-5, 1.e-9}) {
            
            std::cout << "x_0 = " << x_0 << std::endl;
            std::cout << "eps = " << eps << std::endl;
            
            double x = newton(f, df, x_0, max_iter, eps, true);
            
            std::cout << "The approximate root is: " << x << std::endl << std::endl;
            
        }
        
    }
    
    return 0;
    
}
