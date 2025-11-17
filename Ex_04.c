#include <stdlib.h>
#include <stdio.h>

#define TAM 5

struct Aluno {
    char nome[50];
    int matricula;
    char curso[50];
};

int main() {
    struct Aluno alunos[TAM];
    int i;


    printf("===== CADASTRO DE ALUNOS =====\n");

    for (i = 0; i < TAM; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Nome (sem espacos): ");
        scanf("%s", alunos[i].nome);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Curso (sem espacos): ");
        scanf("%s", alunos[i].curso);
    }


    printf("\n\n===== LISTA COMPLETA DE ALUNOS =====\n");

    for (i = 0; i < TAM; i++) {
        printf("\n------------------------------\n");
        printf("Aluno %d\n", i + 1);
        printf("Nome     : %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso    : %s\n", alunos[i].curso);
    }

    printf("\n------------------------------\n");
    printf("Fim da listagem.\n\n\n\n\n");

    return 0;
}
