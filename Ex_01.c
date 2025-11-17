#include <stdlib.h>
#include <stdio.h>

#define TAM 20

struct Profissao {
    int codigo;
    char nome[50];
};

int main() {

    int codigoDigitado;
    int encontrado = 0;


    printf("Digite o código da profissão (1 a 20): ");
    scanf("%d", &codigoDigitado);

    struct Profissao lista[TAM] = {
        {1,  "Medico"},
        {2,  "Enfermeiro"},
        {3,  "Professor"},
        {4,  "Engenheiro"},
        {5,  "Advogado"},
        {6,  "Pro Player"},
        {7,  "Motorista"},
        {8,  "Pedreiro"},
        {9,  "Eletricista"},
        {10, "Mecanico"},
        {11, "Garoto de Programa"},
        {12, "Diretor"},
        {13, "Presidente Corrupto"},
        {14, "Designer"},
        {15, "Garcom"},
        {16, "Auxiliar de Escritorio"},
        {17, "Cozinheiro"},
        {18, "Faxineiro"},
        {19, "Frentista"},
        {20, "Traficante"}
    };

    for (int i = 0; i < TAM; i++) {
        if (lista[i].codigo == codigoDigitado) {
            printf("\nProfissão correspondente: %s\n\n\n\n\n", lista[i].nome);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Código não encontrado!\n");
    }

    return 0;
}
