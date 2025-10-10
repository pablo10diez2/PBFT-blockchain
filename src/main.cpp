#include <iostream>
#include <thread>
#include <vector>
#include "node.h"

unsigned int currentView = 1;

int main(){
    std::vector<Node*> nodes;
    nodes.reserve(4);
    
    std::cout<< nodes.size() <<std::endl;
    
    Node node1(State::request, 0, currentView);
    Node node2(State::request, 1, currentView);
    Node node3(State::request, 2, currentView);
    Node node4(State::request, 3, currentView);

    unsigned int primaryId = [&nodes] { return currentView % nodes.capacity(); }();
    
    nodes.push_back(&node1);
    nodes.push_back(&node2);
    nodes.push_back(&node3);
    nodes.push_back(&node4);

    nodes[primaryId-1]->setIsFaulty(true);

    for(int i = 0; i < nodes.size(); ++i){
        std::cout<<"Service state: "<<nodes[i]->getServiceState() << ", Node id: "<< nodes[i]->getNodeId() 
        << ", Current view: "<<nodes[i]->getView() << ", Primary: "<<nodes[i]->getIsPrimary() << ", Faulty: "
        << nodes[i]->getIsFaulty()<<std::endl;
    }

}
