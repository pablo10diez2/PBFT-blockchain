#include "../nodes/node.h"

#include <list>

using namespace std;

class MessageManager{
    private:
        list<unique_ptr<Node>> nodes;
        list<unique_ptr<Message>> messages;

        mutex nodeMutex;
        mutex messageMutex;

    public:
        MessageManager();
        Node* createNode(bool isFaulty, bool isPrimary);
        Request* createRequest();
};
