//
//  lagrange_interpolator.hpp
//  MATH3316-Project3_Part2
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#ifndef LAGRANGE_INTERPOLATOR_HPP
#define LAGRANGE_INTERPOLATOR_HPP

#include <cmath>
#include <iostream>

#include "Vector.h"

class LagrangeInterpolator {
    
public:
    
    LagrangeInterpolator();
    
    LagrangeInterpolator(const LagrangeInterpolator& l_interp);
    
    ~LagrangeInterpolator();
    
    double lagrange(const PH::Vector& x, const PH::Vector& y, const double& z);
    
    double lagrange_basis(const PH::Vector& x, const std::size_t& i, const double& z);
    
};

#endif /* LAGRANGE_INTERPOLATOR_HPP */
