TYPE = gen-cpp/bandwidth_types
CXX = g++
FLAGS = -g -o
THRIFT = -lthrift
SERV = gen-cpp/Serv


all: build

build: 
	${CXX} $(FLAGS) server ${THRIFT} ${SERV}.cpp ${TYPE}.h server.cpp ${THRIFT}
	${CXX} ${FLAGS} client ${THRIFT} client.cpp ${SERV}.cpp ${TYPE}.h ${THRIFT}
