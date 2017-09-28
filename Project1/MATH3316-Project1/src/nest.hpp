//
//  nest.hpp
//  MATH3316-Project1
//
//  Created by andy on 9/20/17.
//  Copyright © 2017 andy. All rights reserved.
//

#ifndef NEST_HPP
#define NEST_HPP

#include <fstream>

#include "Vector.h"

class Approximator {
    
private:
    
    // shared output file
    std::ofstream _output_file;
    
public:
    
    /*
     * Constructors
     *
     */
    
    Approximator();
    
    Approximator(const Approximator& appr);
    
    ~Approximator();
    
    // evaluate a polynomial at a given x value using a Vector of Taylor coefficients
    double nest(const PH::Vector& c, const double& x);
    
    // output the Vector contents to a file
    void output(const PH::Vector& c, const std::string& output_file_name);
    
};

#endif /* NEST_HPP */
