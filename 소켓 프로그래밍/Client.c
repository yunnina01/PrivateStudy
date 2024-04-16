// 소켓 통신의 클라이언트 부분 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

// 에러 핸들링
void errorHandling(char *msg) {
    WSACleanup();
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

// 소켓 연결
void socketConnection(SOCKET *clientSock, SOCKADDR_IN servAddr, char *host, int port) {
	*clientSock = socket(PF_INET, SOCK_STREAM, 0);
	if(*clientSock == INVALID_SOCKET)
		errorHandling("socket() error!");

    memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(host);
	servAddr.sin_port = htons(port);

    if(connect(*clientSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		errorHandling("connect() error!");
}

int main(int argc, char *argv[]) {
    WSADATA wsaData;
	SOCKET clientSock;
	SOCKADDR_IN servAddr;
	
	char host[] = "127.0.0.1";
	int port = 8080;
	char message[30];
	int strLen;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		errorHandling("WSAStartup() error!");
	
	socketConnection(&clientSock, servAddr, host, port);

	// 서버로 메시지 전송
	printf("Send to Server : ");
	scanf("%s", message);
	send(clientSock, message, strlen(message) + 1, 0);

	// 서버로부터 메시지 수신
    strLen = recv(clientSock, message, sizeof(message) - 1, 0);
	if(strLen <= 0)
		errorHandling("read() error!");
    printf("Receive from Server : %s\n", message);

	// 소켓 연결 해제
    closesocket(clientSock);
	WSACleanup();

    return 0;
}