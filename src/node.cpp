#include "node.h"

unsigned int Node::counter = 0;

Node::Node(bool isFlt, bool isPrm)
         : serviceState(State::off), nodeId(counter++), view(0),
           isPrimary(isPrm), isFaulty(isFlt) {}

void Node::setServiceState(State serviceState){
    this->serviceState = serviceState;
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

void Node::print(){
    std::cout<<"Service state: "<<this->getServiceState() << ", Node id: "<< this->getNodeId() 
    << ", Current view: "<<this->getView() << ", Primary: "<<this->getIsPrimary() << ", Faulty: "
        << this->getIsFaulty()<<std::endl;
}

