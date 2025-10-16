#pragma once
#include "message.h"

class Reply : Message(){
    private:
        unsigned int nodeView;
        unsigned int timestamp;
        unsigned int clientId;
        unsigned int nodeId;
        bool result;
    public:
        Reply(unsigned int nodeView, unsigned int timestampm unsigned int clientId, unsigned int nodeId, bool result);
        
        void setNodeView(unsigned int nodeView);
        void setTimestamp(unsigned int timestamp);
        void setClientId(unsigned int clientId);
        void setNodeId(unsigned int nodeId);
        bool setResult(bool result);

        unsigned int getNodeView();
        unsigned int getTimestamp();
        unsigned int getClientId();
        unsigned int getNodeId();
        bool getResult();

        void print();
}
