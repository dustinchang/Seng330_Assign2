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
 * This is the Index Prototype class that will be the template for other classes
 */
class Index {
    protected:
        /*!
         * Protected string iname
         */
        string iname;
        int id;
    public:
        /*!
         * Template for clone
         */
        virtual Index* clone() = 0;
        /*!
         * Getter method for iname
         */
        string getIname() {
            return iname;
        }
        /*!
         * Getter method for id
         */
        int get_ID() {
            return id;
        }
        /*!
         * Virtual Destructor function for Prototype Template
         */
         virtual ~Index() {
           cout << "Index destructor called\n";
         }
};

/*!
 * This is the Stock Prototype class that will be the template to be cloned for a stock
 */
class Stock : public Index {
    public:
        /*!
         * Constructor for Stock with string value
         */
        Stock(string str) {
            iname = str;
        }
        /*!
         * Clone function for Stock
         */
        Index* clone() {
            cout << "in Stock clone\n";
            return new Stock(*this);
        }
        /*!
         * Destructor function for Stock
         */
        ~Stock() {
            cout << "In the Stock ~Destructor\n";
        }
};

/*!
 * This is the MutualFund Prototype class that will be the template to be cloned for a MutualFund
 */
class MutualFund : public Index {
    public:
        /*!
         * Constructor for MutualFund with string value
         */
        MutualFund(string str) {
            iname = str;
        }
        /*!
         * Clone function for MutualFund
         */
        Index* clone() {
            cout << "in MutualFund clone\n";
            return new MutualFund(*this);
        }
        /*!
         * Destructor function for MutualFund
         */
        ~MutualFund() {
            cout << "In the MutualFund ~Destructor\n";
        }
};

//Factory to assist prototype instances and create their clones
class ObjFactory {
    /*!
     * Static prototype template classes
     */
    static Index* child1;
    static Index* child2;
    public:
        /*!
         * Initialization function of derived classes
         */
        static void init() {
            child1 = new Stock("Stock");
            child2 = new MutualFund("MutualFund");
        }
        /*!
         * Function to clone derived class 1
         */
        static Index* getNameVal1() {
            return child1->clone();
        }
        /*!
         * Function to clone derived class 2
         */
        static Index* getNameVal2() {
            return child2->clone();
        }
};

/*!
 * Prompts user for interaction and adds the name and id of the investment they want to add
 */
void PromptForInvestment(invest::Investment* investment) {
    cout << "Enter investment ID number: ";
    int id;
    cin >> id;
    investment->set_id(id);
    cin.ignore(256, '\n');

    cout << "Enter type of investment: ";
    getline(cin, *investment->mutable_iname());
}

Index* ObjFactory::child1 = 0;
Index* ObjFactory::child2 = 0;

/*!
 * Main function for execution of creating classes and producing objects from user interaction.
 * There is a Index class that acts as a template and two derived classes Stock and MutualFund.
 */
int main(int argc, const char * argv[]) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc != 2) {
        cerr << "Usage:  " << argv[0] << " INVESTMENT_FILE" << endl;
        return -1;
    }
    
    invest::Portfolio investing_portfolio;
    
    {
        // Read the existing portfolio
        fstream input(argv[1], ios::in | ios::binary);
        if (!input) {
            cout << argv[1] << ": File not found.  Creating a new file." << endl;
        } else if (!investing_portfolio.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }

    PromptForInvestment(investing_portfolio.add_index());

    {
      // Write the new portfolio
      fstream output(argv[1], ios::out | ios::trunc | ios::binary);
      if (!investing_portfolio.SerializeToOstream(&output)) {
        cerr << "Failed to write portfolio." << endl;
        return -1;
      }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    //return 0;

    


    /*!
     * Initialization of Objects and variables
     */
    ObjFactory::init();
    Index* obj;
    string s;

    cout << "Enter object you want to (Stock || MutualFund)\n";
    cin >> s;

    //Eventually create a func for this if-else
    if (s=="Stock") {
        obj = ObjFactory::getNameVal1();
        cout << obj->getIname() << endl;
    } else if (s=="MutualFund") {
        obj = ObjFactory::getNameVal2();
        cout << obj->getIname() << endl;
    }

    //
    //Loop for prompting user for a string for the type and the instance name
    //
    while (s == "Stock" || s == "MutualFund") {
        cout << "Enter class you want to build (Stock, MutualFund)\n";
        cin >> s;
        if (s=="Stock") {
            obj = ObjFactory::getNameVal1();
            cout << obj->getIname() << endl;
        } else if (s=="MutualFund") {
            obj = ObjFactory::getNameVal2();
            cout << obj->getIname() << endl;
        } else {
            break;
        }
    }
    
    //Reason for no destructor before was overwriting each time, which could memory leak, FIX
    delete obj;
    cout << "END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    return 0;
}
