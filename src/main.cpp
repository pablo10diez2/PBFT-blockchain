#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory>

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

void initializeNodes(vector<unique_ptr<Node>>* nodes, int totalNodes);

unsigned int totalNodes = 10;
Node* primaryNode;

void joinAll(thread& t){
    t.join();
}

int main(){
    vector<unique_ptr<Node>> nodes;
    vector<thread> threads;

    initializeNodes(&nodes, totalNodes);

    Request request{0,0,0};
    
    thread clientThread(startClient, primaryNode, &request);

    for(auto& node : nodes){
        auto ptr = node.get();

        threads.emplace_back(
            [ptr]() { ptr->bufferRead(); }                
        );
    }

    clientThread.join();
    for_each(threads.begin(), threads.end(), joinAll);
}

void initializeNodes(vector<unique_ptr<Node>>* nodes, int totalNodes){
    nodes->reserve(totalNodes);

    int faultyNodes = 10/3;
    int workingNodes = totalNodes - faultyNodes;

    for(int i = 0; i < faultyNodes; ++i){
        bool isFaulty = true;
        bool isPrimary = false;
        
        auto newNodePtr = make_unique<Node>(isFaulty, isPrimary);

        nodes->push_back( move(newNodePtr) );
    }

    for(int i = 0; i < workingNodes; ++i){
        bool isFaulty = false;
        bool isPrimary = false;
        unique_ptr<Node> newNodePtr;
        
        if(i == 0){
            newNodePtr = make_unique<Node>(isFaulty, !isPrimary);
            primaryNode = newNodePtr.get();
        }

        else{
            newNodePtr = make_unique<Node>(isFaulty, isPrimary);
        }
        nodes->push_back( move(newNodePtr) );
    }
}
