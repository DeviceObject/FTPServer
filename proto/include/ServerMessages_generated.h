// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SERVERMESSAGES_FTP_MESSAGES_SERVER_H_
#define FLATBUFFERS_GENERATED_SERVERMESSAGES_FTP_MESSAGES_SERVER_H_

#include "flatbuffers/flatbuffers.h"

namespace FTP {
namespace Messages {
namespace Server {

struct ConnectionReply;

struct ServerMessage;

enum Message {
  Message_NONE = 0,
  Message_ConnectionReply = 1,
  Message_MIN = Message_NONE,
  Message_MAX = Message_ConnectionReply
};

inline const char **EnumNamesMessage() {
  static const char *names[] = {
    "NONE",
    "ConnectionReply",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessage(Message e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesMessage()[index];
}

template<typename T> struct MessageTraits {
  static const Message enum_value = Message_NONE;
};

template<> struct MessageTraits<ConnectionReply> {
  static const Message enum_value = Message_ConnectionReply;
};

bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type);
bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

enum Status {
  Status_Ok = 1,
  Status_Duplicate = 2,
  Status_MIN = Status_Ok,
  Status_MAX = Status_Duplicate
};

inline const char **EnumNamesStatus() {
  static const char *names[] = {
    "Ok",
    "Duplicate",
    nullptr
  };
  return names;
}

inline const char *EnumNameStatus(Status e) {
  const size_t index = static_cast<int>(e) - static_cast<int>(Status_Ok);
  return EnumNamesStatus()[index];
}

struct ConnectionReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CLIENT_TOKEN = 4
  };
  const flatbuffers::String *client_token() const {
    return GetPointer<const flatbuffers::String *>(VT_CLIENT_TOKEN);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_CLIENT_TOKEN) &&
           verifier.Verify(client_token()) &&
           verifier.EndTable();
  }
};

struct ConnectionReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_client_token(flatbuffers::Offset<flatbuffers::String> client_token) {
    fbb_.AddOffset(ConnectionReply::VT_CLIENT_TOKEN, client_token);
  }
  ConnectionReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConnectionReplyBuilder &operator=(const ConnectionReplyBuilder &);
  flatbuffers::Offset<ConnectionReply> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ConnectionReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ConnectionReply> CreateConnectionReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> client_token = 0) {
  ConnectionReplyBuilder builder_(_fbb);
  builder_.add_client_token(client_token);
  return builder_.Finish();
}

inline flatbuffers::Offset<ConnectionReply> CreateConnectionReplyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *client_token = nullptr) {
  return CreateConnectionReply(
      _fbb,
      client_token ? _fbb.CreateString(client_token) : 0);
}

struct ServerMessage FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_STATUS = 4,
    VT_MESSAGE_TYPE = 6,
    VT_MESSAGE = 8
  };
  Status status() const {
    return static_cast<Status>(GetField<uint8_t>(VT_STATUS, 1));
  }
  Message message_type() const {
    return static_cast<Message>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           VerifyMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

struct ServerMessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(Status status) {
    fbb_.AddElement<uint8_t>(ServerMessage::VT_STATUS, static_cast<uint8_t>(status), 1);
  }
  void add_message_type(Message message_type) {
    fbb_.AddElement<uint8_t>(ServerMessage::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(ServerMessage::VT_MESSAGE, message);
  }
  ServerMessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ServerMessageBuilder &operator=(const ServerMessageBuilder &);
  flatbuffers::Offset<ServerMessage> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<ServerMessage>(end);
    return o;
  }
};

inline flatbuffers::Offset<ServerMessage> CreateServerMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    Status status = Status_Ok,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  ServerMessageBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  builder_.add_status(status);
  return builder_.Finish();
}

inline bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type) {
  switch (type) {
    case Message_NONE: {
      return true;
    }
    case Message_ConnectionReply: {
      auto ptr = reinterpret_cast<const ConnectionReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessage(
        verifier,  values->Get(i), types->GetEnum<Message>(i))) {
      return false;
    }
  }
  return true;
}

inline const FTP::Messages::Server::ServerMessage *GetServerMessage(const void *buf) {
  return flatbuffers::GetRoot<FTP::Messages::Server::ServerMessage>(buf);
}

inline bool VerifyServerMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<FTP::Messages::Server::ServerMessage>(nullptr);
}

inline void FinishServerMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<FTP::Messages::Server::ServerMessage> root) {
  fbb.Finish(root);
}

}  // namespace Server
}  // namespace Messages
}  // namespace FTP

#endif  // FLATBUFFERS_GENERATED_SERVERMESSAGES_FTP_MESSAGES_SERVER_H_