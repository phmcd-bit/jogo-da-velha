#include <stdio.h>
#include "jogadorIA.h"


void jogaIA(JogadorIA *jogadorIA, Tabuleiro *tabuleiro){

    int jogadorHumano;

    if (jogadorIA->tipo == 1) {
        jogadorHumano = 4;
    } else {
        jogadorHumano = 1;
    }

    //r1

    //r2

    //r3

    //r4
    int cantosLinha, cantosColuna, inversoLinha, inversoColuna;

    int cantos[4][2] = {
        {0, 0},
        {0, 2},
        {2, 2},
        {2, 0}
    };

    for (int i = 0; i < 4; i++){
        cantosLinha = cantos[i][0];
        cantosColuna = cantos[i][1];

        if (cantosLinha == 0) {
            inversoLinha = 2;
        } else {
            inversoLinha = 0;
        }

        if (cantosColuna == 0) {
            inversoColuna = 2;
        } else {
            inversoColuna = 0;
        }

        if (tabuleiro->M[cantosLinha][cantosColuna] == jogadorHumano && tabuleiro->M[inversoLinha][inversoColuna] == VAZIO) {
            marcaJogada(tabuleiro, inversoLinha, inversoColuna, jogadorIA->tipo);
            return; 
        }
    }
    
    //r5
       for (int i = 0; i < 4; i++) {
        
        int cantosLinha = cantos[i][0];
        int cantosColuna = cantos[i][1];

        if (tabuleiro->M[cantosLinha][cantosColuna] == VAZIO) {
            marcaJogada(tabuleiro, cantosLinha, cantosColuna, jogadorIA->tipo);
            return;
        }

    //r6
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro->M[linha][coluna] == VAZIO) {
                marcaJogada(tabuleiro, linha, coluna, jogadorIA->tipo);
                return;
            }
        }
    }
}