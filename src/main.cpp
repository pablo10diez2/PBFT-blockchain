#include <iostream>
#include <cassert>
#include <vector>

enum class MessageType{
    REQUEST, REPLY, PREPREPARE, PREPARE
};

struct Request{
    enum MessageType messageType = MessageType::REQUEST;
    bool operation;
    unsigned int requestTimestamp;
    unsigned int clientId;
};

struct Reply{
  enum MessageType messageType = MessageType::REPLY;
  int viewNumber;
  unsigned int requestTimestamp;
  unsigned int clientId;
  unsigned int nodeId;
  bool result;
};

struct PrePrepare{
     enum MessageType messageType = MessageType::PREPREPARE;
     unsigned int viewNumber;
     unsigned int seqNumber;
     size_t digest;
}:

struct Prepare{
    enum MessageType messageType = MessageType::PREPARE;
    unsigned int viewNumber;
    unsigned int seqNumber;
    size_t digest;
    unsigned int nodeId;
}

struct Node{
    bool isPrimary;
    unsigned int nodeId;
    std::vector<>
};

int main(){

    return 0;
}
