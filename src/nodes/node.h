#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <mutex>

#include "../messageClass/preprepare.h"
#include "../messageClass/transaction.h"
#include "../control.h"

enum Phase {
    off, prePrepare, prepare,
};

class Node {
    private:
        Phase nodePhase;
        const unsigned int nodeId;
        static unsigned int counter;
        unsigned int view;
        bool isPrimary;
        bool isFaulty;
        std::vector<std::string> log;
        static unsigned int sequenceNumber;

        std::queue<Transaction> buffer;
        std::mutex mutex;
        
        
    public:
        Node(bool isFaulty, bool isPrimary);

        
        void setNodePhase(Phase phase);
        void setView(unsigned int view);
        void setIsPrimary(bool primary);
        void setIsFaulty(bool faulty);
        void setSequenceNumber(PrePrepare*);

        Phase getNodePhase();
        unsigned int getNodeId();
        unsigned int getView();
        bool getIsPrimary();
        bool getIsFaulty();
        std::queue<Transaction>& getBuffer();
        std::mutex& getMutex();

        void print();

        void bufferRead();
        void insertBuffer(Transaction transaction);
        void multicast();
};
