#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

int main(){
    int client_fd= socket(AF_INET, SOCK_STREAM, 0);

    if(client_fd == -1){
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if(connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        std::cerr << "Connection to server failed" << std::endl;
        close(client_fd);
        return 1;   
    }

    std::string message = "Hello from Client\n";
    send(client_fd, message.c_str(), message.size(), 0);

    char buffer[90];
    memset(buffer, 0, sizeof(buffer));
    recv(client_fd, buffer, sizeof(buffer)-1, 0);
    std::cout << "Received: " << buffer << std::endl;

    close(client_fd);
    
    return 0;
}