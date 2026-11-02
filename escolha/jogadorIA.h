#ifndef JOGADORIA_H
#define JOGADORIA_H
#include "tabuleiro.h"

typedef struct{
    int tipo;
} JogadorIA;

void jogaIA(JogadorIA *jogadorIA, Tabuleiro *tabuleiro);

#endif