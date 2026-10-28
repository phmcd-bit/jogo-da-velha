#include <stdio.h>
#include "partida.h"

void configuraJogadores(Partida *partida) {
    partida->jogador1.tipo = JOGADOR_X;
    partida->jogador2.tipo = JOGADOR_O;
}

void inicia(Partida *partida) {

    int contador_jogadas = 0;
    int resultado = VAZIO;

    inicializaTabuleiro(&partida->tabuleiro);
    
    while (resultado == VAZIO && contador_jogadas < 9) {
        desenha(&partida->tabuleiro);
        if (contador_jogadas % 2 == 0) {
            printf("Vez do Jogador X\n");
            joga(&partida->jogador1, &partida->tabuleiro);
        } else {
            printf("Vez do Jogador O\n");
            joga(&partida->jogador2, &partida->tabuleiro);
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
}