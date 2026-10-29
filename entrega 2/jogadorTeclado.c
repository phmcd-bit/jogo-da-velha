#include "jogadorTeclado.h"
#include <stdio.h>

void joga(JogadorTeclado *jogador, Tabuleiro *tabuleiro){

    int linha, coluna;
    int validacao = 0;

    while (validacao == 0){

        printf("Digite a posicao da linha e coluna: ");
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro->M[linha][coluna] == VAZIO) {
             marcaJogada(tabuleiro, linha, coluna, jogador->tipo);
             validacao = 1;
        }
        else {
            printf("Posicao invalida!\n");
        }
    }
}