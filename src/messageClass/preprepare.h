#pragma once

#include "message.h"
#include <iostream>

class PrePrepare : public Message{
    private:
        unsigned int viewNum;
        unsigned int sequenceNum;
        size_t messageDigest;

    public:
        PrePrepare();
        PrePrepare(unsigned int viewNum, unsigned int sequenceNum, size_t messageDigest);
        
        void setViewNum(unsigned int viewNum);
        void setSequenceNum(unsigned int sequenceNum);
        void setMessageDigest(size_t messageDigest);

        unsigned int getViewNum();
        unsigned int getSequenceNum();
        size_t getMessageDigest();

        void print();
        MsgType getType();
    };
