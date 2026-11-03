#include <stdio.h>
#include "partida.h"

void configuraJogadores(Partida *partida, int souServidor) {
    if (souServidor) {
        partida->jogadorTeclado.tipo = JOGADOR_X;
        partida->jogadorRemoto.tipo = JOGADOR_O;
    } else {
        partida->jogadorTeclado.tipo = JOGADOR_O;
        partida->jogadorRemoto.tipo = JOGADOR_X;
    }
}

void inicia(Partida *partida) {

    int resultado = VAZIO;
    int vez;
    int linha = 0, coluna = 0;
    int contador_jogadas = 0;

    inicializaTabuleiro(&partida->tabuleiro);

    while (resultado == VAZIO && contador_jogadas < 9) {
        desenha(&partida->tabuleiro);

        if (contador_jogadas % 2 == 0) {
            vez = JOGADOR_X;
            printf("Vez do Jogador X\n");
        } else {
            vez = JOGADOR_O;
            printf("Vez do Jogador O\n");
        }

        if (vez == partida->jogadorTeclado.tipo) {
            joga(&partida->jogadorTeclado, &partida->tabuleiro, &linha, &coluna);
            enviaJogada(&partida->jogadorRemoto, linha, coluna);
        } else {
            printf("Aguardando jogada do adversario...\n");
            jogaRemoto(&partida->jogadorRemoto, &partida->tabuleiro);
        }

        resultado = temVencedor(&partida->tabuleiro);
        contador_jogadas++;
    }
    desenha(&partida->tabuleiro);

    if (resultado == JOGADOR_X) {
        printf("Jogador X venceu!\n");
    } else if (resultado == JOGADOR_O) {
        printf("Jogador O venceu!\n");
    } else {
        printf("Empate!\n");
    }

    closesocket(partida->jogadorRemoto.conexao);
}