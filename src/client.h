#pragma once

#include <deque>
#include "message.h"
#include <iostream>

class Client {
    private:
        static unsigned int counter;
        const unsigned int clientId;
        std::deque<Request> clientBuffer;

    public:
        Client();
        
        unsigned int getClientId();
        unsigned int getBufferSize();
           
        void addRequest(Request request);
        void print();
        void printBuffer();
};
