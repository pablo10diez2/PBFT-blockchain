#include <iostream>
#include <thread>
#include <vector>

enum State {
    request, prePrepare, prepare
};

struct Node{
    State serviceState;
    unsigned int nodeId;
    unsigned int view;
    bool primary;
    bool faulty;

    Node(State serviceS, int id, int vw, bool py, bool ft) : 
        serviceState(serviceS), nodeId(id), view(vw), primary(py), faulty(ft) {}
};

unsigned int currentView = 1;

int main(){
    std::vector<Node*> nodes;
    nodes.reserve(4);
    
    std::cout<< nodes.size() <<std::endl;
    
    Node node1(State::request, 0, currentView, true, false);
    Node node2(State::request, 1, currentView, false, false);
    Node node3(State::request, 2, currentView, false, false);
    Node node4(State::request, 3, currentView, false, false);

    unsigned int primaryId = [&nodes] { return currentView % nodes.capacity(); }();
    
    nodes.push_back(&node1);
    nodes.push_back(&node2);
    nodes.push_back(&node3);
    nodes.push_back(&node4);

    nodes[primaryId-1]->faulty = 1;

    for(int i = 0; i < nodes.size(); ++i){
        std::cout<<"Service state: "<<nodes[i]->serviceState << ", Node id: "<< nodes[i]->nodeId 
        << ", Current view: "<<nodes[i]->view << ", Primary: "<<nodes[i]->primary << ", Faulty: "
        << nodes[i]->faulty<<std::endl;
    }

}
