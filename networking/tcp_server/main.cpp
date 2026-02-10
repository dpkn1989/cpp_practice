#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

int main(){
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }
    
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return 1;   
    }

    std::cout << "Server is running and bound to port 8080" << std::endl;

    if(listen(server_fd, 5) < 0)
    {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return 1;   
    }

    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);

    if(client_fd < 0){
        std::cerr << "Accept failed" << std::endl;
        close(server_fd);
        return 1;   
    }

    std::cout << "Client connected successfully." << std::endl;

    char buffer[90];
    memset(buffer, 0, sizeof(buffer));
    recv(client_fd, buffer, sizeof(buffer)-1, 0);
    std::cout << "Received: " << buffer << std::endl;

    std::string response = "Hello from Server\n";
    send(client_fd, response.c_str(), response.size(), 0);

    close(client_fd);
    close(server_fd);

    
    return 0;
}