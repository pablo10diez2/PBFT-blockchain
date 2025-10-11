#include <iostream>
#include <thread>
#include <vector>
#include "node.h"
#include "message.h"

unsigned int currentView = 1;
unsigned int totalNodes = 10;

void initializeNodes(std::vector<Node>& nodes);

int main(){
    std::vector<Node> nodes;
    initializeNodes(nodes);

    for(auto & node : nodes){
        node.print();
    }

    std::vector<Request> requests;
    requests.emplace_back(false, 1, 1);
    requests.emplace_back(true, 3, 1);

    for(auto & request : requests){
        request.print();
    }

    std::vector<PrePrepare> prePrepares;
    prePrepares.emplace_back(1, 11, 15);
    prePrepares.emplace_back(1, 11, 14);

    for(auto & prePrepare : prePrepares){
        prePrepare.print();
    }

}

void initializeNodes(std::vector<Node>& nodes){
    unsigned int faultyNodes = totalNodes % 3;

    for (int i=0; i<totalNodes; ++i){   
        nodes.emplace_back(State::request, i, currentView);
    }

    for (int i=totalNodes-faultyNodes; i<totalNodes; ++i){
        nodes[i].setIsFaulty(true);
    }
    
    unsigned int primaryId = [&nodes] { return currentView % nodes.size(); }();

    nodes[primaryId].setIsPrimary(true);
}
