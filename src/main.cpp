/// \mainpage
///  main.cpp
///  assign2_prototype
///
///  Created by Dustin on 2015-11-11.
///  Copyright © 2015 Dustin. All rights reserved.
///

#include <iostream>
#include <fstream>
#include <string>
#include "invest.pb.h"

using namespace std;


/*!
 * This is the Base Prototype class that will be the template for other classes
 */
class Base {
    protected:
        /*!
         * Protected string cname
         */
        string cname;
    public:
        /*!
         * Template for clone
         */
        virtual Base* clone() = 0;
        /*!
         * Getter method for cname
         */
        string getCName() {
            return cname;
        }
        /*!
         * Virtual Destructor function for Prototype Template
         */
         virtual ~Base() {
           cout << "Base destructor called\n";
         }
};

/*!
 * This is the Stock Prototype class that will be the template to be cloned for a stock
 */
class BaseChild1 : public Base {
    public:
        /*!
         * Constructor for BaseChild1 with string value
         */
        BaseChild1(string str) {
            cname = str;
        }
        /*!
         * Clone function for BaseChild1
         */
        Base* clone() {
            cout << "in BaseChild1 clone\n";
            return new BaseChild1(*this);
        }
        /*!
         * Destructor function for BaseChild1
         */
        ~BaseChild1() {
            cout << "In the BaseChild1 ~Destructor\n";
        }
};

/*!
 * This is the MutualFund Prototype class that will be the template to be cloned for a MutualFund
 */
class BaseChild2 : public Base {
    public:
        /*!
         * Constructor for BaseChild2 with string value
         */
        BaseChild2(string str) {
            cname = str;
        }
        /*!
         * Clone function for BaseChild2
         */
        Base* clone() {
            cout << "in BaseChild2 clone\n";
            return new BaseChild2(*this);
        }
        /*!
         * Destructor function for BaseChild2
         */
        ~BaseChild2() {
            cout << "In the BaseChild2 ~Destructor\n";
        }
};

//Factory to assist prototype instances and create their clones
class ObjFactory {
    /*!
     * Static prototype template classes
     */
    static Base* child1;
    static Base* child2;
    public:
        /*!
         * Initialization function of derived classes
         */
        static void init() {
            child1 = new BaseChild1("BaseChild1");
            child2 = new BaseChild2("BaseChild2");
        }
        /*!
         * Function to clone derived class 1
         */
        static Base* getNameVal1() {
            return child1->clone();
        }
        /*!
         * Function to clone derived class 2
         */
        static Base* getNameVal2() {
            return child2->clone();
        }
};

Base* ObjFactory::child1 = 0;
Base* ObjFactory::child2 = 0;

/*!
 * Main function for execution of creating classes and producing objects from user interaction.
 * There is a Base class that acts as a template and two derived classes Stock and MutualFund.
 */
int main(int argc, const char * argv[]) {
    //GOOGLE_PROTOBUF_VERIFY_VERSION;

    //invest::Invest investing;

    //investing.ParseFromIstream();

    /*!
     * Initialization of Objects and variables
     */
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

    //
    //Loop for prompting user for a string for the type and the instance name
    //
    while (s == "BaseChild1" || s == "BaseChild2") {
        cout << "Enter class you want to build (Basechild1, BaseChild2)\n";
        cin >> s;
        if (s=="BaseChild1") {
            obj = ObjFactory::getNameVal1();
            cout << obj->getCName() << endl;
        } else if (s=="BaseChild2") {
            obj = ObjFactory::getNameVal2();
            cout << obj->getCName() << endl;
        } else {
            break;
        }
    }
    
    //Reason for no destructor before was overwriting each time, which could memory leak, FIX
    delete obj;
    cout << "END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    return 0;
}
