#include "control.h"
#include "nodes/node.h"

using namespace std;

vector<unique_ptr<Node>>* globalNodes;

void startClient(Node* primaryNode, vector<unique_ptr<Node>> nodes){
    globalNodes = &nodes;

    cout << "[CLIENT] Client started"<< endl;

    Client client{};
    unsigned int clientId = client.getClientId();

    Request request{};
    request.setOperation(true);
    request.setTimestamp(time(nullptr) );
    request.setClientId( clientId );
    
    Transaction transaction{};
    transaction.setMessage( &request );
    transaction.setSignature(777);
    
    cout << "[CLIENT] Client request made to primary" << endl;

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
            cout << "[HANDLER] Request transaction handling" << endl;
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
        
        cout << "[PREPREPARE] PrePrepare created" << endl;
        node.multicast(*globalNodes);
    }
}
