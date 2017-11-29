//
//  main.cpp
//  Project4-Part1
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <cmath>

#include "numerical_integrator.hpp"

int main(int argc, const char* argv[]) {
    
    // Function declarations
    
    Fcn polynomial = [&](double x) -> double {
        return ((6 * std::pow(x, 2)) - (4 * x) + 1);
    };

    Fcn polynomial_antiderivative = [&](double x) -> double {
        return ((2 * std::pow(x, 3)) - (2 * std::pow(x, 2)) + x);
    };
    
    Fcn trig = [&](double x) -> double {
        return ((std::sin(M_PI * x)) * (std::exp(x)));
    };
    
    double trig_antiderivative = ((M_PI * (std::exp(1) - (1 / std::exp(1)))) / (1 + (std::pow(M_PI, 2))));
    
    NumericalIntegrator n_integ;
    double a = -1.0;
    double b = 2.0;
    
    double I_true = polynomial_antiderivative(b) - polynomial_antiderivative(a);
    
    std::vector<int> n_vals({20, 40, 80, 160, 320, 640});
    for(std::size_t i = 0; i < n_vals.size(); i++) {
        
        double poly_integ = n_integ.composite_simpson(polynomial, a, b, n_vals[i]);
        double poly_integ_err = std::abs(I_true - poly_integ);

        std::cout << "Polynomial: "<< n_vals[i] << " " << poly_integ << " " << poly_integ_err << std::endl;

        poly_integ = n_integ.composite_trapezoidal(polynomial, a, b, n_vals[i]);
        poly_integ_err = std::abs(I_true - poly_integ);

        std::cout << "Polynomial: "<< n_vals[i] << " " << poly_integ << " " << poly_integ_err << std::endl;
        
//        double trig_integ_simp = n_integ.composite_simpson(trig, -1.0, 1.0, n_vals[i]);
//        double trig_integ_err = std::abs(trig_antiderivative - trig_integ_simp);
//
//        std::cout << "Trig: "<< n_vals[i] << " " << trig_integ_simp << " " << trig_antiderivative << " " << trig_integ_err << std::endl;
        
    }
    
    return 0;

}
