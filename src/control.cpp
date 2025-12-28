#include "control.h"

void startClient(Node* primaryNode){
    Client client{};
    unsigned int clientId = client.getClientId();

    Request request{};
    request.setOperation(1);
    request.setTimestamp( std::time(nullptr) );
    request.setClientId( clientId );
    
    Transaction transaction{};
    transaction.setMessage( &request );
    transaction.setSignature(777);

    client.makeRequest(*primaryNode, transaction);
}

