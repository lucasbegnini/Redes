#include <stdio.h>
#include <conio.h>
#include <winsock.h>
#include <windows.h>
WSADATA data;
SOCKET winsock;
SOCKADDR_IN sock;
char buffer[1024];
char buffer2[1024];
int bytes;



              int main()
{
    if(WSAStartup(MAKEWORD(1,1),&data)==SOCKET_ERROR)
    {
        printf("Erro ao inicializar o winsock");
        return 0;
    }
    if((winsock = socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR)
    {
        printf("Erro ao criar socket");
        return 0;
    }
    sock.sin_family=AF_INET;
    sock.sin_port=htons(1234);
    if(bind(winsock,(SOCKADDR*)&sock,sizeof(sock))==SOCKET_ERROR)
    {
        printf("Erro colocar utilizar a funcao BIND");
        return 0;
    }
    listen(winsock,1);
    while((winsock = accept(winsock,0,0))==SOCKET_ERROR)
    {
        Sleep(1);
    }
    printf("Cliente conectado!");
    while(1)
    {
        Sleep(1);
        memset(buffer2,0,1024);
        printf("Cliente diz:\n");
		bytes=recv(winsock,buffer2,1024,0);
        if(bytes==-1)
        {
            printf("Conexão perdida");
            getch();
            return 0;
        }
        printf(buffer2);
        printf("Digite uma mensagem:\n");
		printf("Voce diz:\n");
        gets(buffer);
        strcat(buffer,"\r\n");
        send(winsock,buffer,strlen(buffer),0);

    }
    getch();
    closesocket(winsock);
    WSACleanup();
    return 0;
}
