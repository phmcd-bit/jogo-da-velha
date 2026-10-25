#include "tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro->M[i][j] = VAZIO;
        }
    }
}
 
