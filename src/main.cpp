#include <iostream>
#include <cassert>

enum class MessageType{
    REQUEST
};

struct Request{
    enum MessageType messageType = MessageType::REQUEST;
    bool operation;
    unsigned int timestamp;
    unsigned short clientId;
};

int main(){
    Request r1 = {};

    return 0;
}
