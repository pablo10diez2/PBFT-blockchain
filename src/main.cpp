#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <queue>

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

using namespace std;

void initializeNodes(vector<Node>* nodes, int totalNodes);

unsigned int totalNodes = 10;
Node* primaryNode;

void joinAll(thread& t){
    t.join();
}

void emit(queue<int>& q){
    sleep(2);
    q.push(100);
}

int main(){
    vector<Node> nodes;
    vector<thread> threads;

    initializeNodes(&nodes, totalNodes);

    for(auto& node : nodes){
        
        threads.emplace_back(
            [&node]() { node.bufferRead(); }                
        );
    }

    for_each(nodes.begin(), nodes.end(), 
                [](Node& n) { emit( n.getBuffer() ); }
            );

    for_each(threads.begin(), threads.end(), joinAll);
}

void initializeNodes(vector<Node>* nodes, int totalNodes){
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
