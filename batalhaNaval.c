#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    printf("## Tabuleiro de Batalha Naval ##\n");

    // Inicializa o tabuleiro com agua (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- Posicionamento dos navios conforme pedido ---

    // Navio diagonal \ de A1 ate C3
    tabuleiro[0][0] = 3; // A1
    tabuleiro[1][1] = 3; // B2
    tabuleiro[2][2] = 3; // C3

    // Navio horizontal de F3 ate H3
    tabuleiro[2][5] = 3; // F3
    tabuleiro[2][6] = 3; // G3
    tabuleiro[2][7] = 3; // H3

    // Navio vertical de D5 ate D7
    tabuleiro[4][3] = 3; // D5
    tabuleiro[5][3] = 3; // D6
    tabuleiro[6][3] = 3; // D7

    // Navio diagonal / de H7 ate J9
    tabuleiro[6][7] = 3; // H7
    tabuleiro[7][8] = 3; // I8
    tabuleiro[8][9] = 3; // J9

    // Exibe o cabecalho das colunas (letras de A ate J)
    printf("\n   ");
    for (j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Exibe o tabuleiro com numeração das linhas
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
