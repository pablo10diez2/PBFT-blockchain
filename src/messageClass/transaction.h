#pragma once 

#include "message.h"

class Transaction {
    private:
        Message* message;
        int signature;
    
    public:
        Transaction();
        Transaction(Message* message, int signature);
        
        void setMessage(Message* message);
        void setSignature(int signature);

        Message* getMessage();
        int getSignature();
        void print();
};
