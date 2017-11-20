//
//  newton_interpolator.cpp
//  MATH3316-Project3_Part1
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include "newton_interpolator.hpp"

NewtonInterpolator::NewtonInterpolator() { }

NewtonInterpolator::NewtonInterpolator(const NewtonInterpolator& n_interp) { }

NewtonInterpolator::~NewtonInterpolator() { }

// Evaluate the Newton basis function φ_(k+1)(x) = (x - x_0)(x - x_1) ... (x - x_k)
//
// @param xnodes -- PH::Vector containing nodes x_0, x_1, ... , x_k
// @param k      -- value k (i.e. number of iterations)
// @param x      -- value x used to evaluate the basis
double NewtonInterpolator::Newton_basis(const PH::Vector& x_nodes, const std::size_t& k, const double& x) {
    
    double phi(1.0);
    
    for(std::size_t i = 0; i < k+1; i++) {
        phi *= x - x_nodes[i];
    }
    
    return phi;
    
}

// Construct the Newtonian form of an interpolating polynomial
//
// together, x_nodes and y_nodes represent a set of known nodes (x_n, y_n).
// using these, the function outputs a PH::Vector containing coefficients
// a_0, a_1, ... , a_n for the Newton form.
//
// @param x_nodes -- PH::Vector containing the nodes x_0, x_1, ... , x_n
// @param y_nodes -- PH::Vector containing the nodes y_0, y_1, ... , y_n
//
PH::Vector NewtonInterpolator::Newton_coefficients(const PH::Vector& x_nodes, const PH::Vector& y_nodes) {
    
    if(x_nodes.size() != y_nodes.size()) {
        throw new std::invalid_argument("Vectors x_nodes and y_nodes are not the same size.");
    }
    
    std::size_t k = x_nodes.size();
    
    if(k == 0) { return PH::Vector(0); }

    PH::Vector a = PH::Vector(k);
    
    // p_0(x) = a_0 = y_0
    a[0] = y_nodes[0];
    
    for(std::size_t i = 1; i < k; i++) {
        PH::Vector a_truncated = a.range(0, i);
        
        double numer = y_nodes[i];
        numer -= Newton_nestedform(a_truncated, x_nodes, x_nodes[i]);
        
        double denom = Newton_basis(x_nodes, i-1, x_nodes[i]);
        
        a[i] = numer / denom;
    }
    
    return a;
    
}

// Evaluate the Newton form p_k(x) using nested multiplication (Horner's method)
//
// p_k(x) = a_0 + a_1(x - x_0) + a_2(x - x_0)(x - x_1) + ... + a_(k+1)(x - x_0)...(x - x_k)
//
// nested form:
// p_k(x) = a_0 + (x - x_0)(a_1 + (x - x_1)( ... a_k + (x - x_k)(a_k + 1) ... ))
//
// @param a       -- PH::Vector containing coefficients
// @param x_nodes -- PH::Vector containing nodes x_0, x_1, ... , x_k
// @param x       -- value x used to evaluate the polynomial
double NewtonInterpolator::Newton_nestedform(const PH::Vector& a, const PH::Vector& x_nodes, const double& x) {
    
    std::size_t k = a.size();
    double p_k(a[k-1]);
    
    for(std::size_t i = k-2; i > 0; i--) {
        // std::fma(x, y, z) = (x * y) + z
        p_k = std::fma(p_k, (x - x_nodes[i]), a[i]);
    }
    p_k = std::fma(p_k, (x - x_nodes[0]), a[0]);
    
    return p_k;
    
}
