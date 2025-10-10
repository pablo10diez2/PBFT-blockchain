#include <iostream>
#include <thread>

void print(){
    std::cout<<"aa"<<std::endl;
}

int main(){
    std::thread server (print);
    std::thread client (print);

    server.join();
    client.join();

    return 0;
}
