//
//  base.cpp
//  seng330_assign2
//
//  Created by Dustin on 2015-11-08.
//  Copyright © 2015 Dustin. All rights reserved.
//

#include "base.hpp"
#include <iostream>

Base::Base() {
    std::cout << "In the Base Constructor\n";
}

Base::~Base() {
    std::cout << "In the Base Deconstructor\n";
}