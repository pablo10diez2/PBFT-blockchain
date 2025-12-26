#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <queue>

#include "control.h"
#include "nodes/node.h"
#include "messageClass/message.h"
#include "messageClass/request.h"
#include "messageClass/preprepare.h"
#include "messageClass/prepare.h"
#include "messageClass/commit.h"
#include "messageClass/reply.h"
#include "messageClass/commit.h"
#include "messageClass/reply.h"
#include "nodes/client.h"

using namespace std;

void initializeNodes(vector<Node>* nodes, int totalNodes);

unsigned int totalNodes = 10;
Node* primaryNode;

void joinAll(thread& t){
    t.join();
}

int main(){
    vector<Node> nodes;
    vector<thread> threads;

    initializeNodes(&nodes, totalNodes);
    
    thread clientThread(startClient, primaryNode);

    for(auto& node : nodes){
        threads.emplace_back(
            [&node]() { node.bufferRead(); }                
        );
    }

    clientThread.join();
    for_each(threads.begin(), threads.end(), joinAll);
}

void initializeNodes(vector<Node>* nodes, int totalNodes){
    nodes->reserve(totalNodes);

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
