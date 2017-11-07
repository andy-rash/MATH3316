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

#include "Matrix.h"

class NewtonInterpolator {
    
public:
    
    /*
     * Constructors
     *
     */
    
    NewtonInterpolator();
    
    NewtonInterpolator(const NewtonInterpolator& ninterp);
    
    ~NewtonInterpolator();
    
    double Newton_basis(PH::Matrix& xnodes, int k, double x);
    
    PH::Matrix Newton_coefficients(PH::Matrix& xnodes, PH::Matrix& ynodes);
    
    double Newton_nestedform(PH::Matrix& a, PH::Matrix& xnodes, double x);
    
};

#endif /* NEWTON_INTERPOLATOR_HPP */
