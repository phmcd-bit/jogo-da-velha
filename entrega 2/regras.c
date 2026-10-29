#include "regras.h"
#include <stdio.h>

int r1(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[0][j] + tabuleiro->M[1][j] + tabuleiro->M[2][j] == 2 * jogadorIA->tipo && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return 1;
            } else if (tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2] == 2 * jogadorIA->tipo && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return;
            } else if (i == j && tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == 2 * jogadorIA->tipo && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return 1;
            } else if (i + j == 2 && tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == 2 * jogadorIA->tipo && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[0][j] + tabuleiro->M[1][j] + tabuleiro->M[2][j] == 2 * jogadorHumano && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return 1;
            } else if (tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2] == 2 * jogadorHumano && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return;
            } else if (i == j && tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == 2 * jogadorHumano && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return 1;
            } else if (i + j == 2 && tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == 2 * jogadorHumano && tabuleiro->M[i][j] == VAZIO) {
                marcaJogada(tabuleiro, i, j, jogadorIA->tipo);
                return 1;
            }
        }
    }

    return 0;
}



int r2(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){
    
    return 0;
}

int r3(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){

    return 0;
}

int r4(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){
    int cantos[4][2] = {
        {0, 0},
        {0, 2},
        {2, 2},
        {2, 0}
    };

    for (int i = 0; i < 4; i++){
        int cantosLinha = cantos[i][0];
        int cantosColuna = cantos[i][1];

        int inversoLinha = 2 - cantosLinha;
        int inversoColuna = 2 - cantosColuna;

        if (tabuleiro->M[cantosLinha][cantosColuna] == jogadorHumano &&
            tabuleiro->M[inversoLinha][inversoColuna] == VAZIO) {
            marcaJogada(tabuleiro, inversoLinha, inversoColuna, jogadorIA->tipo);
            return 1;
        }
    }
    return 0; 
}

int r5(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){
    int cantos[4][2] = {
        {0, 0},
        {0, 2},
        {2, 2},
        {2, 0}
    };

    for (int i = 0; i < 4; i++){
        int linha = cantos[i][0];
        int coluna = cantos[i][1];

        if (tabuleiro->M[linha][coluna] == VAZIO) {
            marcaJogada(tabuleiro, linha, coluna, jogadorIA->tipo);
            return 1;
        }
    }
    return 0;
}

int r6(Tabuleiro *tabuleiro, JogadorIA *jogadorIA, int jogadorHumano){
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro->M[linha][coluna] == VAZIO) {
                marcaJogada(tabuleiro, linha, coluna, jogadorIA->tipo);
                return 1;
            }
        }
    }
    return 0;
}