#include "messageManager.h"

MessageManager::MessageManager(){

}

Request* MessageManager::createRequest(){
    this->messageMutex.lock();
    
    auto newMessagePtr = make_unique<Request>();
    this->messages.push_back( move(newMessagePtr) );

    this->messageMutex.unlock();

    return newMessagePtr.get();
}

Node* MessageManager::createNode(bool isFaulty, bool isPrimary){
    this->nodeMutex.lock();

    auto newNodePtr = make_unique<Node>(isFaulty, isPrimary);
    this->nodes.push_back( move(newNodePtr) );

    this->nodeMutex.unlock();

    return newNodePtr.get();
}
