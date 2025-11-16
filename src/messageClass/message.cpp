#include "message.h"

unsigned int Message::counter=0;

Message::Message() : messageId(counter++) {}

int Message::getMessageId(){
    return this->messageId;
}

void Message::print(){
    std::cout << "" << std::endl;
}
