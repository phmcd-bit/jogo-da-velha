#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H

#include "Tabuleiro.h"

typedef struct {
    int tipo;
} JogadorTeclado;

void joga(JogadorTeclado *jogador, Tabuleiro *tabuleiro);

#endif