// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SipMessage.proto

#ifndef PROTOBUF_INCLUDED_SipMessage_2eproto
#define PROTOBUF_INCLUDED_SipMessage_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_SipMessage_2eproto 

namespace protobuf_SipMessage_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_SipMessage_2eproto
namespace acafela {
namespace sip {
class SIPMessage;
class SIPMessageDefaultTypeInternal;
extern SIPMessageDefaultTypeInternal _SIPMessage_default_instance_;
class Session;
class SessionDefaultTypeInternal;
extern SessionDefaultTypeInternal _Session_default_instance_;
class SessionInfo;
class SessionInfoDefaultTypeInternal;
extern SessionInfoDefaultTypeInternal _SessionInfo_default_instance_;
}  // namespace sip
}  // namespace acafela
namespace google {
namespace protobuf {
template<> ::acafela::sip::SIPMessage* Arena::CreateMaybeMessage<::acafela::sip::SIPMessage>(Arena*);
template<> ::acafela::sip::Session* Arena::CreateMaybeMessage<::acafela::sip::Session>(Arena*);
template<> ::acafela::sip::SessionInfo* Arena::CreateMaybeMessage<::acafela::sip::SessionInfo>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace acafela {
namespace sip {

enum Command {
  INVITE = 0,
  RINGING = 1,
  ACCEPTCALL = 2,
  MAKECALL = 3,
  OPENSESSION = 4,
  STARTVIDEO = 5,
  STOPVIDEO = 6,
  TERMINATE = 7,
  BYE = 8,
  REGISTER = 9,
  CLOSESESSION = 10,
  Command_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Command_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Command_IsValid(int value);
const Command Command_MIN = INVITE;
const Command Command_MAX = CLOSESESSION;
const int Command_ARRAYSIZE = Command_MAX + 1;

const ::google::protobuf::EnumDescriptor* Command_descriptor();
inline const ::std::string& Command_Name(Command value) {
  return ::google::protobuf::internal::NameOfEnum(
    Command_descriptor(), value);
}
inline bool Command_Parse(
    const ::std::string& name, Command* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Command>(
    Command_descriptor(), name, value);
}
enum SessionType {
  SENDAUDIO = 0,
  RECIEVEAUDIO = 1,
  SENDVIDEO = 2,
  RECIEVEVIDEO = 3,
  SessionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SessionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SessionType_IsValid(int value);
const SessionType SessionType_MIN = SENDAUDIO;
const SessionType SessionType_MAX = RECIEVEVIDEO;
const int SessionType_ARRAYSIZE = SessionType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SessionType_descriptor();
inline const ::std::string& SessionType_Name(SessionType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SessionType_descriptor(), value);
}
inline bool SessionType_Parse(
    const ::std::string& name, SessionType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SessionType>(
    SessionType_descriptor(), name, value);
}
// ===================================================================

class Session : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.sip.Session) */ {
 public:
  Session();
  virtual ~Session();

  Session(const Session& from);

  inline Session& operator=(const Session& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Session(Session&& from) noexcept
    : Session() {
    *this = ::std::move(from);
  }

  inline Session& operator=(Session&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Session& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Session* internal_default_instance() {
    return reinterpret_cast<const Session*>(
               &_Session_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Session* other);
  friend void swap(Session& a, Session& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Session* New() const final {
    return CreateMaybeMessage<Session>(NULL);
  }

  Session* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Session>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Session& from);
  void MergeFrom(const Session& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Session* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string ip = 2;
  void clear_ip();
  static const int kIpFieldNumber = 2;
  const ::std::string& ip() const;
  void set_ip(const ::std::string& value);
  #if LANG_CXX11
  void set_ip(::std::string&& value);
  #endif
  void set_ip(const char* value);
  void set_ip(const char* value, size_t size);
  ::std::string* mutable_ip();
  ::std::string* release_ip();
  void set_allocated_ip(::std::string* ip);

  // .acafela.sip.SessionType sessiontype = 1;
  void clear_sessiontype();
  static const int kSessiontypeFieldNumber = 1;
  ::acafela::sip::SessionType sessiontype() const;
  void set_sessiontype(::acafela::sip::SessionType value);

  // int32 port = 3;
  void clear_port();
  static const int kPortFieldNumber = 3;
  ::google::protobuf::int32 port() const;
  void set_port(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:acafela.sip.Session)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr ip_;
  int sessiontype_;
  ::google::protobuf::int32 port_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SipMessage_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SessionInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.sip.SessionInfo) */ {
 public:
  SessionInfo();
  virtual ~SessionInfo();

  SessionInfo(const SessionInfo& from);

  inline SessionInfo& operator=(const SessionInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SessionInfo(SessionInfo&& from) noexcept
    : SessionInfo() {
    *this = ::std::move(from);
  }

  inline SessionInfo& operator=(SessionInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SessionInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SessionInfo* internal_default_instance() {
    return reinterpret_cast<const SessionInfo*>(
               &_SessionInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SessionInfo* other);
  friend void swap(SessionInfo& a, SessionInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SessionInfo* New() const final {
    return CreateMaybeMessage<SessionInfo>(NULL);
  }

  SessionInfo* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SessionInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SessionInfo& from);
  void MergeFrom(const SessionInfo& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SessionInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .acafela.sip.Session sessions = 1;
  int sessions_size() const;
  void clear_sessions();
  static const int kSessionsFieldNumber = 1;
  ::acafela::sip::Session* mutable_sessions(int index);
  ::google::protobuf::RepeatedPtrField< ::acafela::sip::Session >*
      mutable_sessions();
  const ::acafela::sip::Session& sessions(int index) const;
  ::acafela::sip::Session* add_sessions();
  const ::google::protobuf::RepeatedPtrField< ::acafela::sip::Session >&
      sessions() const;

  // @@protoc_insertion_point(class_scope:acafela.sip.SessionInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::acafela::sip::Session > sessions_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SipMessage_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SIPMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.sip.SIPMessage) */ {
 public:
  SIPMessage();
  virtual ~SIPMessage();

  SIPMessage(const SIPMessage& from);

  inline SIPMessage& operator=(const SIPMessage& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SIPMessage(SIPMessage&& from) noexcept
    : SIPMessage() {
    *this = ::std::move(from);
  }

  inline SIPMessage& operator=(SIPMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SIPMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SIPMessage* internal_default_instance() {
    return reinterpret_cast<const SIPMessage*>(
               &_SIPMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(SIPMessage* other);
  friend void swap(SIPMessage& a, SIPMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SIPMessage* New() const final {
    return CreateMaybeMessage<SIPMessage>(NULL);
  }

  SIPMessage* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SIPMessage>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SIPMessage& from);
  void MergeFrom(const SIPMessage& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SIPMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string from = 4;
  void clear_from();
  static const int kFromFieldNumber = 4;
  const ::std::string& from() const;
  void set_from(const ::std::string& value);
  #if LANG_CXX11
  void set_from(::std::string&& value);
  #endif
  void set_from(const char* value);
  void set_from(const char* value, size_t size);
  ::std::string* mutable_from();
  ::std::string* release_from();
  void set_allocated_from(::std::string* from);

  // string to = 5;
  void clear_to();
  static const int kToFieldNumber = 5;
  const ::std::string& to() const;
  void set_to(const ::std::string& value);
  #if LANG_CXX11
  void set_to(::std::string&& value);
  #endif
  void set_to(const char* value);
  void set_to(const char* value, size_t size);
  ::std::string* mutable_to();
  ::std::string* release_to();
  void set_allocated_to(::std::string* to);

  // string sessionid = 6;
  void clear_sessionid();
  static const int kSessionidFieldNumber = 6;
  const ::std::string& sessionid() const;
  void set_sessionid(const ::std::string& value);
  #if LANG_CXX11
  void set_sessionid(::std::string&& value);
  #endif
  void set_sessionid(const char* value);
  void set_sessionid(const char* value, size_t size);
  ::std::string* mutable_sessionid();
  ::std::string* release_sessionid();
  void set_allocated_sessionid(::std::string* sessionid);

  // .acafela.sip.SessionInfo sessioninfo = 8;
  bool has_sessioninfo() const;
  void clear_sessioninfo();
  static const int kSessioninfoFieldNumber = 8;
  private:
  const ::acafela::sip::SessionInfo& _internal_sessioninfo() const;
  public:
  const ::acafela::sip::SessionInfo& sessioninfo() const;
  ::acafela::sip::SessionInfo* release_sessioninfo();
  ::acafela::sip::SessionInfo* mutable_sessioninfo();
  void set_allocated_sessioninfo(::acafela::sip::SessionInfo* sessioninfo);

  // .acafela.sip.Command cmd = 1;
  void clear_cmd();
  static const int kCmdFieldNumber = 1;
  ::acafela::sip::Command cmd() const;
  void set_cmd(::acafela::sip::Command value);

  // bool isACK = 2;
  void clear_isack();
  static const int kIsACKFieldNumber = 2;
  bool isack() const;
  void set_isack(bool value);

  // bool isVideoCall = 3;
  void clear_isvideocall();
  static const int kIsVideoCallFieldNumber = 3;
  bool isvideocall() const;
  void set_isvideocall(bool value);

  // int32 seq = 7;
  void clear_seq();
  static const int kSeqFieldNumber = 7;
  ::google::protobuf::int32 seq() const;
  void set_seq(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:acafela.sip.SIPMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr from_;
  ::google::protobuf::internal::ArenaStringPtr to_;
  ::google::protobuf::internal::ArenaStringPtr sessionid_;
  ::acafela::sip::SessionInfo* sessioninfo_;
  int cmd_;
  bool isack_;
  bool isvideocall_;
  ::google::protobuf::int32 seq_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SipMessage_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Session

// .acafela.sip.SessionType sessiontype = 1;
inline void Session::clear_sessiontype() {
  sessiontype_ = 0;
}
inline ::acafela::sip::SessionType Session::sessiontype() const {
  // @@protoc_insertion_point(field_get:acafela.sip.Session.sessiontype)
  return static_cast< ::acafela::sip::SessionType >(sessiontype_);
}
inline void Session::set_sessiontype(::acafela::sip::SessionType value) {
  
  sessiontype_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.Session.sessiontype)
}

// string ip = 2;
inline void Session::clear_ip() {
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Session::ip() const {
  // @@protoc_insertion_point(field_get:acafela.sip.Session.ip)
  return ip_.GetNoArena();
}
inline void Session::set_ip(const ::std::string& value) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.sip.Session.ip)
}
#if LANG_CXX11
inline void Session::set_ip(::std::string&& value) {
  
  ip_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.sip.Session.ip)
}
#endif
inline void Session::set_ip(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.sip.Session.ip)
}
inline void Session::set_ip(const char* value, size_t size) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.sip.Session.ip)
}
inline ::std::string* Session::mutable_ip() {
  
  // @@protoc_insertion_point(field_mutable:acafela.sip.Session.ip)
  return ip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Session::release_ip() {
  // @@protoc_insertion_point(field_release:acafela.sip.Session.ip)
  
  return ip_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Session::set_allocated_ip(::std::string* ip) {
  if (ip != NULL) {
    
  } else {
    
  }
  ip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ip);
  // @@protoc_insertion_point(field_set_allocated:acafela.sip.Session.ip)
}

// int32 port = 3;
inline void Session::clear_port() {
  port_ = 0;
}
inline ::google::protobuf::int32 Session::port() const {
  // @@protoc_insertion_point(field_get:acafela.sip.Session.port)
  return port_;
}
inline void Session::set_port(::google::protobuf::int32 value) {
  
  port_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.Session.port)
}

// -------------------------------------------------------------------

// SessionInfo

// repeated .acafela.sip.Session sessions = 1;
inline int SessionInfo::sessions_size() const {
  return sessions_.size();
}
inline void SessionInfo::clear_sessions() {
  sessions_.Clear();
}
inline ::acafela::sip::Session* SessionInfo::mutable_sessions(int index) {
  // @@protoc_insertion_point(field_mutable:acafela.sip.SessionInfo.sessions)
  return sessions_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::acafela::sip::Session >*
SessionInfo::mutable_sessions() {
  // @@protoc_insertion_point(field_mutable_list:acafela.sip.SessionInfo.sessions)
  return &sessions_;
}
inline const ::acafela::sip::Session& SessionInfo::sessions(int index) const {
  // @@protoc_insertion_point(field_get:acafela.sip.SessionInfo.sessions)
  return sessions_.Get(index);
}
inline ::acafela::sip::Session* SessionInfo::add_sessions() {
  // @@protoc_insertion_point(field_add:acafela.sip.SessionInfo.sessions)
  return sessions_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::acafela::sip::Session >&
SessionInfo::sessions() const {
  // @@protoc_insertion_point(field_list:acafela.sip.SessionInfo.sessions)
  return sessions_;
}

// -------------------------------------------------------------------

// SIPMessage

// .acafela.sip.Command cmd = 1;
inline void SIPMessage::clear_cmd() {
  cmd_ = 0;
}
inline ::acafela::sip::Command SIPMessage::cmd() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.cmd)
  return static_cast< ::acafela::sip::Command >(cmd_);
}
inline void SIPMessage::set_cmd(::acafela::sip::Command value) {
  
  cmd_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.cmd)
}

// bool isACK = 2;
inline void SIPMessage::clear_isack() {
  isack_ = false;
}
inline bool SIPMessage::isack() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.isACK)
  return isack_;
}
inline void SIPMessage::set_isack(bool value) {
  
  isack_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.isACK)
}

// bool isVideoCall = 3;
inline void SIPMessage::clear_isvideocall() {
  isvideocall_ = false;
}
inline bool SIPMessage::isvideocall() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.isVideoCall)
  return isvideocall_;
}
inline void SIPMessage::set_isvideocall(bool value) {
  
  isvideocall_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.isVideoCall)
}

// string from = 4;
inline void SIPMessage::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SIPMessage::from() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.from)
  return from_.GetNoArena();
}
inline void SIPMessage::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.from)
}
#if LANG_CXX11
inline void SIPMessage::set_from(::std::string&& value) {
  
  from_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.sip.SIPMessage.from)
}
#endif
inline void SIPMessage::set_from(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.sip.SIPMessage.from)
}
inline void SIPMessage::set_from(const char* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.sip.SIPMessage.from)
}
inline ::std::string* SIPMessage::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:acafela.sip.SIPMessage.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SIPMessage::release_from() {
  // @@protoc_insertion_point(field_release:acafela.sip.SIPMessage.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SIPMessage::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:acafela.sip.SIPMessage.from)
}

