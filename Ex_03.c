#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 5
#define LINE_SIZE 200

struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[4];
    char cep[15];
};

struct Cadastro {
    char nome[100];
    struct Endereco end;
    float salario;
    char identidade[30];
    char cpf[30];
    char estadoCivil[30];
    char telefone[30];
    int idade;
    char sexo;
};

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        
        buffer[0] = '\0';
    }
}

int toInt(const char *s) {
    return (int)strtol(s, NULL, 10);
}

float toFloat(const char *s) {
    return strtof(s, NULL);
}

int main() {
    struct Cadastro pessoas[TAM];
    char line[LINE_SIZE];
    int i;

    printf("=== CADASTRAMENTO DE %d PESSOAS ===\n\n", TAM);

    for (i = 0; i < TAM; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1);

        printf("Nome: ");
        readLine(pessoas[i].nome, sizeof(pessoas[i].nome));

        printf("Identidade: ");
        readLine(pessoas[i].identidade, sizeof(pessoas[i].identidade));

        printf("CPF: ");
        readLine(pessoas[i].cpf, sizeof(pessoas[i].cpf));

        printf("Estado Civil: ");
        readLine(pessoas[i].estadoCivil, sizeof(pessoas[i].estadoCivil));

        printf("Telefone: ");
        readLine(pessoas[i].telefone, sizeof(pessoas[i].telefone));

        printf("Idade: ");
        readLine(line, LINE_SIZE);
        pessoas[i].idade = toInt(line);

        printf("Sexo (M/F): ");
        readLine(line, LINE_SIZE);
        pessoas[i].sexo = (line[0] != '\0') ? line[0] : '?';

        printf("Salario (use . como separador): ");
        readLine(line, LINE_SIZE);
        pessoas[i].salario = toFloat(line);

        printf("Rua: ");
        readLine(pessoas[i].end.rua, sizeof(pessoas[i].end.rua));

        printf("Bairro: ");
        readLine(pessoas[i].end.bairro, sizeof(pessoas[i].end.bairro));

        printf("Cidade: ");
        readLine(pessoas[i].end.cidade, sizeof(pessoas[i].end.cidade));

        printf("Estado (UF): ");
        readLine(pessoas[i].end.estado, sizeof(pessoas[i].end.estado));

        printf("CEP: ");
        readLine(pessoas[i].end.cep, sizeof(pessoas[i].end.cep));
    }

    int idxMaiorIdade = 0;
    for (i = 1; i < TAM; i++) {
        if (pessoas[i].idade > pessoas[idxMaiorIdade].idade) {
            idxMaiorIdade = i;
        }
    }

    printf("\n=== PESSOA COM MAIOR IDADE ===\n");
    printf("Nome: %s | Idade: %d\n", pessoas[idxMaiorIdade].nome, pessoas[idxMaiorIdade].idade);

    printf("\n=== PESSOAS DO SEXO MASCULINO ===\n");
    for (i = 0; i < TAM; i++) {
        if (pessoas[i].sexo == 'M' || pessoas[i].sexo == 'm') {
            printf("Nome: %s | Sexo: %c\n", pessoas[i].nome, pessoas[i].sexo);
        }
    }

    printf("\n=== PESSOAS COM SALARIO > 1000 ===\n");
    for (i = 0; i < TAM; i++) {
        if (pessoas[i].salario > 1000.0f) {
            printf("Nome: %s | Salario: %.2f\n", pessoas[i].nome, pessoas[i].salario);
        }
    }

    char buscaID[30];
    int achou = 0;

    printf("\nDigite uma identidade para buscar: ");
    readLine(buscaID, sizeof(buscaID));

    printf("\n=== RESULTADO DA BUSCA ===\n");
    for (i = 0; i < TAM; i++) {
        if (strcmp(pessoas[i].identidade, buscaID) == 0) {
            achou = 1;
            printf("\n-- Pessoa encontrada --\n");
            printf("Nome: %s\n", pessoas[i].nome);
            printf("CPF: %s\n", pessoas[i].cpf);
            printf("Idade: %d\n", pessoas[i].idade);
            printf("Sexo: %c\n", pessoas[i].sexo);
            printf("Salario: %.2f\n", pessoas[i].salario);
            printf("Endereco: %s, %s, %s - %s. CEP: %s\n\n\n\n\n",
                   pessoas[i].end.rua,
                   pessoas[i].end.bairro,
                   pessoas[i].end.cidade,
                   pessoas[i].end.estado,
                   pessoas[i].end.cep);
        }
    }

    if (!achou)
        printf("Nenhuma pessoa encontrada com essa identidade.\n");

    return 0;
}
