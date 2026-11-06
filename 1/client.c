#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(5000);
	inet_pton(AF_INET,"127.0.0.1",&server_addr.sin_addr);
	connect (sockfd,(struct sockaddr *)&server_addr,
	sizeof(server_addr));
	char msg[]="Hello sever";
	send(sockfd,msg,strlen(msg),0);
	char buffer[100];
	recv(sockfd,buffer,sizeof(buffer),0);
	printf("server %s",buffer);
	close(sockfd);
	return 0;
}
