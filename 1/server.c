#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
	int sockfd =socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=INADDR_ANY;
	server_addr.sin_port=htons(5000);
	bind(sockfd,
	(struct sockaddr *)&server_addr,
	sizeof(server_addr));
	listen(sockfd,5);
	int clientfd=accept(sockfd,NULL,NULL);
	char buffer[100];
	recv(clientfd,buffer,sizeof(buffer),0);
	printf("client %s ",buffer);
	
	char msg[]="hello client";
	send(clientfd,msg,sizeof(msg),0);
	close(clientfd);
	close(sockfd);
	return 0;
}
