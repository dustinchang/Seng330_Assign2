#include <iostream>
#include <fstream>
#include <string>
#include "invest.pb.h"
using namespace std;

//
// Iterates though all investments in the portfolio
//
void ListInvestments(const invest::Portfolio& investing_portfolio) {
  for (int i = 0; i < investing_portfolio.index_size(); i++) {
    const invest::Investment& investment = investing_portfolio.index(i);

    cout << "Investment ID: " << investment.id() << endl;
    cout << "Investment Name: " << investment.iname() << endl;

  }
}

//
// Reads the portfolio from file and prints the contents from it.
//
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  //
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " INVESTING_FILE" << endl;
    return -1;
  }

  invest::Portfolio investing_portfolio;

  {
    // Read the existing portfolio
    fstream input(argv[1], ios::in | ios::binary);
    if (!investing_portfolio.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }
  }

  ListInvestments(investing_portfolio);

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
