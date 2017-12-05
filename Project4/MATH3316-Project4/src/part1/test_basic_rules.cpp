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
    int n = 1000;
    
    double I_true = polynomial_antiderivative(b) - polynomial_antiderivative(a);
    double I_approx_simp = n_integ.composite_simpson(polynomial, a, b, n);
    double I_approx_trapezoid = n_integ.composite_trapezoidal(polynomial, a, b, n);
    
    double I_approx_simp_err = std::abs(I_true - I_approx_simp);
    double I_approx_trapezoid_err = std::abs(I_true - I_approx_trapezoid);
    
    printf("True Integral (polynomial) = %22.16e\n\n", I_true);
    
    std::cout << "Simpson's Rule Polynomial test (f(x) = 6x^2 - 4x + 1):" << std::endl;
    std::cout << "     n             I_f                abs err" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    printf("  %6i    %22.16e    %7.1e         \n\n", n, I_approx_simp, I_approx_simp_err);
    
    std::cout << "Trapezoid Rule Polynomial test (f(x) = 6x^2 - 4x + 1):" << std::endl;
    std::cout << "     n             I_f                abs err" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    printf("  %6i    %22.16e    %7.1e         \n\n\n", n, I_approx_trapezoid, I_approx_trapezoid_err);
    
    std::cout << "=======================================================" << std::endl << std::endl << std::endl;
    
    printf("True Integral (trig function) = %22.16e\n", trig_antiderivative);
    
    std::cout << "\n Simpson Rule approximation:\n";
    std::cout << "     n             I_f             abs err    conv rate\n";
    std::cout << "  -----------------------------------------------------\n";
    
    std::vector<int> n_vals({20, 40, 80, 160, 320, 640});
    std::vector<double> errors;
    std::vector<double> h_vals;
    a = -1.0;
    b = 1.0;
    for(std::size_t i = 0; i < n_vals.size(); i++) {
        
        double trig_integ_simp = n_integ.composite_simpson(trig, a, b, n_vals[i]);
        errors.push_back(std::abs(trig_antiderivative - trig_integ_simp));
        h_vals.push_back((double)((b - a) / n_vals[i]));
        
        printf("   %6i", n_vals[i]);
        
        if(i == 0) {
            printf("  %22.16e  %7.1e     ----\n", trig_integ_simp, errors[i]);
        } else {
            printf("  %22.16e  %7.1e   %f\n", trig_integ_simp, errors[i],
                   (std::log(errors[i-1]) - std::log(errors[i])) / (std::log(h_vals[i-1]) - std::log(h_vals[i])));
        }
        
    }
    
    std::cout << "\n Trapezoid Rule approximation:\n";
    std::cout << "     n             I_f             abs err    conv rate\n";
    std::cout << "  -----------------------------------------------------\n";
    
    errors.clear();
    h_vals.clear();
    for(std::size_t i = 0; i < n_vals.size(); i++) {
        
        double trig_integ_trapezoid = n_integ.composite_trapezoidal(trig, a, b, n_vals[i]);
        errors.push_back(std::abs(trig_antiderivative - trig_integ_trapezoid));
        h_vals.push_back((double)((b - a) / n_vals[i]));
        
        printf("   %6i", n_vals[i]);
        
        if(i == 0) {
            printf("  %22.16e  %7.1e     ----\n", trig_integ_trapezoid, errors[i]);
        } else {
            printf("  %22.16e  %7.1e   %f\n", trig_integ_trapezoid, errors[i],
                   (std::log(errors[i-1]) - std::log(errors[i])) / (std::log(h_vals[i-1]) - std::log(h_vals[i])));
        }
        
    }
    
    return 0;

}
