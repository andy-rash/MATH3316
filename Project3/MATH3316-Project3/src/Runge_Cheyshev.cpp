//
//  Runge_Cheyshev.cpp
//  MATH3316-Project3_Part2_Runge_Chebyshev
//
//  Created by andy on 11/7/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#include "lagrange_interpolator.hpp"
#include "Vector.h"

int main(int argc, char* argv[]) {
    
    auto f = [](const double x) -> double {
        return (1 / (1 + std::pow(x, 2)));
    };
    
    auto chebyshev = [](const double a, const double b, const std::size_t i, const std::size_t n) -> double {
        return (0.5*(a + b) + 0.5*(b - a) * std::cos((((2 * i + 1) * M_PI) / (2 * n + 2))));
    };
    
    LagrangeInterpolator l_interp;
    std::vector<std::size_t> n_vals({10, 20});

    for(auto& n : n_vals) {

        // initialize node Vectors
        std::vector<double> chebyshev_nodes(n+1);
        for(std::size_t i = 0; i <= n; i++) {
            chebyshev_nodes[i] = chebyshev(-5, 5, i, n+1);
        }
        
        PH::Vector x(chebyshev_nodes);
        PH::Vector y_real(x.size());
        for(std::size_t i = 0; i <= n; i++) {
            y_real[i] = f(x[i]);
        }

        // set evaluation points z as midpoints between nodes
        PH::Vector z = PH::Vector::linSpace(-5, 5, 401);

        // evaluate p_4(x) using Lagrange interpolation, along with the error
        PH::Vector y_comp(401);
        PH::Vector y_err(401);
        for(std::size_t i = 0; i < z.size(); i++) {
            y_comp[i] = l_interp.lagrange(x, y_real, z[i]);
            y_err[i] = std::abs(f(z[i]) - y_comp[i]);
        }

        try {
            std::string prefix = "../res/part2/";
            x.saveTo(prefix + "runge_Chebyshev_nodes" + std::to_string(n) + ".txt");
            y_real.saveTo(prefix + "runge_Chebyshev_real" + std::to_string(n) + ".txt");
            y_comp.saveTo(prefix + "runge_Chebyshev_comp" + std::to_string(n) + ".txt");
            y_err.saveTo(prefix + "runge_Chebyshev_err" + std::to_string(n) + ".txt");
        } catch(std::runtime_error e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

    }
    
    return 0;
    
}
