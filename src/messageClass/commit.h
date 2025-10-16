#pragma once
#include "message.h"

class Commit : Message(){
    private:
        unsigned int viewNum;
        unsigned int sequenceNum;
        size_t messageDigest;
        unsigned int nodeId;

    public:
        Message(unsigned int viewNum, unsigned int sequenceNum, size_t messageDigest, unsigned int nodeId);

        void setViewNum(unsigned int viewNum);
        void setSequenceNum(unsigned int sequenceNum);
        void setMessageDigest(size_t messageDigest);
        void setNodeId(unsigned int nodeId);
        
        unsigned int getViewNum();
        unsigned int getSequenceNum();
        size_t getMessageDigest();
        unsigned int getNodeId();

        void print();
}
