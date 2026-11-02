#include <stdio.h>
#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "partida.h"

int main() {
    Partida partida;
    configuraJogadores(&partida);
    inicia(&partida);
    return 0;
}
