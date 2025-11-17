#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct Imovel {
    int identificacao;
    float valorImposto;
    int mesesAtraso;
    float multa;
};

float calcularMulta(float valor, int meses) {
    float percentual;

    if (valor <= 500)
        percentual = 1;
    else if (valor <= 1800)
        percentual = 2;
    else if (valor <= 5000)
        percentual = 4;
    else if (valor <= 12000)
        percentual = 7;
    else
        percentual = 10;

    return valor * (percentual / 100.0f) * meses;
}

int main() {

    struct Imovel lista[MAX];
    int quantidade = 0;
    char continuar;

    printf("Cadastro de imoveis em atraso\n");

    do {
        if (quantidade >= MAX) {
            printf("Limite maximo de registros atingido!\n");
            break;
        }

        printf("\n--- Imovel %d ---\n", quantidade + 1);
        printf("\nIdentificação do imovel: ");
        scanf("%d", &lista[quantidade].identificacao);

        printf("Valor do imposto (R$): ");
        scanf("%f", &lista[quantidade].valorImposto);

        printf("Meses em atraso: ");
        scanf("%d", &lista[quantidade].mesesAtraso);

        lista[quantidade].multa =
            calcularMulta(lista[quantidade].valorImposto,
                          lista[quantidade].mesesAtraso);

        quantidade++;

        printf("Deseja cadastrar outro imovel? (s/n): ");
        getchar();
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\n\n--- RELATORIO FINAL ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("\nImovel %d\n", i + 1);
        printf("Identificacao: %d\n", lista[i].identificacao);
        printf("Valor do imposto: R$ %.2f\n", lista[i].valorImposto);
        printf("Meses em atraso: %d\n", lista[i].mesesAtraso);
        printf("Multa a pagar: R$ %.2f\n\n\n\n\n\n", lista[i].multa);
    }

    return 0;
}
