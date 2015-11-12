//
//  main.cpp
//  assign2_prototype
//
//  Created by Dustin on 2015-11-11.
//  Copyright © 2015 Dustin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Base {
    protected:
        string cname;
    public:
    virtual Base* clone() = 0;
    string getCName() {
        return cname;
    }
};

class BaseChild1 : public Base {
    public:
        BaseChild1(string str) {
            cname = str;
        }
        Base* clone() {
            return new BaseChild1(*this);
        }
};

class BaseChild2 : public Base {
public:
    BaseChild2(string str) {
        cname = str;
    }
    Base* clone() {
        return new BaseChild2(*this);
    }
};

//Factory to assist prototype instances and create their clones
class ObjFactory {
    static Base* child1;
    static Base* child2;
    public:
        static void init() {
            child1 = new BaseChild1("child1");
            child2 = new BaseChild2("child2");
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
