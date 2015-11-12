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
            cout << "in BaseChild1 clone\n";
            return new BaseChild1(*this);
        }
        ~BaseChild1() {
            cout << "In the BaseChild1 ~Destructor\n";
        }
};

class BaseChild2 : public Base {
    public:
        BaseChild2(string str) {
            cname = str;
        }
        Base* clone() {
            cout << "in BaseChild2 clone\n";
            return new BaseChild2(*this);
        }
        ~BaseChild2() {
            cout << "In the BaseChild2 ~Destructor\n";
        }
};

//Factory to assist prototype instances and create their clones
class ObjFactory {
    static Base* child1;
    static Base* child2;
    public:
        static void init() {
            child1 = new BaseChild1("BaseChild1");
            child2 = new BaseChild2("BaseChild2");
        }
        static Base* getNameVal1() {
            return child1->clone();
        }
        static Base* getNameVal2() {
            return child2->clone();
        }
};

Base* ObjFactory::child1 = 0;
Base* ObjFactory::child2 = 0;

int main(int argc, const char * argv[]) {
    ObjFactory::init();
    Base* obj;
    string s;
    
    cout << "Enter object you want to (BaseChild1 || BaseChild2)\n";
    cin >> s;
    
    //Eventually create a func for this if-else
    if (s=="BaseChild1") {
        obj = ObjFactory::getNameVal1();
        cout << obj->getCName() << endl;
    } else if (s=="BaseChild2") {
        obj = ObjFactory::getNameVal2();
        cout << obj->getCName() << endl;
    }
    
    //Loop for prompting user for a string for the type and the instance name
    while (s == "BaseChild1" || s == "BaseChild2") {
        cout << "Enter class you want to build (Basechild1, BaseChild2)\n";
        cin >> s;
        if (s=="BaseChild1") {
            obj = ObjFactory::getNameVal1();
            cout << obj->getCName() << endl;
        } else if (s=="BaseChild2") {
            obj = ObjFactory::getNameVal2();
            cout << obj->getCName() << endl;
        }
    }
    return 0;
}
