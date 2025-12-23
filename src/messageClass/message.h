#pragma once

#include <iostream>
#include <string>

enum MsgType{
    Type_Request,
    Type_PrePrepare,
    Type_Prepare,
    Type_Commit,
    Type_Reply,
};

class Message{
    private:
        static unsigned int counter;
        const unsigned int messageId;

    public:
        Message();
        
        int getMessageId();
        virtual void print() = 0;
        virtual MsgType getType() = 0;
};
