#include "gtest/gtest.h"
#include "main.cpp"

  TEST_F(investment_test, Index) {

	  	Index *index1;
	    EXPECT_EQ(index1->id , 0);
    }

  TEST_F(investment_test, Stock) {

	  	Index *index2;
	  	index2 = new Stock("Google");

	    EXPECT_EQ(index2->iname , "Google");
    }
  TEST_F(investment_test, Stock) {

	  	Index *index3;
	  	index3 = new Stock("Apple");

	    EXPECT_EQ(index3->iname , "Apple");
    }
  TEST_F(investment_test, MutualFund) {

	  	Index *index4;
	  	index4 = new MutualFund("Nasdaq");
	    EXPECT_EQ(index4->iname , "Nasdaq");
    }

}