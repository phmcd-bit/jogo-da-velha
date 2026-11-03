#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main() {
    WSADATA wsa;
    Partida partida;
    char ip[32];
    int porta;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Erro ao iniciar o Winsock\n");
        return EXIT_FAILURE;
    }

    printf("Digite o IP do servidor (ex: 127.0.0.1): ");
    scanf("%31s", ip);
    printf("Digite a porta (ex: 8080): ");
    scanf("%d", &porta);

    configuraJogadores(&partida, 0);          
    conecta(&partida.jogadorRemoto, ip, porta);

    inicia(&partida);

    WSACleanup();
    return 0;
}