#include <stdio.h>
#include "partida.h"

void configuraJogadores(Partida *partida) {
    int opcao;

    printf("Como vai ser o jogo?\n");
    printf("1 - Pessoa VS Pessoa\n");
    printf("2 - Pessoa VS IA \n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            partida->escolha = PESSOA_VS_PESSOA;
            break;
        case 2:
            partida->escolha = PESSOA_VS_IA;
            break;
    }

    partida->jogador1.tipo = JOGADOR_X;
    partida->jogador2.tipo = JOGADOR_O;
    partida->jogadorIA.tipo = JOGADOR_O;
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
            if (partida->escolha == PESSOA_VS_IA) {
                jogaIA(&partida->jogadorIA, &partida->tabuleiro);
            } else {
                joga(&partida->jogador2, &partida->tabuleiro);
            }   
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