// string to = 5;
inline void SIPMessage::clear_to() {
  to_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SIPMessage::to() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.to)
  return to_.GetNoArena();
}
inline void SIPMessage::set_to(const ::std::string& value) {
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.to)
}
#if LANG_CXX11
inline void SIPMessage::set_to(::std::string&& value) {
  
  to_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.sip.SIPMessage.to)
}
#endif
inline void SIPMessage::set_to(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.sip.SIPMessage.to)
}
inline void SIPMessage::set_to(const char* value, size_t size) {
  
  to_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.sip.SIPMessage.to)
}
inline ::std::string* SIPMessage::mutable_to() {
  
  // @@protoc_insertion_point(field_mutable:acafela.sip.SIPMessage.to)
  return to_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SIPMessage::release_to() {
  // @@protoc_insertion_point(field_release:acafela.sip.SIPMessage.to)
  
  return to_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SIPMessage::set_allocated_to(::std::string* to) {
  if (to != NULL) {
    
  } else {
    
  }
  to_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), to);
  // @@protoc_insertion_point(field_set_allocated:acafela.sip.SIPMessage.to)
}

// string sessionid = 6;
inline void SIPMessage::clear_sessionid() {
  sessionid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SIPMessage::sessionid() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.sessionid)
  return sessionid_.GetNoArena();
}
inline void SIPMessage::set_sessionid(const ::std::string& value) {
  
  sessionid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.sessionid)
}
#if LANG_CXX11
inline void SIPMessage::set_sessionid(::std::string&& value) {
  
  sessionid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.sip.SIPMessage.sessionid)
}
#endif
inline void SIPMessage::set_sessionid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  sessionid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.sip.SIPMessage.sessionid)
}
inline void SIPMessage::set_sessionid(const char* value, size_t size) {
  
  sessionid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.sip.SIPMessage.sessionid)
}
inline ::std::string* SIPMessage::mutable_sessionid() {
  
  // @@protoc_insertion_point(field_mutable:acafela.sip.SIPMessage.sessionid)
  return sessionid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SIPMessage::release_sessionid() {
  // @@protoc_insertion_point(field_release:acafela.sip.SIPMessage.sessionid)
  
  return sessionid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SIPMessage::set_allocated_sessionid(::std::string* sessionid) {
  if (sessionid != NULL) {
    
  } else {
    
  }
  sessionid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sessionid);
  // @@protoc_insertion_point(field_set_allocated:acafela.sip.SIPMessage.sessionid)
}

// int32 seq = 7;
inline void SIPMessage::clear_seq() {
  seq_ = 0;
}
inline ::google::protobuf::int32 SIPMessage::seq() const {
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.seq)
  return seq_;
}
inline void SIPMessage::set_seq(::google::protobuf::int32 value) {
  
  seq_ = value;
  // @@protoc_insertion_point(field_set:acafela.sip.SIPMessage.seq)
}

