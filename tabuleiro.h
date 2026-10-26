#ifndef TABULEIRO_H
#define TABULEIRO_H

#define VAZIO 0
#define JOGADOR_O 1
#define JOGADOR_X 4

typedef struct {
    int M[3][3];
} Tabuleiro;

void inicializaTabuleiro(Tabuleiro *tabuleiro);

void desenhaTabuleiro(Tabuleiro *tabuleiro);

void marcaJogada(Tabuleiro *tabuleiro, int linha, int coluna, int tipo);

int temVencedor(Tabuleiro *tabuleiro);

#endif
