//
//  base.cpp
//  seng330_assign2
//
//  Created by Dustin on 2015-11-08.
//  Copyright © 2015 Dustin. All rights reserved.
//

#include <iostream>
#include "Base.hpp"
//#include "Child1.hpp"

using namespace std;

Base::Base() {
    cout << "In the Base Constructor\n";
}

Base::~Base() {
    cout << "In the Base ~Deconstructor\n";
}