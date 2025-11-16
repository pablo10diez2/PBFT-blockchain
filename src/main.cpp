#include <iostream>
#include <thread>
#include <vector>
#include "node.h"
#include "messageClass/message.h"
#include "messageClass/request.h"
#include "messageClass/preprepare.h"
#include "messageClass/prepare.h"
#include "messageClass/commit.h"
#include "messageClass/reply.h"
#include "messageClass/commit.h"
#include "messageClass/reply.h"
#include "client.h"

void initializeNodes(std::vector<Node>* nodes, int totalNodes);
void programStart();
void prePreparePhase();
void prePreparePrimary();

unsigned int totalNodes = 10;
Node* primaryNode;

struct Transaction{
    Message* message;
    int signature;

    Transaction(Message* m, int s) : message(m), signature(s) {}
};

int main(){
    std::vector<Node> nodes;

    initializeNodes(&nodes, totalNodes);

    Commit c1 = {1, 1, 1, 1};

    Transaction t(&c1, 0);

    for(auto& node : nodes){
        node.print();
    }

    programStart();
}

void initializeNodes(std::vector<Node>* nodes, int totalNodes){
    int faultyNodes = 10/3;
    int workingNodes = totalNodes - faultyNodes;

    for(int i = 0; i < faultyNodes; ++i){
        bool isFaulty = true;
        bool isPrimary = false;
        nodes->emplace_back(isFaulty, isPrimary);
    }

    for(int i = 0; i < workingNodes; ++i){
        bool isFaulty = false;
        bool isPrimary = false;
        
        if(i == 0){
            nodes->emplace_back(isFaulty, !isPrimary);
            primaryNode = &(nodes->back());
        }

        else{
            nodes->emplace_back(isFaulty, isPrimary);
        }
    }
}

void programStart(){
    Request request = {1, 20 , 0};
    prePreparePrimary();
}

void prePreparePhase(){
}

void prePreparePrimary(){
    primaryNode->setSequenceNumber();
}
