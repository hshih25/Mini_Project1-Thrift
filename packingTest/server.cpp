// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "./gen-cpp/Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class ServHandler : virtual public ServIf {
 public:
  ServHandler() {
    // Your initialization goes here
  }

  int32_t intPacking(const int32_t num1) {
    // Your implementation goes here
    printf("intPacking\n");
    return num1;
  }

  double doublePacking(const double num2) {
    // Your implementation goes here
    printf("doublePacking\n");
    return num2;
  }

  void stringPacking(std::string& _return, const std::string& str1) {
    // Your implementation goes here
    printf("stringPacking\n");
    _return = str1;
  }

  void structPacking(heavy& _return, const heavy& h) {
    // Your implementation goes here
    printf("structPacking\n");
    _return = h;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<ServHandler> handler(new ServHandler());
  ::std::shared_ptr<TProcessor> processor(new ServProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

