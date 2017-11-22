//
//  application.cpp
//  MATH3316-Project3_Part3
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <iostream>

#include "lagrange_interpolator.hpp"

int main(int argc, char* argv[]) {
    
    LagrangeInterpolator l_interp;
    
    // initialize Vectors with recorded data
    PH::Vector years({1885, 1895, 1905, 1915,
                      1925, 1935, 1945, 1955,
                      1965, 1975, 1985, 1995});
    PH::Vector temps({56.70, 56.72, 56.87, 56.89,
                      57.01, 57.21, 57.28, 57.18,
                      57.12, 57.22, 57.65, 57.89});
    
    // create interval data points
    PH::Vector interval = PH::Vector::linSpace(1885, 1995, 200);
    
    // build the Lagrange interpolating polynomial
    PH::Vector comp(200);
    for(std::size_t i = 0; i < comp.size(); i++) {
        comp[i] = l_interp.lagrange(years, temps, interval[i]);
    }
    
    // predict the temperatures for the given years
    // using the interpolated polynomial
    PH::Vector predict_years({1903, 1941, 1963, 1969,
                              1976, 1989, 1999, 2009, 2015});
    PH::Vector predict_temps(predict_years.size());
    for(std::size_t i = 0; i < predict_years.size(); i++) {
        predict_temps[i] = l_interp.lagrange(years, temps, predict_years[i]);
    }
    
    // extend the set of data points
    PH::Vector interval_extended = PH::Vector::linSpace(1885, 2015, 200);
    
    // build the polynomial using the extended interval
    PH::Vector comp_extended(200);
    for(std::size_t i = 0; i < comp_extended.size(); i++) {
        comp_extended[i] = l_interp.lagrange(years, temps, interval_extended[i]);
    }
    
    try {
        std::string prefix = "res/part3/";
        years.saveTo(prefix + "years.txt");
        temps.saveTo(prefix + "temps.txt");
        comp.saveTo(prefix + "comp.txt");
        predict_years.saveTo(prefix + "predict_years.txt");
        predict_temps.saveTo(prefix + "predict_temps.txt");
        comp_extended.saveTo(prefix + "comp_extended.txt");
    } catch(std::runtime_error e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
    
}
