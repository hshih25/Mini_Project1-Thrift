all: build

build: gen-cpp/Serv.cpp gen-cpp/packing_types.cpp server.cpp client.cpp
	g++ -g -o server -lthrift gen-cpp/Serv.cpp gen-cpp/packing_types.cpp server.cpp -lthrift
	g++ -g -o client -lthrift client.cpp gen-cpp/Serv.cpp gen-cpp/packing_types.cpp -lthrift
	
