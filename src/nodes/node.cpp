#include <string>
#include <unistd.h>

#include "node.h"

unsigned int Node::counter = 0;
unsigned int Node::sequenceNumber = 0;

Node::Node(bool isFlt, bool isPrm)
         : nodePhase(Phase::off), nodeId(counter++), view(0),
           isPrimary(isPrm), isFaulty(isFlt) {}

void Node::setNodePhase(Phase phase){
    this->nodePhase = phase;
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

Phase Node::getNodePhase(){
    return this->nodePhase;
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

std::queue<Transaction>& Node::getBuffer(){
    return this->buffer;
}

std::mutex& Node::getMutex(){
    return this->mutex;
}

void Node::print(){
    std::cout<<"Service state: "<<this->getNodePhase() << ", Node id: "<< this->getNodeId() 
    << ", Current view: "<<this->getView() << ", Primary: "<<this->getIsPrimary() << ", Faulty: "
        << this->getIsFaulty()<<std::endl;
}

void Node::setSequenceNumber(PrePrepare* prePrepare){
    if(isPrimary){
        this->sequenceNumber++;
        prePrepare->setSequenceNum(this->sequenceNumber);
    }
}

void Node::bufferRead(){
    while(true){
        sleep(1);
        this->mutex.lock();

        if( !this->buffer.empty() ){
            Transaction t = this->buffer.front();
            
            std::cout << "From node: ";
            print();
            t.getMessage()->print();
            std::cout << "-----------------------" << std::endl;

            this->handleTransaction(t);

            buffer.pop();

            this->mutex.unlock();
            break;
        }

        this->mutex.unlock();
    }
}

void Node::insertBuffer(Transaction transaction){
    this->buffer.push(transaction);
}

void Node::handleTransaction(Transaction transaction){
    Message* message = transaction.getMessage();
    MsgType type = message->getType();

    switch(type){
        
        case(MsgType::Type_Request):
            //check signature...

            createPrePrepare();    
    }
}

void Node::createPrePrepare(){
    if(isPrimary){
        setNodePhase(prePrepare);

        PrePrepare prePrepare{};
    
        prePrepare.setViewNum(10);
        setSequenceNumber(&prePrepare);
        prePrepare.setMessageDigest(888);

        prePrepare.print();
    }
}
