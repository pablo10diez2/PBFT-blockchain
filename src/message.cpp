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
    std::cout << "MessageId: " << this->Message::getMessageId() <<", Type: Request"<< ", Operation: "
    << this->getOperation() << ", Timestamp: " << this->getTimestamp() 
    << ", ClientId: " << this->getClientId() << std::endl;
}

PrePrepare::PrePrepare(unsigned int vNum, unsigned int seqNum, size_t msgDigest) : viewNum(vNum), sequenceNum(seqNum), messageDigest(msgDigest) {}
        
void PrePrepare::setViewNum(unsigned int viewNum){
    this->viewNum = viewNum;
}
        
void PrePrepare::setSequenceNum(unsigned int sequenceNum){
    this->sequenceNum = sequenceNum;
}
        
void PrePrepare::setMessageDigest(size_t messageDigest){
    this->messageDigest = messageDigest;
}

unsigned int PrePrepare::getViewNum(){
    return this->viewNum;
}
        
unsigned int PrePrepare::getSequenceNum(){
    return this->sequenceNum;
}
        
size_t PrePrepare::getMessageDigest(){
    return this->messageDigest;
}

void PrePrepare::print(){
    std::cout << "MessageId: " << this->Message::getMessageId() << ", Type: PrePrepare" << 
    ", View numbe: " << this->getViewNum() << ", Sequence number: " << this->getSequenceNum() 
    << ", Message digest: " << this->getMessageDigest() << std::endl;
}
