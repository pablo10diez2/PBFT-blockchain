#include "message.h"

unsigned int Message::counter=0;

Message::Message() : messageId(counter++) {}

int Message::getMessageId(){
    return this->messageId;
}

Request::Request(bool op, unsigned int ts, unsigned int cId) : operation(op), timestamp(ts), clientId(cId) {}
        
void Request::setOperation(bool operation){
    this->operation = operation;
}
        
void Request::setTimestamp(unsigned int timestamp){
    this->timestamp = timestamp;
}
        
void Request::setClientId(unsigned int clientId){
    this->clientId = clientId;
}

bool Request::getOperation(){
    return this->operation;
}
        
unsigned int Request::getTimestamp(){
    return this->timestamp;
}
        
unsigned int Request::getClientId(){
    return this->clientId;
}

void Request::print(){
    std::cout << "Type: Request"<< ", Operation: " << this->getOperation() << ", Timestamp: " <<
        this->getTimestamp() << ", ClientId: " << this->getClientId() << std::endl;
}
