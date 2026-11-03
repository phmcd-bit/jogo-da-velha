#include "jogadorRemoto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jogaRemoto(JogadorRemoto *jogadorRemoto, Tabuleiro *tabuleiro) {
    int linha = -1, coluna = -1;
    char buffer[16];

    memset(buffer, 0, sizeof(buffer));

    int bytes = recv(jogadorRemoto->conexao, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) {
        printf("Adversario desconectou.\n");
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    if (sscanf(buffer, "%d %d", &linha, &coluna) != 2) {
        printf("Jogada recebida em formato invalido.\n");
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro->M[linha][coluna] != VAZIO) {
        printf("Jogada recebida invalida.\n");
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    marcaJogada(tabuleiro, linha, coluna, jogadorRemoto->tipo);
}

void conecta(JogadorRemoto *jogadorRemoto, const char *endereco, int porta) {
    struct sockaddr_in servidor;

    jogadorRemoto->conexao = socket(AF_INET, SOCK_STREAM, 0);
    if (jogadorRemoto->conexao == INVALID_SOCKET) {
        printf("Erro ao criar socket: %d\n", WSAGetLastError());
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    memset(&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(porta);
    servidor.sin_addr.s_addr = inet_addr(endereco);

    if (servidor.sin_addr.s_addr == INADDR_NONE) {
        printf("Endereco invalido\n");
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    if (connect(jogadorRemoto->conexao, (struct sockaddr *)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        printf("Erro ao conectar: %d\n", WSAGetLastError());
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
}

void aceita(JogadorRemoto *jogadorRemoto, int porta) {
    SOCKET servidor_fd;
    struct sockaddr_in endereco;
    int endereco_len = sizeof(endereco);

    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == INVALID_SOCKET) {
        printf("Erro ao criar socket: %d\n", WSAGetLastError());
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR) {
        printf("Erro no bind: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    if (listen(servidor_fd, 1) == SOCKET_ERROR) {
        printf("Erro no listen: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Aguardando conexao na porta %d...\n", porta);

    jogadorRemoto->conexao = accept(servidor_fd, (struct sockaddr *)&endereco, &endereco_len);
    if (jogadorRemoto->conexao == INVALID_SOCKET) {
        printf("Erro no accept: %d\n", WSAGetLastError());
        closesocket(servidor_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    closesocket(servidor_fd);

    printf("Cliente conectado!\n");
}

void enviaJogada(JogadorRemoto *jogadorRemoto, int linha, int coluna) {
    char buffer[16];

    snprintf(buffer, sizeof(buffer), "%d %d", linha, coluna);

    if (send(jogadorRemoto->conexao, buffer, strlen(buffer), 0) == SOCKET_ERROR) {
        printf("Erro ao enviar jogada: %d\n", WSAGetLastError());
        closesocket(jogadorRemoto->conexao);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
}