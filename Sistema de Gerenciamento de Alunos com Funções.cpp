#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define alunos 10
#define numnotas 3

char nomes[alunos][50];
float notas[alunos][numnotas],medias[alunos];
int numalunos=0;

void adicionarAluno(){
    if (numalunos >= alunos){
        printf("Limite de alunos atingido.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nomes[numalunos]);

    for (int i = 0; i < numnotas; i++){
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[numalunos][i]);
    }

    numalunos++;
    printf("Aluno adicionado!\n");
}

float calcularmedia(int index){
    float soma = 0;
    for (int i = 0; i < numnotas; i++){
        soma += notas[index][i];
    }
    medias[index] = soma / numnotas;
    return medias[index];
}

void exibirmedias(){
    for (int i = 0; i < numalunos; i++){
        float media = calcularmedia(i);
        printf("Aluno: %s, Media: %.2f\n", nomes[i], media);
    }
}

void exibiralunos(){
    for (int i=0;i<numalunos;i++){
        printf("Aluno: %s\n", nomes[i]);
        for (int j=0;j<numnotas;j++) {
            printf("Nota %d: %.2f\n",j+1,notas[i][j]);
        }
        printf("Media: %.2f\n", calcularmedia(i));
    }
}

void alunomaiorMedia(){
    if (numalunos == 0){
        printf("Nenhum aluno cadastrado.\n");
        
    }

    int indexMaior = 0;
    for (int i = 1; i < numalunos; i++){
        if (calcularmedia(i) > calcularmedia(indexMaior)){
            indexMaior = i;
        }
    }

    printf("Aluno com maior media: %s, Media: %.2f\n", nomes[indexMaior], calcularmedia(indexMaior));
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int op;
    do{
        printf("1. Adicionar aluno e notas\n2. Calcular e exibir a media de cada aluno\n3. Exibir todos os alunos\n4. Exibir o aluno com maior media\n5. Sair do programa\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                adicionarAluno();
                break;
            case 2:
                exibirmedias();
                break;
            case 3:
                exibiralunos();
                break;
            case 4:
                alunomaiorMedia();
                break;
            case 5:
                printf("Voce saiu.\n");
                break;
            default:
                printf("Opcaoo invalida. Tente novamente.\n");
        }
    }while (op != 5);
}
