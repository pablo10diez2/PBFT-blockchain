#include "control.h"
#include "nodes/node.h"

void startClient(Node* primaryNode){

    std::cout << "[CLIENT] Client started"<< std::endl;

    Client client{};
    unsigned int clientId = client.getClientId();

    Request request{};
    request.setOperation(true);
    request.setTimestamp( std::time(nullptr) );
    request.setClientId( clientId );
    
    Transaction transaction{};
    transaction.setMessage( &request );
    transaction.setSignature(777);
    
    std::cout << "[CLIENT] Client request made to primary" << std::endl;

    client.makeRequest(*primaryNode, transaction);
    
    waitResponse();
}

void waitResponse(){
    while(true){
    }
}

void handleTransaction(Transaction transaction, Node& node){
    Message* message = transaction.getMessage();
    MsgType type = message->getType();

    switch(type){
        
        case(MsgType::Type_Request):
            std::cout << "[HANDLER] Request transaction handling" << std::endl;
            //check signature...

            createPrePrepare(node);    
    }
}

void createPrePrepare(Node& node){
    if(node.getIsPrimary()){
        node.setNodePhase(prePrepare);

        PrePrepare prePrepare{};
    
        prePrepare.setViewNum(10);
        node.setSequenceNumber(&prePrepare);
        prePrepare.setMessageDigest(888);
        
        std::cout << "[PREPREPARE] PrePrepare created" << std::endl;
    }
}
