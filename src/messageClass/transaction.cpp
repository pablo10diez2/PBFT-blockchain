#include "transaction.h"

Transaction::Transaction(Message* m, int sig) : message(m), signature(sig) {}

Message* Transaction::getMessage(){
    return this->message;
}

int Transaction::getSignature(){
    return this->signature;
}

void Transaction::print(){
    std::cout << "Transaction: ";
    this->message->print();
    std::cout << this->getSignature() <<  std::endl;
}
