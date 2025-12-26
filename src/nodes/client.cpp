#include "client.h"
#include <unistd.h>

unsigned int Client::counter = 0;

Client::Client() : clientId(counter++) {}

unsigned int Client::getClientId(){
    return this->clientId;
}
        
void Client::print(){
    std::cout << "Client id: " << this->getClientId() << std::endl;
}

void Client::makeRequest(Node& primaryNode, Transaction transaction){
    primaryNode.getMutex().lock();
    std::cout << "locked" << std::endl;

    primaryNode.getBuffer().push(transaction);

    primaryNode.getMutex().unlock();
    std::cout << "unlocked" << std::endl;
}
