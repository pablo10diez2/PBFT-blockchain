#pragma once

#include "nodes/client.h"
#include "messageClass/transaction.h"

#include <memory>

using namespace std;

class Node;

void startClient(Node* primaryNode, vector<unique_ptr<Node>> nodes);
void waitResponse();
void handleTransaction(Transaction t, Node& node);
void createPrePrepare(Node& node);
