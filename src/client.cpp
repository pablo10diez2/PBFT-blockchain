#include "client.h"

unsigned int Client::counter = 0;

Client::Client() : clientId(counter++) {}

unsigned int Client::getClientId(){
    return this->clientId;
}
        
void Client::print(){
    std::cout << "Client id: " << this->getClientId() << std::endl;
}

void Client::makeRequest(Node& primaryNode){
    primaryNode.getBuffer().push(100);
    
    std::cout << "Pushed from primary " << std::endl;
}
