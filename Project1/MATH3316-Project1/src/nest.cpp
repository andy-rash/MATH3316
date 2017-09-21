//
//  nest.cpp
//  MATH3316-Project1
//
//  Created by andy on 9/20/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include "nest.hpp"

Approximator::Approximator() { }

Approximator::Approximator(const Approximator& appr) { }

Approximator::~Approximator() { }

double Approximator::nest(const PH::Vector& c, const double& x) {
    
    double p = (double)c[c.size()-1];
    for(Index k = c.size()-2; k > 0; k--) {
        p = (double)c[k] + (p * x);
    }
    p = (double)c[0] + (p * x);
    
    return p;
    
}

void Approximator::output(const PH::Vector& c, const std::string& output_file_name) {
    
    _output_file.open(output_file_name.c_str());
    
    _output_file << c << std::endl;
    
    _output_file.close();
    
}
