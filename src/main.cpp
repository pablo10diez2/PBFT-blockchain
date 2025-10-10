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

    Node(State serviceS, int id, int vw, bool py) : 
        serviceState(serviceS), nodeId(id), view(vw), primary(py) {}
};

int main(){
    std::vector<Node> nodes;
    nodes.reserve(4);
    
    Node node1(State::request, 0, 0, true, false);
    Node node2(State::request, 1, 0, false, false);
    Node node3(State::request, 2, 0, false, false);
    Node node4(State::request, 3, 0, false, false);

    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);

}
