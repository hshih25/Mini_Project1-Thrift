// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "./gen-cpp/Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <time.h>
#include <iostream>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;


int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<TSocket> socket(new TSocket("localhost", port));
  ::std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  ::std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  std::string message = "Hello Server! sent from client";
  struct timespec start, end;
  ServClient client(protocol);
  transport->open();
  std::cout << "One Machine\n";
  for (int i = 0; i < 20; ++i) {
  	clock_gettime(CLOCK_REALTIME, &start);
 	client.send(message);  
  	clock_gettime(CLOCK_REALTIME, &end);
  	std::cout << end.tv_nsec - start.tv_nsec << "\n";
  }

  transport->close();
  

  return 0;
}
