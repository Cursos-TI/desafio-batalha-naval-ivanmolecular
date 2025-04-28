#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    printf("##Tabuleiro de batalha naval##"); //Cabecalho / Titulo do jogo
    // Inicializa o tabuleiro com agua (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 7;

    // Validacao para garantir que os navios estejam dentro do tabuleiro
    if (coluna_horizontal + 2 >= 10 || linha_vertical + 2 >= 10) {
        printf("Erro: Coordenadas invalidas para os navios!\n");
        return 1;
    }

    // Posiciona o navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posiciona o navio vertical (verificando se nao ha sobreposicao)
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
            printf("Erro: Sobreposicao de navios!\n");
            return 1;
        }
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Exibe o cabecalho das colunas (letras de A ate J)
    printf("\n  "); // Espaco para alinhar os numeros das linhas
    for (j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Exibe o tabuleiro com numeracao das linhas
    for (i = 0; i < 10; i++) {
        printf("%2d", i + 1); // Numeros de 1 ate 10 alinhados
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
