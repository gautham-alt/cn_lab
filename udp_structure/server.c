#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind socket
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP Server waiting for message...\n");

    socklen_t len = sizeof(client_addr);

    // Receive message from client
    recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&client_addr, &len);

    buffer[sizeof(buffer) - 1] = '\0';

    printf("Client: %s\n", buffer);

    // Send reply to client
    char *message = "Hello from UDP Server";

    sendto(sockfd, message, strlen(message), 0,
           (struct sockaddr *)&client_addr, len);

    // Close socket
    close(sockfd);

    return 0;
}
