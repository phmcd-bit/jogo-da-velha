#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"

#define PESSOA_VS_PESSOA 1
#define PESSOA_VS_IA     2

typedef struct {
    Tabuleiro tabuleiro;
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    JogadorIA jogadorIA;
    int escolha;
} Partida;

void configuraJogadores(Partida *partida);

void inicia(Partida *partida);

#endif