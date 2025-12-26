#pragma once

#include "../messageClass/request.h"
#include "../messageClass/transaction.h"
#include "node.h"

#include <iostream>
#include <queue>

class Client {
    private:
        static unsigned int counter;
        const unsigned int clientId;

    public:
        Client();
        unsigned int getClientId();
           
        void print();

        void makeRequest(Node& primaryNode, Transaction transaction);
};
