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

    // -------- Cone com base na posicao (0, 2) (coluna C, linha 1) --------
    int cone_i = 0;
    int cone_j = 2;
    for (i = 0; i < 3; i++) {
        for (j = -i; j <= i; j++) {
            int x = cone_i + i;
            int y = cone_j + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                tabuleiro[x][y] = 3;
            }
        }
    }

    // -------- Cruz com centro em (4, 5) (coluna F, linha 5) --------
    int cruz_i = 4;
    int cruz_j = 5;
    for (i = cruz_i - 2; i <= cruz_i + 2; i++) {
        if (i >= 0 && i < 10) {
            tabuleiro[i][cruz_j] = 3;
        }
    }
    for (j = cruz_j - 2; j <= cruz_j + 2; j++) {
        if (j >= 0 && j < 10) {
            tabuleiro[cruz_i][j] = 3;
        }
    }

    // -------- Octaedro com centro em (7, 1) (coluna B, linha 8) --------
    int oct_i = 7;
    int oct_j = 1;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            int soma = i + j;
            int dif = i - j;
            if ((soma >= oct_i + oct_j - 2) && (soma <= oct_i + oct_j + 2) &&
                (dif >= oct_i - oct_j - 2) && (dif <= oct_i - oct_j + 2)) {
                if (tabuleiro[i][j] == 0) {
                    tabuleiro[i][j] = 3;
                }
            }
        }
    }

    // Exibe o cabecalho das colunas (letras de A ate J)
    printf("\n     ");
    for (j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Exibe o tabuleiro com numeracao das linhas
    for (i = 0; i < 10; i++) {
        printf("%2d   ", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
