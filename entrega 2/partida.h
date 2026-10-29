#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"

typedef struct {
    Tabuleiro tabuleiro;
    JogadorTeclado jogador1;
    JogadorIA jogador2;
} Partida;

void configuraJogadores(Partida *partida);

void inicia(Partida *partida);

#endif