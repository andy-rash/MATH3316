//
//  main.cpp
//  MATH3316-Project1
//
//  Created by andy on 9/20/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#include "nest.hpp"

// simple factorial function
unsigned int factorial(const unsigned int& n) {
    return n == 0 ? 1 : (n * factorial(n - 1));
}

// return a Vector containing n Taylor coefficients for f(x) = e^x
PH::Vector exp_taylor_coef(int degree) {
    
    std::vector<double> ret;
    
    for(int i = 0; i <= degree; i++) {
        if(i == 0) { ret.push_back(double(1)); }
        else {
            ret.push_back((double)1 / (double)factorial(i));
        }
    }
    
    return PH::Vector(ret);
    
}

int main(int argc, const char * argv[]) {
    
    /*
     * Calculations
     *
     */
    
    Approximator * appr = new Approximator();
    
    PH::Vector z = z.linSpace(-1.0, 1.0, 201);
    
    PH::Vector p4_coef = exp_taylor_coef(4);
    PH::Vector p8_coef = exp_taylor_coef(8);
    PH::Vector p12_coef = exp_taylor_coef(12);
    
    std::vector<double> p4_vec;
    std::vector<double> p8_vec;
    std::vector<double> p12_vec;
    std::vector<double> f_vec;
    std::vector<double> err4_vec;
    std::vector<double> err8_vec;
    std::vector<double> err12_vec;
    
    // calculate with Taylor polynomials
    for(int i = 0; i < z.size(); i++) { p4_vec.push_back(appr->nest(p4_coef, z[i])); }
    for(int i = 0; i < z.size(); i++) { p8_vec.push_back(appr->nest(p8_coef, z[i])); }
    for(int i = 0; i < z.size(); i++) { p12_vec.push_back(appr->nest(p12_coef, z[i])); }
    
    // calculate with built-in exponential function
    for(int i = 0; i < z.size(); i++) { f_vec.push_back(exp(z[i])); }
    
    // calculate error
    for(int i = 0; i < f_vec.size(); i++) { err4_vec.push_back(abs(f_vec[i] - p4_vec[i])); }
    for(int i = 0; i < f_vec.size(); i++) { err8_vec.push_back(abs(f_vec[i] - p8_vec[i])); }
    for(int i = 0; i < f_vec.size(); i++) { err12_vec.push_back(abs(f_vec[i] - p12_vec[i])); }
    
    /*
     * Output files
     *
     */
    
    PH::Vector p4(p4_vec);
    PH::Vector p8(p8_vec);
    PH::Vector p12(p12_vec);
    PH::Vector f(f_vec);
    PH::Vector err4(err4_vec);
    PH::Vector err8(err8_vec);
    PH::Vector err12(err12_vec);
    
    appr->output(z, "res/part1/z.txt");
    appr->output(p4, "res/part1/p4.txt");
    appr->output(p8, "res/part1/p8.txt");
    appr->output(p12, "res/part1/p12.txt");
    appr->output(f, "res/part1/f.txt");
    appr->output(err4, "res/part1/err4.txt");
    appr->output(err8, "res/part1/err8.txt");
    appr->output(err12, "res/part1/err12.txt");
    
    return 0;

}
