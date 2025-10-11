#pragma once
#include <iostream>

class Message{
    private:
        static unsigned int counter;
        const unsigned int messageId;
    public:
        Message();
        
        int getMessageId();

        virtual void print() = 0;
};

class Request : public Message{
    private:
        bool operation;
        unsigned int timestamp;
        unsigned int clientId;
    
    public:
        Request(bool operation, unsigned int timestamp, unsigned int clientId);
        
        void setOperation(bool operation);
        void setTimestamp(unsigned int timestamp);
        void setClientId(unsigned int clientId);

        bool getOperation();
        unsigned int getTimestamp();
        unsigned int getClientId();

        void print();
};
