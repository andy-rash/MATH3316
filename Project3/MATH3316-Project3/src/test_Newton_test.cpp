//
//  test_Newton_test.cpp
//  MATH3316-Project3
//
//  Created by andy on 11/6/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>

#include "newton_interpolator.hpp"

int main(int argc, char* argv[]) {
    
    NewtonInterpolator n_interp;
    
    // function to evaluate
    auto f = [](const double& x) -> double {
        return ((3.1 * std::pow(x, 4)) + (2.3 * std::pow(x, 3)) - (6.6 * std::pow(x, 2)) + (8.7 * x) + 7.9);
    };
    
    // x nodes are {-2, -1, 0, 1, 2}
    PH::Vector x_nodes({-2, -1, 0, 1, 2});
    
    // y nodes are f(x_nodes)
    PH::Vector y_nodes(x_nodes);
    y_nodes.mapElements([&](double& e, std::size_t i){ e = f(e); });
    
    // Build the fourth-degree polynomial p_4(x)
    PH::Vector p4 = n_interp.Newton_coefficients(x_nodes, y_nodes);
    
    // Evaluate both f(x) and p_4(x) on 201 values over the interval [-3,3]
    PH::Vector x_values = PH::Vector::linSpace(-3, 3, 201);
    PH::Vector y_real = PH::Vector(x_values.size());
    PH::Vector y_comp = PH::Vector(x_values.size());
    PH::Vector y_err = PH::Vector(x_values.size());
    
    for(std::size_t i = 0; i < x_values.size(); i++) {
        y_real[i] = f(x_values[i]);
        y_comp[i] = n_interp.Newton_nestedform(p4, x_nodes, x_values[i]);
        y_err[i] = std::abs(y_real[i] - y_comp[i]);
    }
    
    try {
        std::string prefix = "res/part1/";
        y_real.saveTo(prefix + "y_real.txt");
        y_comp.saveTo(prefix + "y_comp.txt");
        y_err.saveTo(prefix + "y_err.txt");
    } catch(std::runtime_error e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
    
}
