#pragma once 

#include "message.h"

class Transaction {
    private:
        Message* message;
        int signature;
    
    public:
        Transaction(Message* message, int signature);

        Message* getMessage();
        int getSignature();
        void print();
};
