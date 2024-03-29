//
//  Runge_uniform.cpp
//  MATH3316-Project3_Part2_Runge
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <vector>

#include "lagrange_interpolator.hpp"
#include "newton_interpolator.hpp"
#include "Vector.h"

int main(int argc, char* argv[]) {
    
    // input function
    auto f = [](const double x) -> double {
        return (1 / (1 + std::pow(x, 2)));
    };
    
    LagrangeInterpolator l_interp;
    NewtonInterpolator n_interp;
    std::vector<std::size_t> n_vals({10, 20});
    
    for(auto& n : n_vals) {
        
        // initialize node Vectors
        PH::Vector x = PH::Vector::linSpace(-5, 5, n+1);
        PH::Vector y_real(x.size());
        for(std::size_t i = 0; i <= n; i++) {
            y_real[i] = f(x[i]);
        }
        
        // set evaluation points z as 401 equally spaced nodes in [-5,5]
        PH::Vector z = PH::Vector::linSpace(-5, 5, 401);
        
        // evaluate p_n(x) using Lagrange interpolation, along with the error
        PH::Vector y_comp(401);
        PH::Vector y_err(401);
        for(std::size_t i = 0; i < z.size(); i++) {
            y_comp[i] = l_interp.lagrange(x, y_real, z[i]);
            y_err[i] = std::abs(f(z[i]) - y_comp[i]);
        }
        
        // calculate phi_{n+1}(x)
        PH::Vector omega(401);
        if(n == 10) {
            for(std::size_t i = 0; i < z.size(); i++) {
                omega[i] = std::abs(n_interp.Newton_basis(x, n, z[i]));
            }
        }
        
        try {
            std::string prefix = "res/part2/";
            y_real.saveTo(prefix + "runge_uniform/runge_uniform_real" + std::to_string(n) + ".txt");
            y_comp.saveTo(prefix + "runge_uniform/runge_uniform_comp" + std::to_string(n) + ".txt");
            y_err.saveTo(prefix + "runge_uniform/runge_uniform_err" + std::to_string(n) + ".txt");
            omega.saveTo(prefix + "runge_uniform/runge_uniform_omega" + std::to_string(n) + ".txt");
        } catch(std::runtime_error e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        
    }
    
    return 0;
    
}
