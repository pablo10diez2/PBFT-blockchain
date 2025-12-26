#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <mutex>

#include "../messageClass/preprepare.h"
#include "../messageClass/transaction.h"

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

        std::queue<Transaction> buffer;
        std::mutex mutex;
        
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
        std::queue<Transaction>& getBuffer();
        std::mutex& getMutex();

        void print();

        void bufferRead();
        void insertBuffer(Transaction transaction);
};
