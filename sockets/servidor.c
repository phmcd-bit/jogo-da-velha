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

    SOCKET servidor_fd, cliente_fd;
    struct sockaddr_in endereco;
    int endereco_len = sizeof(endereco);
    
    char buffer[TAM_BUFFER];

    // Cria socket
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == INVALID_SOCKET) {
        printf("Erro ao criar socket: %d\n", WSAGetLastError());
        WSACleanup();
        return EXIT_FAILURE;
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    // Associa socket à porta
    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR) {
        printf("Erro no bind: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Escuta conexões
    if (listen(servidor_fd, 1) == SOCKET_ERROR) {
        printf("Erro no listen: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    printf("Servidor aguardando conexao na porta %d...\n", PORTA);

    cliente_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &endereco_len);
    if (cliente_fd == INVALID_SOCKET) {
        printf("Erro no accept: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    printf("Cliente conectado!\n");

    while (1) {
        memset(buffer, 0, TAM_BUFFER);

        // Recebe mensagem do cliente
        int bytes = recv(cliente_fd, buffer, TAM_BUFFER - 1, 0);

        if (bytes <= 0) {
            printf("Cliente desconectou.\n");
            break;
        }

        printf("\nCliente: %s\n", buffer);

        if (strcmp(buffer, "sair") == 0)
            break;

        // Envia resposta
        printf("Servidor: ");
        fgets(buffer, TAM_BUFFER, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(cliente_fd, buffer, strlen(buffer) + 1, 0);

        if (strcmp(buffer, "sair") == 0)
            break;
    }

    close(cliente_fd);
    close(servidor_fd);
    WSACleanup();

    return 0;
}