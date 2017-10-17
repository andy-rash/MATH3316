//
//  newton.cpp
//  MATH3316-Project2
//
//  Created by andy on 10/12/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <functional>
#include <iostream>

// better way to pass functions as arguments
// than Dr. Reynolds's method
using Fcn = std::function<double(double)>;


/*
 * Newton's Method
 * ---------------
 *
 * x_n+1 = x_n + (f(x_n) / df(x_n))
 *
 */
double newton(Fcn& f, Fcn& df,
              double x, std::size_t maxit,
              double tol, bool show_iterates) {

    double prev = x;
    for(std::size_t i = 1; i < maxit; i++) {

        // output
        if(show_iterates) {

            std::cout << "iter "     << i                  << ", "
                      << "x = "      << x                  << ", "
                      << "|h| = "    << std::abs(prev - x) << ", "
                      << "|f(x)| = " << f(x)               << std::endl;

        }

        // end iteration when within given tolerance
        if(tol > std::abs(f(x) / df(x))) { break; }

        prev = x;
        x = x - (f(x) / df(x));

    }

    return x;

}
