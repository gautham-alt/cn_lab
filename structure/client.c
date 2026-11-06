#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char *message = "Hello from Client";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Connected to server!\n");

    // Send message to server
    send(sock, message, strlen(message), 0);

    // Receive message from server
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}
