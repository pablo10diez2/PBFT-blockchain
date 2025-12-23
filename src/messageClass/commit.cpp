#include "commit.h"

Commit::Commit(unsigned int vNum, unsigned int seqNum, size_t msgDigest, unsigned int nId) : viewNum(vNum), sequenceNum(seqNum), messageDigest(msgDigest), nodeId(nId) {}
            
void Commit::setViewNum(unsigned int viewNum){
    this->viewNum = viewNum;
}

void Commit::setSequenceNum(unsigned int sequenceNum){
    this->sequenceNum = sequenceNum;
}

void Commit::setMessageDigest(size_t messageDigest){
    this->messageDigest = messageDigest;
}
void Commit::setNodeId(unsigned int nodeId){
    this->nodeId = nodeId;
}

unsigned int Commit::getViewNum(){
    return this->viewNum;
}

unsigned int Commit::getSequenceNum(){
    return this->sequenceNum;
}
            
size_t Commit::getMessageDigest(){
    return this->messageDigest;
}
            
unsigned int Commit::getNodeId(){
    return this->nodeId;
}

void Commit::print(){
    std::cout << "MessageId: " << this->Message::getMessageId() << ", Type: Commit" << 
    ", View numbe: " << this->getViewNum() << ", Sequence number: " << this->getSequenceNum() 
    << ", Message digest: " << this->getMessageDigest() << ", Node id:" << this->getNodeId() << std::endl;
}

MsgType Commit::getType(){
    return MsgType::Type_Commit;
};
