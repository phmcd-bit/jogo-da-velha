#include <stdio.h>
#include "jogadorIA.h"
#include "regras.h"

void jogaIA(JogadorIA *jogadorIA, Tabuleiro *tabuleiro){

    int jogadorHumano;

    if (jogadorIA->tipo == JOGADOR_O) {
        jogadorHumano = JOGADOR_X;
    } else {
        jogadorHumano = JOGADOR_O;
    }

    if (r1(tabuleiro, jogadorIA, jogadorHumano) == 1){
        return;
    }
    if (r2(tabuleiro, jogadorIA, jogadorHumano)== 1){
        return;
    }
    if (r3(tabuleiro, jogadorIA, jogadorHumano)== 1){
        return;
    }
    if (r4(tabuleiro, jogadorIA, jogadorHumano) == 1){
        return;
    }
    if (r5(tabuleiro, jogadorIA, jogadorHumano) == 1){
        return;
    }
    if (r6(tabuleiro, jogadorIA, jogadorHumano) == 1){
        return;
    }
}