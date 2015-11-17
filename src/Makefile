mainexec: main.cpp
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ main.cpp invest.pb.cc -o main_cpp `pkg-config --cflags --libs protobuf`