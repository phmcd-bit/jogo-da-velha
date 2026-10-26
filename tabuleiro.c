#include "tabuleiro.h"
#include <stdio.h>

void inicializaTabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro->M[i][j] = VAZIO;
        }
    }
}
 
void desenhaTabuleiro(Tabuleiro *tabuleiro) {

    printf("\033[2J\033[H"); 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] == VAZIO) {
                printf("   ");
            } else if (tabuleiro->M[i][j] == JOGADOR_O) {
                printf(" O ");
            } else if (tabuleiro->M[i][j] == JOGADOR_X) {
                printf(" X ");
            }

            if (j < 2) {
                printf("|");
            }
        }

        printf("\n");

        if (i < 2) {
            printf("---+---+---\n");
        }
    }
}

void marcaJogada(Tabuleiro *tabuleiro, int linha, int coluna, int tipo) {
    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
        tabuleiro->M[linha][coluna] = tipo;
    }

    else {
        printf("Posicao invalida!\n");
    }

}
            
int temVencedor(Tabuleiro *tabuleiro) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2] == 3 * JOGADOR_O) {
            return JOGADOR_O;
        }

        if (tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2] == 3 * JOGADOR_X) {
            return JOGADOR_X;
        }

        if (tabuleiro->M[0][i] + tabuleiro->M[1][i] + tabuleiro->M[2][i] == 3 * JOGADOR_O) {
            return JOGADOR_O;
        }

        if (tabuleiro->M[0][i] + tabuleiro->M[1][i] + tabuleiro->M[2][i] == 3 * JOGADOR_X) {
            return JOGADOR_X;
        }
    }

    if (tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == 3 * JOGADOR_O) {
        return JOGADOR_O;
        }

    if (tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == 3 * JOGADOR_X) {
        return JOGADOR_X;
        }

    if (tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == 3 * JOGADOR_O) {
        return JOGADOR_O;
       }

    if (tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == 3 * JOGADOR_X) {
        return JOGADOR_X;
       }

    return VAZIO;
}