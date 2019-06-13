// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: CryptoKey.proto
#ifndef GRPC_CryptoKey_2eproto__INCLUDED
#define GRPC_CryptoKey_2eproto__INCLUDED

#include "CryptoKey.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace acafela {
namespace rpc {

class CryptoKey final {
 public:
  static constexpr char const* service_full_name() {
    return "acafela.rpc.CryptoKey";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status request(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::acafela::rpc::Key* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>> Asyncrequest(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>>(AsyncrequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>> PrepareAsyncrequest(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>>(PrepareAsyncrequestRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void request(::grpc::ClientContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>* AsyncrequestRaw(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::acafela::rpc::Key>* PrepareAsyncrequestRaw(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status request(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::acafela::rpc::Key* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>> Asyncrequest(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>>(AsyncrequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>> PrepareAsyncrequest(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>>(PrepareAsyncrequestRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void request(::grpc::ClientContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>* AsyncrequestRaw(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::acafela::rpc::Key>* PrepareAsyncrequestRaw(::grpc::ClientContext* context, const ::acafela::rpc::Session& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_request_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status request(::grpc::ServerContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_request : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_request() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_request() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status request(::grpc::ServerContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestrequest(::grpc::ServerContext* context, ::acafela::rpc::Session* request, ::grpc::ServerAsyncResponseWriter< ::acafela::rpc::Key>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_request<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_request : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_request() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_request() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status request(::grpc::ServerContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_request : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_request() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_request() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status request(::grpc::ServerContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestrequest(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_request : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_request() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::acafela::rpc::Session, ::acafela::rpc::Key>(std::bind(&WithStreamedUnaryMethod_request<BaseClass>::Streamedrequest, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_request() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status request(::grpc::ServerContext* context, const ::acafela::rpc::Session* request, ::acafela::rpc::Key* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedrequest(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::acafela::rpc::Session,::acafela::rpc::Key>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_request<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_request<Service > StreamedService;
};

}  // namespace rpc
}  // namespace acafela


#endif  // GRPC_CryptoKey_2eproto__INCLUDED