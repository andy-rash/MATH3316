//
//  proj1_c.cpp
//  MATH3316-Project1
//
//  Created by andy on 9/25/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#include "Vector.h"

// simple factorial function
unsigned int factorial(const unsigned int& n) {
    return n == 0 ? 1 : (n * factorial(n - 1));
}

// calculate recurrence relation for j = {1, 2, ... , 25}
double recurrence_relation(const int& j, const double& v_j1) {
    return 1.0 - (j * v_j1);
}

int main(int argc, const char * argv[]) {
    
    /*
     * Calculations
     *
     */
    
    std::vector<double> e;
    double epsilons[] = { 0.13, 0.0024, 0.000035 };
    std::vector<unsigned int> j(26);
    std::vector<double> v;
    std::vector<std::vector<double>> v_e(3);
    std::vector<std::vector<double>> e_e(3);
    
    // fill j with values 0..25
    std::iota(j.begin(), j.end(), 0);
    
    // perform initial calculations
    for(auto& i : j) {
        if(i == 0) {
            double v_0 = 1.0 - (1.0 / exp(1.0));
            v.push_back(v_0);
            e.push_back(v_0 / factorial(i));
            continue;
        } else {
            double v_j = recurrence_relation(i, v[i-1]);
            v.push_back(v_j);
            e.push_back(v_j / factorial(i));
            
        }
    }
    
    // perform calculations that include epsilon values
    for(int x = 0; x < 3; x++) {
        for(auto& i : j) {
            if(i == 0) {
                double v_0 = 1.0 - (1.0 / exp(1.0)) + epsilons[x];
                v_e[x].push_back(v_0);
                e_e[x].push_back(abs(v_0 / factorial(i)));
                continue;
            } else {
                double v_j = recurrence_relation(i, v_e[x][i-1]);
                v_e[x].push_back(v_j);
                e_e[x].push_back(abs(v_j / factorial(i)));
            }
            
        }
    }
    
    /*
     * Output files
     *
     */
    
    // output j vector
    std::ofstream _output_file;
    _output_file.open("res/part3/j.txt");
    for(auto& i : j) {
        _output_file << i << std::endl;
    }
    _output_file.close();
    
    // output initial vector v
    _output_file.open("res/part3/v.txt");
    for(auto& i : j) {
        _output_file << v[i] << std::endl;
    }
    _output_file.close();
    
    // output initial estimate vector e
    _output_file.open("res/part3/e.txt");
    for(auto& i : j) {
        _output_file << e[i] << std::endl;
    }
    _output_file.close();
    
    // output calculation and estimation vectors v2_(1..3) and e2_(1..3)
    for(int x = 0; x < 3; x++) {
        
        std::string filename = "res/part3/v2_e" + std::to_string(x+1) + ".txt";
        
        _output_file.open(filename.c_str());
        for(auto& i : j) {
            _output_file << v_e[x][i] << std::endl;
        }
        _output_file.close();
        
        filename = "res/part3/e2_e" + std::to_string(x+1) + ".txt";
        _output_file.open(filename.c_str());
        for(auto& i : j) {
            _output_file << e_e[x][i] << std::endl;
        }
        _output_file.close();
        
    }
    
    return 0;
    
}
