#include "control.h"

void startClient(Node* primaryNode, Request* request){
    Client client{};

    Transaction transaction{request, 100};

    client.makeRequest(*primaryNode, transaction);
}   
