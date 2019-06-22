// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserAdmin.proto

#ifndef PROTOBUF_INCLUDED_UserAdmin_2eproto
#define PROTOBUF_INCLUDED_UserAdmin_2eproto

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
#include <google/protobuf/unknown_field_set.h>
#include "Common.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_UserAdmin_2eproto 

namespace protobuf_UserAdmin_2eproto {
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
}  // namespace protobuf_UserAdmin_2eproto
namespace acafela {
namespace rpc {
class Email;
class EmailDefaultTypeInternal;
extern EmailDefaultTypeInternal _Email_default_instance_;
class UserInfo;
class UserInfoDefaultTypeInternal;
extern UserInfoDefaultTypeInternal _UserInfo_default_instance_;
class UserInfoList;
class UserInfoListDefaultTypeInternal;
extern UserInfoListDefaultTypeInternal _UserInfoList_default_instance_;
}  // namespace rpc
}  // namespace acafela
namespace google {
namespace protobuf {
template<> ::acafela::rpc::Email* Arena::CreateMaybeMessage<::acafela::rpc::Email>(Arena*);
template<> ::acafela::rpc::UserInfo* Arena::CreateMaybeMessage<::acafela::rpc::UserInfo>(Arena*);
template<> ::acafela::rpc::UserInfoList* Arena::CreateMaybeMessage<::acafela::rpc::UserInfoList>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace acafela {
namespace rpc {

// ===================================================================

class UserInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.rpc.UserInfo) */ {
 public:
  UserInfo();
  virtual ~UserInfo();

  UserInfo(const UserInfo& from);

  inline UserInfo& operator=(const UserInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  UserInfo(UserInfo&& from) noexcept
    : UserInfo() {
    *this = ::std::move(from);
  }

  inline UserInfo& operator=(UserInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserInfo* internal_default_instance() {
    return reinterpret_cast<const UserInfo*>(
               &_UserInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(UserInfo* other);
  friend void swap(UserInfo& a, UserInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UserInfo* New() const final {
    return CreateMaybeMessage<UserInfo>(NULL);
  }

  UserInfo* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<UserInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const UserInfo& from);
  void MergeFrom(const UserInfo& from);
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
  void InternalSwap(UserInfo* other);
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

  // string email = 1;
  void clear_email();
  static const int kEmailFieldNumber = 1;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // string phone_number = 2;
  void clear_phone_number();
  static const int kPhoneNumberFieldNumber = 2;
  const ::std::string& phone_number() const;
  void set_phone_number(const ::std::string& value);
  #if LANG_CXX11
  void set_phone_number(::std::string&& value);
  #endif
  void set_phone_number(const char* value);
  void set_phone_number(const char* value, size_t size);
  ::std::string* mutable_phone_number();
  ::std::string* release_phone_number();
  void set_allocated_phone_number(::std::string* phone_number);

  // bool enabled = 3;
  void clear_enabled();
  static const int kEnabledFieldNumber = 3;
  bool enabled() const;
  void set_enabled(bool value);

  // @@protoc_insertion_point(class_scope:acafela.rpc.UserInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::internal::ArenaStringPtr phone_number_;
  bool enabled_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_UserAdmin_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class UserInfoList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.rpc.UserInfoList) */ {
 public:
  UserInfoList();
  virtual ~UserInfoList();

  UserInfoList(const UserInfoList& from);

  inline UserInfoList& operator=(const UserInfoList& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  UserInfoList(UserInfoList&& from) noexcept
    : UserInfoList() {
    *this = ::std::move(from);
  }

  inline UserInfoList& operator=(UserInfoList&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfoList& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserInfoList* internal_default_instance() {
    return reinterpret_cast<const UserInfoList*>(
               &_UserInfoList_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(UserInfoList* other);
  friend void swap(UserInfoList& a, UserInfoList& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UserInfoList* New() const final {
    return CreateMaybeMessage<UserInfoList>(NULL);
  }

  UserInfoList* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<UserInfoList>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const UserInfoList& from);
  void MergeFrom(const UserInfoList& from);
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
  void InternalSwap(UserInfoList* other);
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

  // repeated .acafela.rpc.UserInfo user_info = 1;
  int user_info_size() const;
  void clear_user_info();
  static const int kUserInfoFieldNumber = 1;
  ::acafela::rpc::UserInfo* mutable_user_info(int index);
  ::google::protobuf::RepeatedPtrField< ::acafela::rpc::UserInfo >*
      mutable_user_info();
  const ::acafela::rpc::UserInfo& user_info(int index) const;
  ::acafela::rpc::UserInfo* add_user_info();
  const ::google::protobuf::RepeatedPtrField< ::acafela::rpc::UserInfo >&
      user_info() const;

  // @@protoc_insertion_point(class_scope:acafela.rpc.UserInfoList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::acafela::rpc::UserInfo > user_info_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_UserAdmin_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Email : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:acafela.rpc.Email) */ {
 public:
  Email();
  virtual ~Email();

  Email(const Email& from);

  inline Email& operator=(const Email& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Email(Email&& from) noexcept
    : Email() {
    *this = ::std::move(from);
  }

  inline Email& operator=(Email&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Email& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Email* internal_default_instance() {
    return reinterpret_cast<const Email*>(
               &_Email_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Email* other);
  friend void swap(Email& a, Email& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Email* New() const final {
    return CreateMaybeMessage<Email>(NULL);
  }

  Email* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Email>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Email& from);
  void MergeFrom(const Email& from);
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
  void InternalSwap(Email* other);
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

  // string email = 1;
  void clear_email();
  static const int kEmailFieldNumber = 1;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // @@protoc_insertion_point(class_scope:acafela.rpc.Email)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_UserAdmin_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserInfo

// string email = 1;
inline void UserInfo::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserInfo::email() const {
  // @@protoc_insertion_point(field_get:acafela.rpc.UserInfo.email)
  return email_.GetNoArena();
}
inline void UserInfo::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.rpc.UserInfo.email)
}
#if LANG_CXX11
inline void UserInfo::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.rpc.UserInfo.email)
}
#endif
inline void UserInfo::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.rpc.UserInfo.email)
}
inline void UserInfo::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.rpc.UserInfo.email)
}
inline ::std::string* UserInfo::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:acafela.rpc.UserInfo.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserInfo::release_email() {
  // @@protoc_insertion_point(field_release:acafela.rpc.UserInfo.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:acafela.rpc.UserInfo.email)
}

// string phone_number = 2;
inline void UserInfo::clear_phone_number() {
  phone_number_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserInfo::phone_number() const {
  // @@protoc_insertion_point(field_get:acafela.rpc.UserInfo.phone_number)
  return phone_number_.GetNoArena();
}
inline void UserInfo::set_phone_number(const ::std::string& value) {
  
  phone_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.rpc.UserInfo.phone_number)
}
#if LANG_CXX11
inline void UserInfo::set_phone_number(::std::string&& value) {
  
  phone_number_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.rpc.UserInfo.phone_number)
}
#endif
inline void UserInfo::set_phone_number(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  phone_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.rpc.UserInfo.phone_number)
}
inline void UserInfo::set_phone_number(const char* value, size_t size) {
  
  phone_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.rpc.UserInfo.phone_number)
}
inline ::std::string* UserInfo::mutable_phone_number() {
  
  // @@protoc_insertion_point(field_mutable:acafela.rpc.UserInfo.phone_number)
  return phone_number_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserInfo::release_phone_number() {
  // @@protoc_insertion_point(field_release:acafela.rpc.UserInfo.phone_number)
  
  return phone_number_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_phone_number(::std::string* phone_number) {
  if (phone_number != NULL) {
    
  } else {
    
  }
  phone_number_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), phone_number);
  // @@protoc_insertion_point(field_set_allocated:acafela.rpc.UserInfo.phone_number)
}

// bool enabled = 3;
inline void UserInfo::clear_enabled() {
  enabled_ = false;
}
inline bool UserInfo::enabled() const {
  // @@protoc_insertion_point(field_get:acafela.rpc.UserInfo.enabled)
  return enabled_;
}
inline void UserInfo::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:acafela.rpc.UserInfo.enabled)
}

// -------------------------------------------------------------------

// UserInfoList

// repeated .acafela.rpc.UserInfo user_info = 1;
inline int UserInfoList::user_info_size() const {
  return user_info_.size();
}
inline void UserInfoList::clear_user_info() {
  user_info_.Clear();
}
inline ::acafela::rpc::UserInfo* UserInfoList::mutable_user_info(int index) {
  // @@protoc_insertion_point(field_mutable:acafela.rpc.UserInfoList.user_info)
  return user_info_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::acafela::rpc::UserInfo >*
UserInfoList::mutable_user_info() {
  // @@protoc_insertion_point(field_mutable_list:acafela.rpc.UserInfoList.user_info)
  return &user_info_;
}
inline const ::acafela::rpc::UserInfo& UserInfoList::user_info(int index) const {
  // @@protoc_insertion_point(field_get:acafela.rpc.UserInfoList.user_info)
  return user_info_.Get(index);
}
inline ::acafela::rpc::UserInfo* UserInfoList::add_user_info() {
  // @@protoc_insertion_point(field_add:acafela.rpc.UserInfoList.user_info)
  return user_info_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::acafela::rpc::UserInfo >&
UserInfoList::user_info() const {
  // @@protoc_insertion_point(field_list:acafela.rpc.UserInfoList.user_info)
  return user_info_;
}

// -------------------------------------------------------------------

// Email

// string email = 1;
inline void Email::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Email::email() const {
  // @@protoc_insertion_point(field_get:acafela.rpc.Email.email)
  return email_.GetNoArena();
}
inline void Email::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:acafela.rpc.Email.email)
}
#if LANG_CXX11
inline void Email::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:acafela.rpc.Email.email)
}
#endif
inline void Email::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:acafela.rpc.Email.email)
}
inline void Email::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:acafela.rpc.Email.email)
}
inline ::std::string* Email::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:acafela.rpc.Email.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Email::release_email() {
  // @@protoc_insertion_point(field_release:acafela.rpc.Email.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Email::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:acafela.rpc.Email.email)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace rpc
}  // namespace acafela

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_UserAdmin_2eproto