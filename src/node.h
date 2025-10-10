#pragma once

#include "message.h"
#include <string>
#include <vector>

enum State {
    request, prePrepare, prepare
};

class Node {
    private:
        State serviceState;
        unsigned int nodeId;
        unsigned int view;
        bool isPrimary;
        bool isFaulty;
        std::vector<std::string> log;
        
    public:
        Node(State serviceState, unsigned int nodeId, unsigned int view);
        
        void setServiceState(State serviceState);
        void setNodeId(unsigned int nodeId);
        void setView(unsigned int view);
        void setIsPrimary(bool primary);
        void setIsFaulty(bool faulty);

        State getServiceState();
        unsigned int getNodeId();
        unsigned int getView();
        bool getIsPrimary();
        bool getIsFaulty();

};
