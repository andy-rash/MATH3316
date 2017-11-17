//
//  lagrange_interpolator.cpp
//  MATH3316-Project3_Part2
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include "lagrange_interpolator.hpp"

LagrangeInterpolator::LagrangeInterpolator() { }

LagrangeInterpolator::LagrangeInterpolator(const LagrangeInterpolator& l_interp) { }

LagrangeInterpolator::~LagrangeInterpolator() { }

// Utility function to evaluate a given Lagrange basis function at a point, phi_i(z).
//
// Usage: l = lagrange_basis(x, i, z);
//
// inputs:   x     Vector of length n+1, containing the interpolation nodes
//           i     integer indicating which Lagrange basis function to evaluate
//           z     double location to evaluate basis function
// outputs:  p     value of phi_i(z)
//
double LagrangeInterpolator::lagrange_basis(const PH::Vector& x, const std::size_t& i, const double& z) {
    
    // initialize basis function
    double l = 1.0;
    
    for(std::size_t j = 0; j < x.size(); j++) {
        if(j != i) {
            l *= (z - x[j]) / (x[i] - x[j]);
        }
    }
    
    return l;
    
}

// This routine evaluates the Lagrange interpolating polynomial,
// defined over a set of data points (x_i,y_i), i=0,...,n, at a point z.
//
// Usage: p = lagrange(x, y, z);
//
// inputs:   x     Vector of length n+1, containing the interpolation nodes
//           y     Vector of length n+1, containing the interpolation data
//           z     double location to evaluate polynomial
// outputs:  p     value of p(z)
//
double LagrangeInterpolator::lagrange(const PH::Vector& x, const PH::Vector& y, const double& z) {
    
    // check input arguments (lengths of x and y)
    if (x.size() != y.size()) {
        throw new std::invalid_argument("Vectors x and y are not the same size.");
    }
    
    // evaluate p
    
    // initialize result
    double p(0.0);
    
    // loop over data values
    for(std::size_t i = 0; i < x.size(); i++) {
        // update result with next term
        p += y[i] * lagrange_basis(x, i, z);
    }
    
    // return final result
    return p;
    
}
