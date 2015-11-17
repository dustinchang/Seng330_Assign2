all: cpp

cpp: mainexec listexec

mainexec: main.cpp
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ main.cpp invest.pb.cc -o main_cpp `pkg-config --cflags --libs protobuf`

listexec: list_portfolio.cpp
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ list_portfolio.cpp invest.pb.cc -o list_portfolio_cpp `pkg-config --cflags --libs protobuf`