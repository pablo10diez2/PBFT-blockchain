#include <iostream>
#include <cassert>

enum class MessageType{
    REQUEST
};

struct Request{
    enum MessageType messageType = MessageType::REQUEST;
};

int main(){
    Request r1 = {};
    Request r2 = {};
    
    assert(r1.messageType ==r2.messageType);

    return 0;
}
