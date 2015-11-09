//
//  main.cpp
//  seng330_assign2
//
//  Created by Dustin on 2015-11-08.
//  Copyright © 2015 Dustin. All rights reserved.
//

#include <iostream>
#include <string>
#include "Base.hpp"
#include "Child1.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    
    cout << "Enter class you want to build (base, child1, child2)\n";
    cin >> s;
    
    while (s == "base" || s == "child1" || s == "child2") {
        cout << "Enter class you want to build (Base, child1, child2)\n";
        cin >> s;
    }
    
    if (s != "base" || s == "child1" || s == "child2") {
        cout << "Not a base, child1, or child2\nExiting\n";
    }
    
    return 0;
}
