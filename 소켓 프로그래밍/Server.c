#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void errorHandling(char *msg){
    WSACleanup();
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void socketBinding(SOCKET *servSock, SOCKET *clientSock, SOCKADDR_IN servAddr, SOCKADDR_IN clientAddr, char *host, int port){
    *servSock = socket(PF_INET, SOCK_STREAM, 0);
	if(*servSock == INVALID_SOCKET)
		errorHandling("socket() error!");

    memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(host);
	servAddr.sin_port = htons(port);

    if(bind(*servSock, (void*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        errorHandling("bind() error!");
    
    if(listen(*servSock, 2) == SOCKET_ERROR)
        errorHandling("listen() error!");
    
    int fromLen = sizeof(clientAddr);

    *clientSock = accept(*servSock, (void*)&clientAddr, &fromLen);
    if(*clientSock == INVALID_SOCKET)
        errorHandling("accept() error!");
    else{
        printf("%s Connection Complete\n", inet_ntoa(clientAddr.sin_addr));
        printf("Start ...\n");
    }
}

int main(){
    WSADATA wsaData;
	SOCKET servSock, clientSock;
	SOCKADDR_IN servAddr, clientAddr;
	
	char host[] = "127.0.0.1";
	int port = 8080;
	char message[30];
	int fromLen, nRcv;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		errorHandling("WSAStartup() error!");

    socketBinding(&servSock, &clientSock, servAddr, clientAddr, host, port);

    nRcv = recv(clientSock, message, sizeof(message) - 1, 0);
    if(nRcv == SOCKET_ERROR)
        errorHandling("recv() error!");
    message[nRcv] = '\0';
    printf("Receive from Client : %s\n", message);

	printf("Send to Client : ");
	scanf("%s", message);
	send(clientSock, message, strlen(message) + 1, 0);

    closesocket(servSock);

	WSACleanup();

    return 0;
}