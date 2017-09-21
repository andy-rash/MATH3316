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
    
    std::ofstream _output_file;
    
public:
    
    Approximator();
    
    Approximator(const Approximator& appr);
    
    ~Approximator();
    
    double nest(const PH::Vector& c, const double& x);
    
    void output(const PH::Vector& c, const std::string& output_file_name);
    
};

#endif /* NEST_HPP */
