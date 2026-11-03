#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorIA.h"
#include "jogadorRemoto.h"

#define PESSOA_VS_PESSOA 1
#define PESSOA_VS_IA     2
#define PESSOA_SERVIDOR  3
#define PESSOA_CLIENTE   4

typedef struct {
    Tabuleiro tabuleiro;
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    JogadorIA jogadorIA;
    JogadorRemoto jogadorRemoto;
    int escolha;
} Partida;

void configuraJogadores(Partida *partida);

void inicia(Partida *partida);

#endif