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

int main(){
    int totalNodes = 10;
    std::vector<Node> nodes;

    initializeNodes(&nodes, totalNodes);

    for(auto& node : nodes){
        node.print();
    }
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
        }

        else{
            nodes->emplace_back(isFaulty, isPrimary);
        }
    }
}
