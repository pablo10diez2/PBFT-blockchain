#include "request.h"

Request::Request(bool op, unsigned int ts, unsigned int cId) : operation(op), timestamp(ts), clientId(cId) {}
  
Request::Request() : operation(0), timestamp( time(nullptr) ), clientId(0) {}

void Request::setOperation(bool operation){
    this->operation = operation;
}
        
void Request::setTimestamp(std::time_t timestamp){
    this->timestamp = timestamp;
}
        
void Request::setClientId(unsigned int clientId){
    this->clientId = clientId;
}

bool Request::getOperation(){
    return this->operation;
}
        
std::time_t Request::getTimestamp(){
    return this->timestamp;
}
        
unsigned int Request::getClientId(){
    return this->clientId;
}

void Request::print(){
    std::cout << "MessageId: " << this->Message::getMessageId() <<", Type: Request"<< ", Operation: "
    << this->getOperation() << ", Timestamp: " << this->getTimestamp() 
    << ", ClientId: " << this->getClientId() << std::endl;
}

MsgType Request::getType(){
    return MsgType::Type_Request;
}
