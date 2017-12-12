//
//  numerical_integrator.cpp
//  Project4-Part1
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include "numerical_integrator.hpp"

NumericalIntegrator::NumericalIntegrator() { }

NumericalIntegrator::NumericalIntegrator(const NumericalIntegrator& copy) { }

NumericalIntegrator::~NumericalIntegrator() { }

// Implementation of the composite Simpson's rule
//
// The definite integral on the interval [a,b] for f(x) can be
// approximated by T(f,h) where
//
//     S(f,h) = (h / 3)(f(a) + f(b)) + ((2 * h) / 3) * \summation_{k=1}^{M-1}(f(x_k)) + ((4 * h) / 3) * \summation_{k=1}^{M}(f(x_k1))
//
//     h = (b - a) / n
//     M = n / 2
//     x_k = a + (2 * k) * h;
//     x_k1 = a + (2 * k - 1) * H
//
//     * 'n' must be an even number
//
double NumericalIntegrator::composite_simpson(const Fcn& f, const double& a, const double& b, const int& n) {
    
    if(b < a) {
        throw std::invalid_argument("Illegal interval [a,b]: b < a");
        return 1;
    }
    
    if(n < 1) {
        throw std::invalid_argument("Illegal number of subintervals n: n < 1");
        return 1;
    }
    
    // n must be divisible by 2 for composite Simpson's rule
    if(n % 2 != 0) {
        throw std::invalid_argument("Illegal number of subintervals n: n must be even");
        return 1;
    }
    
    double h = (b - a) / n;
    double approx(f(a) + f(b));
    
    // perform summation 1
    for(std::size_t k = 1; k < n; k += 2) {
        approx += 4 * f(a + k * h);
    }
    
    // perform summation 2
    for(std::size_t k = 2; k < n-1; k += 2) {
        approx += 2 * f(a + k * h);
    }
    
    // put it all together
    return approx * h / 3.0;
    
}

// Implementation of the composite trapezoidal rule
//
// The definite integral on the interval [a,b] for f(x) can be
// approximated by T(f,h) where
//
//     T(f,h) = (h / 2)(f(a) + f(b)) + h * \summation_{k=1}^{n-1}(f(x_k))
//
//     h = (b - a) / n
//     x_k = a + k * h;
//
double NumericalIntegrator::composite_trapezoidal(const Fcn& f, const double& a, const double& b, const int& n) {
    
    if(b < a) {
        throw std::invalid_argument("Illegal interval [a,b]: b < a");
        return 1;
    }
    
    if(n < 1) {
        throw std::invalid_argument("Illegal number of subintervals n: n < 1");
        return 1;
    }
    
    double h = (b - a) / n;
    double approx((f(a) + f(b)));
    
    // perform summation
    for(std::size_t k = 1; k < n-1; k++) {
        approx += 2 * f(a + k * h);
    }
    
    // put it all together
    return approx * h / 2.0;
    
}
