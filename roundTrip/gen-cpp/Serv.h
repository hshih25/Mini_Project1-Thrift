/**
 * Autogenerated by Thrift Compiler (0.15.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "roundTrip_types.h"
#include <time.h>
#include <iostream>

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ServIf {
 public:
  virtual ~ServIf() {}
  virtual void send(std::vector<int64_t> & _return, const std::string& str1) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
  };

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const ::std::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  void send(std::vector<int64_t> & /* _return */, const std::string& /* str1 */) override {
    return;
  }
};

typedef struct _Serv_send_args__isset {
  _Serv_send_args__isset() : str1(false) {}
  bool str1 :1;
} _Serv_send_args__isset;

class Serv_send_args {
 public:

  Serv_send_args(const Serv_send_args&);
  Serv_send_args& operator=(const Serv_send_args&);
  Serv_send_args() noexcept
                 : str1() {
  }

  virtual ~Serv_send_args() noexcept;
  std::string str1;

  _Serv_send_args__isset __isset;

  void __set_str1(const std::string& val);

  bool operator == (const Serv_send_args & rhs) const
  {
    if (!(str1 == rhs.str1))
      return false;
    return true;
  }
  bool operator != (const Serv_send_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_send_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_send_pargs {
 public:


  virtual ~Serv_send_pargs() noexcept;
  const std::string* str1;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_send_result__isset {
  _Serv_send_result__isset() : success(false) {}
  bool success :1;
} _Serv_send_result__isset;

class Serv_send_result {
 public:

  Serv_send_result(const Serv_send_result&);
  Serv_send_result& operator=(const Serv_send_result&);
  Serv_send_result() noexcept {
  }

  virtual ~Serv_send_result() noexcept;
  std::vector<int64_t>  success;

  _Serv_send_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val);

  bool operator == (const Serv_send_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_send_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_send_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_send_presult__isset {
  _Serv_send_presult__isset() : success(false) {}
  bool success :1;
} _Serv_send_presult__isset;

class Serv_send_presult {
 public:


  virtual ~Serv_send_presult() noexcept;
  std::vector<int64_t> * success;

  _Serv_send_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void send(std::vector<int64_t> & _return, const std::string& str1) override;
  void send_send(const std::string& str1);
  void recv_send(std::vector<int64_t> & _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_send(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(::std::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["send"] = &ServProcessor::process_send;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::std::shared_ptr< ServIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<std::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<std::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(::std::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void send(std::vector<int64_t> & _return, const std::string& str1) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->send(_return, str1);
    }
    ifaces_[i]->send(_return, str1);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ServConcurrentClient : virtual public ServIf {
 public:
  ServConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  ServConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void send(std::vector<int64_t> & _return, const std::string& str1) override;
  int32_t send_send(const std::string& str1);
  void recv_send(std::vector<int64_t> & _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