// .acafela.sip.SessionInfo sessioninfo = 8;
inline bool SIPMessage::has_sessioninfo() const {
  return this != internal_default_instance() && sessioninfo_ != NULL;
}
inline void SIPMessage::clear_sessioninfo() {
  if (GetArenaNoVirtual() == NULL && sessioninfo_ != NULL) {
    delete sessioninfo_;
  }
  sessioninfo_ = NULL;
}
inline const ::acafela::sip::SessionInfo& SIPMessage::_internal_sessioninfo() const {
  return *sessioninfo_;
}
inline const ::acafela::sip::SessionInfo& SIPMessage::sessioninfo() const {
  const ::acafela::sip::SessionInfo* p = sessioninfo_;
  // @@protoc_insertion_point(field_get:acafela.sip.SIPMessage.sessioninfo)
  return p != NULL ? *p : *reinterpret_cast<const ::acafela::sip::SessionInfo*>(
      &::acafela::sip::_SessionInfo_default_instance_);
}
inline ::acafela::sip::SessionInfo* SIPMessage::release_sessioninfo() {
  // @@protoc_insertion_point(field_release:acafela.sip.SIPMessage.sessioninfo)
  
  ::acafela::sip::SessionInfo* temp = sessioninfo_;
  sessioninfo_ = NULL;
  return temp;
}
inline ::acafela::sip::SessionInfo* SIPMessage::mutable_sessioninfo() {
  
  if (sessioninfo_ == NULL) {
    auto* p = CreateMaybeMessage<::acafela::sip::SessionInfo>(GetArenaNoVirtual());
    sessioninfo_ = p;
  }
  // @@protoc_insertion_point(field_mutable:acafela.sip.SIPMessage.sessioninfo)
  return sessioninfo_;
}
inline void SIPMessage::set_allocated_sessioninfo(::acafela::sip::SessionInfo* sessioninfo) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete sessioninfo_;
  }
  if (sessioninfo) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      sessioninfo = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, sessioninfo, submessage_arena);
    }
    
  } else {
    
  }
  sessioninfo_ = sessioninfo;
  // @@protoc_insertion_point(field_set_allocated:acafela.sip.SIPMessage.sessioninfo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace sip
}  // namespace acafela

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::acafela::sip::Command> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::acafela::sip::Command>() {
  return ::acafela::sip::Command_descriptor();
}
template <> struct is_proto_enum< ::acafela::sip::SessionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::acafela::sip::SessionType>() {
  return ::acafela::sip::SessionType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_SipMessage_2eproto
