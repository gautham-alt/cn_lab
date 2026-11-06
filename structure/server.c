#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char *message = "Hello from Server";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind socket to IP and port
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Listen for client connections
    listen(server_fd, 5);
    printf("Server waiting for connection...\n");

    // Accept client connection
    new_socket = accept(server_fd, NULL, NULL);
    printf("Client connected!\n");

    // Receive message from client
    read(new_socket, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    // Send message to client
    send(new_socket, message, strlen(message), 0);

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}
