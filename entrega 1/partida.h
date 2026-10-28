#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"

void configuraJogadores(JogadorTeclado *jogador1, JogadorTeclado *jogador2);
void inicia(Tabuleiro *tabuleiro, JogadorTeclado *jogador1, JogadorTeclado *jogador2);

#endif