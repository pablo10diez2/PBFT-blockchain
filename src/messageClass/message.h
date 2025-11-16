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
