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

queue<int> cola;

void func(){
    while(true){
        if (!cola.empty()){
            int num = cola.front();
            cout << "Thread number: " << this_thread::get_id() << " -> Arrived: " << num << endl;

            cola.pop();
            break;
        }
    }   
}

void joinAll(thread& t){
    t.join();
}

void emit(){
    sleep(3);
    cola.push(100);
}

int main(){
    vector<Node> nodes;
    vector<thread> threads;

    initializeNodes(&nodes, totalNodes);

    for(auto& node : nodes){
        node.print();
    }

    //for(int i = 0; i < totalNodes; ++i){
    //    threads.push_back( thread(func) );
    //}

    thread emisor(emit);
    thread rec(func);

    rec.join();
    emisor.join();    
    std::for_each(threads.begin(), threads.end(), joinAll);
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
