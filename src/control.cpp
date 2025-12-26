#include "control.h"

void startClient(Node* primaryNode, Request* request){
    Client client{};

    //Hacer que el request se construya desde el cliente para el timestamp y client ID

    Transaction transaction{request, 100};

    client.makeRequest(*primaryNode, transaction);
}   
