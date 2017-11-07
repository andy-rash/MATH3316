//
//  newton_interpolator.cpp
//  MATH3316-Project3_Part1
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include "newton_interpolator.hpp"

NewtonInterpolator::NewtonInterpolator() { }

NewtonInterpolator::NewtonInterpolator(const NewtonInterpolator& ninterp) { }

NewtonInterpolator::~NewtonInterpolator() { }

double NewtonInterpolator::Newton_basis(PH::Matrix& xnodes, int k, double x) {
    
    return 0.0;
    
}

PH::Matrix NewtonInterpolator::Newton_coefficients(PH::Matrix& xnodes, PH::Matrix& ynodes) {
    
    PH::Matrix l;
    
    return l;
    
}

double NewtonInterpolator::Newton_nestedform(PH::Matrix& a, PH::Matrix& xnodes, double x) {
    
    return 0.0;
    
}
