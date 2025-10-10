#include "node.h"

Node::Node(State serviceState, unsigned int nodeId, unsigned int view)
         : serviceState(serviceState), nodeId(nodeId), view(view),
           isPrimary(false), isFaulty(false) {}


void Node::setServiceState(State serviceState){
    this->serviceState = serviceState;
}

void Node::setNodeId(unsigned int nodeId){
    this->nodeId = nodeId;
}

void Node::setView(unsigned int view){
    this->view = view;
}
        
void Node::setIsPrimary(bool primary){
    this->isPrimary = primary;
}
        
void Node::setIsFaulty(bool faulty){
    this->isFaulty = faulty;
}

State Node::getServiceState(){
    return this->serviceState;
}
        
unsigned int Node::getNodeId(){
    return this->nodeId;
}
        
unsigned int Node::getView(){
    return this->view;
}
        
bool Node::getIsPrimary(){
    return this->isPrimary;
}
        
bool Node::getIsFaulty(){
    return this->isFaulty;
}
