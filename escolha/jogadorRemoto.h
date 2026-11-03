#ifndef JOGADORREMOTO_H
#define JOGADORREMOTO_H

#include "tabuleiro.h"
#include <winsock2.h>

typedef struct {
    int tipo;
    SOCKET conexao;
} JogadorRemoto;

void jogaRemoto(JogadorRemoto *jogadorRemoto, Tabuleiro *tabuleiro);

void conecta(JogadorRemoto *jogadorRemoto, const char *endereco, int porta);

void aceita(JogadorRemoto *jogadorRemoto, int porta);

void enviaJogada(JogadorRemoto *jogadorRemoto, int linha, int coluna);

#endif