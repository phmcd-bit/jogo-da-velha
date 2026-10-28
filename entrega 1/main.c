#include <stdio.h>
#include "tabuleiro.h"

int main() {
    Tabuleiro t;

    // 1. tabuleiro vazio: esperado 0
    inicializaTabuleiro(&t);
    printf("Vazio: %d (esperado 0)\n", temVencedor(&t));

    // 2. X na linha de baixo: esperado 4
    inicializaTabuleiro(&t);
    marcaJogada(&t, 2, 0, JOGADOR_X);
    marcaJogada(&t, 2, 1, JOGADOR_X);
    marcaJogada(&t, 2, 2, JOGADOR_X);
    printf("X linha 2: %d (esperado 4)\n", temVencedor(&t));

    // 3. O na coluna do meio: esperado 1
    inicializaTabuleiro(&t);
    marcaJogada(&t, 0, 1, JOGADOR_O);
    marcaJogada(&t, 1, 1, JOGADOR_O);
    marcaJogada(&t, 2, 1, JOGADOR_O);
    printf("O coluna 1: %d (esperado 1)\n", temVencedor(&t));

    // 4. X na diagonal principal: esperado 4
    inicializaTabuleiro(&t);
    marcaJogada(&t, 0, 0, JOGADOR_X);
    marcaJogada(&t, 1, 1, JOGADOR_X);
    marcaJogada(&t, 2, 2, JOGADOR_X);
    printf("X diagonal principal: %d (esperado 4)\n", temVencedor(&t));

    // 5. O na diagonal secundaria: esperado 1
    inicializaTabuleiro(&t);
    marcaJogada(&t, 0, 2, JOGADOR_O);
    marcaJogada(&t, 1, 1, JOGADOR_O);
    marcaJogada(&t, 2, 0, JOGADOR_O);
    printf("O diagonal secundaria: %d (esperado 1)\n", temVencedor(&t));

    // 6. duas marcas iguais e uma diferente na mesma linha: esperado 0
    inicializaTabuleiro(&t);
    marcaJogada(&t, 0, 0, JOGADOR_X);
    marcaJogada(&t, 0, 1, JOGADOR_X);
    marcaJogada(&t, 0, 2, JOGADOR_O);
    printf("X X O na linha 0: %d (esperado 0)\n", temVencedor(&t));

    return 0;
}