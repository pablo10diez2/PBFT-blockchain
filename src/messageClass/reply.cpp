#include "reply.h"

Reply::Reply(unsigned int nodeV, unsigned int timest, unsigned int cltId, unsigned int ndId, bool rst) : 
nodeView(nodeV), timestamp(timest), clientId(cltId), nodeId(ndId), result(rst) {}
    
void Reply::setNodeView(unsigned int nodeView){
    this->nodeView = nodeView;        
}
        
void Reply::setTimestamp(unsigned int timestamp){
    this->timestamp = timestamp;
}
        
void Reply::setClientId(unsigned int clientId){
    this->clientId = clientId;
}
        
void Reply::setNodeId(unsigned int nodeId){
    this->nodeId = nodeId;
}
        
bool Reply::setResult(bool result){
    return this->result;
}

unsigned int Reply::getNodeView(){
    return this->nodeView;
}

unsigned int Reply::getTimestamp(){
    return this->timestamp;
}
       
unsigned int Reply::getClientId(){
    return this->clientId;
}
        
unsigned int Reply::getNodeId(){
    return this->nodeId;
}
        
bool Reply::getResult(){
    return this->result;
}

        
void Reply::print(){
    std::cout << "MessageId: " << this->Message::getMessageId() << ", Type: Reply" << 
    ", Node view: " << this->getNodeView() << ", Timestamp: " << this->getTimestamp() 
    << ", Client id: " << this->getClientId() << ", Node id:" << this->getNodeId() << 
    ", Result: " << this->getResult() <<
    std::endl;
}

MsgType Reply::getType(){
    return MsgType::Type_Reply;
}
