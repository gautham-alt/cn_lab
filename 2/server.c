#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	int m[20][20];
	int n;
	int sockfd,newsock;
	struct sockaddr_in server,client;
	socklen_t len=sizeof(client);
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(5000);
	
	bind(sockfd,(struct sockaddr *)&server,sizeof(server));
	listen(sockfd,1);
	printf("WAITING FOR cliwnt \n");
	newsock=accept(sockfd,(struct sockaddr *)&client,&len);
	recv(newsock,m,sizeof(m),0);
	recv(newsock,&n,sizeof(n),0);
	
	printf("recieved");
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", m[i][j]);

        printf("\n");
    }

    int upper = 1, lower = 1, diagonal = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && m[i][j] != 0)
                upper = 0;

            if (i < j && m[i][j] != 0)
                lower = 0;

            if (i != j && m[i][j] != 0)
                diagonal = 0;
        }
    }

    char result[30];

    if (diagonal)
        strcpy(result, "Diagonal");
    else if (upper)
        strcpy(result, "Upper Triangular");
    else if (lower)
        strcpy(result, "Lower Triangular");
    else
        strcpy(result, "Neither");
	send(newsock,result,sizeof(result),0);
	close(newsock);
	close(sockfd);
}
	
