//
//  test_carbon.cpp
//  Project4-Part2
//
//  Created by andy on 11/28/17.
//  Copyright © 2017 andy. All rights reserved.
//

#include <iostream>
#include <vector>

#include "carbon.cpp"
#include "Vector.h"

int main(int argc, const char* argv []) {
    
    PH::Vector interval = PH::Vector::linSpace(0.0, 0.003, 200);
    std::vector<int> t_vals({1, 2, 10, 40});
    
    for(auto& t : t_vals) {
        
        PH::Vector data(interval.size());
        
        for(std::size_t i = 0; i < interval.size(); i++) {
            data[i] = carbon(interval[i], t*3600);
        }
        
        try {
            std::string prefix("res/part2/");
            data.saveTo(prefix + "carbon_" + std::to_string(t) + ".txt");
        } catch(std::runtime_error e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        
    }
    
    return 0;
    
}
