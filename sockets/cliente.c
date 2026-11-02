#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORTA 8080
#define TAM_BUFFER 1024

int main() {

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Erro ao inicializar Winsock: %d\n", WSAGetLastError());
        return EXIT_FAILURE;
    }

    SOCKET sock;
    struct sockaddr_in servidor;
    char buffer[TAM_BUFFER];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        printf("Erro ao criar socket: %d\n", WSAGetLastError());
        WSACleanup();
        return EXIT_FAILURE;
    }

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    if (inet_pton(AF_INET, "127.0.0.1", &servidor.sin_addr) <= 0) {
        printf("Endereco invalido\n");
        closesocket(sock);
        WSACleanup();
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        printf("Erro ao conectar: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return EXIT_FAILURE;
    }

    printf("Conectado ao servidor!\n");

    while (1) {
        // Envia mensagem
        printf("Cliente: ");
        fgets(buffer, TAM_BUFFER, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(sock, buffer, strlen(buffer) + 1, 0);

        if (strcmp(buffer, "sair") == 0)
            break;

        // Recebe resposta
        memset(buffer, 0, TAM_BUFFER);

        int bytes = recv(sock, buffer, TAM_BUFFER - 1, 0);

        if (bytes <= 0) {
            printf("Servidor desconectou.\n");
            break;
        }

        printf("Servidor: %s\n", buffer);

        if (strcmp(buffer, "sair") == 0)
            break;
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}