#ifndef PARTIDA_H
#define PARTIDA_H

#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorRemoto.h"

typedef struct {
    Tabuleiro tabuleiro;
    JogadorTeclado jogadorTeclado;  
    JogadorRemoto jogadorRemoto; 
} Partida;

void configuraJogadores(Partida *partida, int souServidor);

void inicia(Partida *partida);

#endif