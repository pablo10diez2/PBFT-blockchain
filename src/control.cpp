#include "control.h"

void startClient(Node* primaryNode){
    Client client{};

    //Hacer que el request se construya desde el cliente para el timestamp y client ID
    Request request{0,0,0};

    Transaction transaction{&request, 100};

    client.makeRequest(*primaryNode, transaction);
}   
