//
//  newton_interpolator.hpp
//  MATH3316-Project3_Part1
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#ifndef NEWTON_INTERPOLATOR_HPP
#define NEWTON_INTERPOLATOR_HPP

#include <iostream>

#include "Vector.h"

class NewtonInterpolator {
    
public:
    
    /*
     * Constructors
     *
     */
    
    NewtonInterpolator();
    
    NewtonInterpolator(const NewtonInterpolator& n_interp);
    
    ~NewtonInterpolator();
    
    double Newton_basis(const PH::Vector& x_nodes, const std::size_t& k, const double& x);
    
    PH::Vector Newton_coefficients(const PH::Vector& x_nodes, const PH::Vector& y_nodes);
    
    double Newton_nestedform(const PH::Vector& a, const PH::Vector& x_nodes, const double& x);
    
};

#endif /* NEWTON_INTERPOLATOR_HPP */
