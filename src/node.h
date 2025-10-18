#pragma once

#include <string>
#include <vector>
#include <iostream>

enum State {
    off, request, prePrepare, prepare
};

class Node {
    private:
        State serviceState;
        const unsigned int nodeId;
        static unsigned int counter;
        unsigned int view;
        bool isPrimary;
        bool isFaulty;
        std::vector<std::string> log;
        
    public:
        Node(bool isFaulty, bool isPrimary);
        
        void setServiceState(State serviceState);
        void setView(unsigned int view);
        void setIsPrimary(bool primary);
        void setIsFaulty(bool faulty);

        State getServiceState();
        unsigned int getNodeId();
        unsigned int getView();
        bool getIsPrimary();
        bool getIsFaulty();

        void print();

};
