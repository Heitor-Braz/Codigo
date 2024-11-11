#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int matriz[4][4];

    printf("Preencha a matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Valores nas coordenadas iguais:\n");
    for (int i = 0; i < 4; i++) {
        printf("matriz[%d][%d] = %d\n", i, i, matriz[i][i]);
    }
}

