// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "./gen-cpp/Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;


int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<TSocket> socket(new TSocket("localhost", port));
  ::std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  ::std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  ServClient client(protocol);
  transport->open();
  int sample1 = 123124;
  double num1 = 123.1231;
  std::string str1 = "abcde";
  struct heavy h;
  struct another ano;
  ano.num1 = 123123;
  ano.num2 = 11111;
  ano.str1 = "abved";
  ano.num3 = 123.11251;
  h.num1 = 123123;
  h.num2 = 213.123;
  h.str1 = "abddsda";
  h.bool1 = false;
  h.an = ano;
  
  std::cout << "Int packing time(nanosec)\n";
  for (int i = 0; i < 20; ++i) {
  	client.intPacking(sample1);
  }  
  std::cout << "Double packing time(nanosec)\n";
  for (int i = 0; i < 20; ++i) {
	client.doublePacking(num1);
  } 
  std::cout << "String packing time(nanosec)\n";
  for (int i = 0; i < 20; ++i) {
	client.stringPacking(str1);
  }
  std::cout << "Stucture packing time(nanosec)\n";
  for (int i = 0; i < 20; ++i) {
	client.structPacking(h);
  }

  transport->close();
  

  return 0;
}

