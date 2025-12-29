#include "preprepare.h"

PrePrepare::PrePrepare() : viewNum(0), sequenceNum(0), messageDigest(0) {}

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
    ", View number: " << this->getViewNum() << ", Sequence number: " << this->getSequenceNum() 
    << ", Message digest: " << this->getMessageDigest() << std::endl;
}

MsgType PrePrepare::getType(){
    return MsgType::Type_PrePrepare;
}


