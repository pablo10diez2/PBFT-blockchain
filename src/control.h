#pragma once

#include "nodes/client.h"
#include "messageClass/transaction.h"

class Node;

void startClient(Node* primaryNode);
void waitResponse();
void handleTransaction(Transaction t, Node& node);
void createPrePrepare(Node& node);
