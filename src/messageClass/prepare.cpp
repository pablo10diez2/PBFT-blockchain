#include "prepare.h"

Prepare::Prepare(unsigned int vNum, unsigned int seqNum, size_t msgDigest, unsigned int nId) : viewNum(vNum), sequenceNum(seqNum), messageDigest(msgDigest), nodeId(nId) {}
            
void Prepare::setViewNum(unsigned int viewNum){
    this->viewNum = viewNum;
}

void Prepare::setSequenceNum(unsigned int sequenceNum){
    this->sequenceNum = sequenceNum;
}

void Prepare::setMessageDigest(size_t messageDigest){
    this->messageDigest = messageDigest;
}
void Prepare::setNodeId(unsigned int nodeId){
    this->nodeId = nodeId;
}

unsigned int Prepare::getViewNum(){
    return this->viewNum;
}

unsigned int Prepare::getSequenceNum(){
    return this->sequenceNum;
}
            
size_t Prepare::getMessageDigest(){
    return this->messageDigest;
}
            
unsigned int Prepare::getNodeId(){
    return this->nodeId;
}

void Prepare::print(){
    std::cout << "MessageId: " << this->Message::getMessageId() << ", Type: Prepare" << 
    ", View numbe: " << this->getViewNum() << ", Sequence number: " << this->getSequenceNum() 
    << ", Message digest: " << this->getMessageDigest() << ", Node id:" << this->getNodeId() << std::endl;
}

MsgType Prepare::getType(){
    return MsgType::Type_Prepare;
}
