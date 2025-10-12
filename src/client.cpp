#include "client.h"

unsigned int Client::counter = 0;

Client::Client() : clientId(counter++) {}

unsigned int Client::getClientId(){
    return this->clientId;
}
        
unsigned int Client::getBufferSize(){
    return this->clientBuffer.size();
}
           
void Client::addRequest(Request request){
    this->clientBuffer.push_back(request);
}
        
void Client::print(){
    std::cout << "Client id: " << this->getClientId() << std::endl;
    
    for(int i=0; i < clientBuffer.size(); ++i){
        clientBuffer[i].print();
    }
}
