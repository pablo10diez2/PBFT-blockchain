#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "messageClass/preprepare.h"

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
        static unsigned int sequenceNumber;
        
    public:
        Node(bool isFaulty, bool isPrimary);
        
        void setServiceState(State serviceState);
        void setView(unsigned int view);
        void setIsPrimary(bool primary);
        void setIsFaulty(bool faulty);
        void setSequenceNumber(PrePrepare&);

        State getServiceState();
        unsigned int getNodeId();
        unsigned int getView();
        bool getIsPrimary();
        bool getIsFaulty();

        void print();

};
