#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char *message = "Hello from UDP Client";

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Send message to server
    sendto(sockfd, message, strlen(message), 0,
           (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Message sent to server!\n");

    // Receive reply from server
    socklen_t len = sizeof(server_addr);

    recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&server_addr, &len);

    buffer[sizeof(buffer) - 1] = '\0';

    printf("Server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
