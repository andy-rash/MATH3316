//
//  numerical_integrator.hpp
//  Project4-Part1
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#ifndef NUMERICAL_INTEGRATOR_HPP
#define NUMERICAL_INTEGRATOR_HPP

#include <functional>

using Fcn = std::function<double(double)>;

class NumericalIntegrator {
    
public:
    
    NumericalIntegrator();
    
    NumericalIntegrator(const NumericalIntegrator& copy);
    
    ~NumericalIntegrator();
  
    double composite_simpson(const Fcn& f, const double& a, const double& b, const int& n);
    
    double composite_trapezoidal(const Fcn& f, const double& a, const double& b, const int& n);
    
};

#endif /* NUMERICAL_INTEGRATOR_HPP */
