#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main() {
    WSADATA wsa;
    Partida partida;
    int porta;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Erro ao iniciar o Winsock\n");
        return EXIT_FAILURE;
    }

    printf("Digite a porta (ex: 8080): ");
    scanf("%d", &porta);

    configuraJogadores(&partida, 1);         
    aceita(&partida.jogadorRemoto, porta);  

    inicia(&partida);

    WSACleanup();
    return 0;
}