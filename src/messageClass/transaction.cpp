#include "transaction.h"

Transaction::Transaction() : message(nullptr), signature(0) {}

Transaction::Transaction(Message* m, int sig) : message(m), signature(sig) {}

void Transaction::setMessage(Message* message){
    this->message = message;
}

void Transaction::setSignature(int signature){
    this->signature = signature;
}

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
