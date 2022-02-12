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
  //::std::shared_ptr<TSocket> socket(new TSocket("10.10.1.1", port));
 
  ::std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  ::std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  std::string message = "Hello Server! sent from clientHello Server! sent from clientHello Server! sent from clientHello ServHello Server! sent from c";
  std::string base = message + message;
  base += base;
  base += base;
  message = base;
  struct timespec start;
  ServClient client(protocol);
  transport->open();
  std::cout << "Message size     bandwidth(mb/s)\n";  
  for (int i = 0; i < 20; ++i) {
	std::vector<int64_t> time;
  	clock_gettime(CLOCK_MONOTONIC, &start);
	int64_t sec = start.tv_sec;
	int64_t nsec = start.tv_nsec;

	int size = message.size();
 	client.send(time, message);  
  
  std::cout << size << "     ";
      //std::cout << size * 1000000l << " " << time[1] - nsec + ( time[0] - sec ) * 1000000000L << " \n";
  std::cout << size * 1000000l / (time[1] - nsec + (time[0] - sec) * 1000000000L) << "\n";
  
 
	message += message;
  }

  transport->close();
  

  return 0;
}

