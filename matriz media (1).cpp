#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int matriz[4][4], somaImpares = 0, contadorImpares = 0;
    float mediaImpares;

    printf("Preencha a matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] % 2 != 0) {
                somaImpares += matriz[i][j];
                contadorImpares++;
            }
        }
    }

    if (contadorImpares > 0) {
        mediaImpares = (float)somaImpares / contadorImpares;
        printf("A média dos valores ímpares é: %.2f\n", mediaImpares);
    } else {
        printf("Não há valores ímpares na matriz.\n");
    }
}

