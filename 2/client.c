#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
int main(){
	int sockfd;
	struct sockaddr_in server;
	int m[20][20];
	int n;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port=htons(5000);
	
	connect(sockfd,(struct sockaddr *)&server,sizeof(server));
	printf("Enter n");
	scanf("%d",&n);
	srand(time(NULL));
	// Generate random matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = rand() % 50 + 1;
        }
    }

    printf("Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", m[i][j]);

        printf("\n");
    }
    send(sockfd,m,sizeof(m),0);
    send(sockfd,&n,sizeof(n),0);
    char result[30];
    
    recv(sockfd,result,sizeof(result),0);
    printf("%s ",result);
    return 0;
   }
