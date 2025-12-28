#pragma once

#include <iostream>
#include <ctime>

#include "message.h"

class Request : public Message{
    private:
        bool operation;
        std::time_t timestamp;
        unsigned int clientId;
    
    public:
        Request();
        Request(bool operation, unsigned int timestamp, unsigned int clientId);
        
        void setOperation(bool operation);
        void setTimestamp(std::time_t timestamp);
        void setClientId(unsigned int clientId);

        bool getOperation();
        std::time_t getTimestamp();
        unsigned int getClientId();

        void print();
        MsgType getType();
};
