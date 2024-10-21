#include <stdio.h>
#include <locale.h>

void EntradaValores(float *n1, float *n2) {
    //Entrada de dados
    printf("\nNumero 1: ");
    scanf("%f", &*n1);
    printf("\nNumero 2: ");
    scanf("%f", &*n2);
    printf("\n");
}


//Implementando funçoes e processando dados
void TrocarValores(float *n1, float *n2){
    float aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


float Soma (float n1, float n2) {
    return n1 + n2;
}


float Divisao(float n1,float n2) {
    if (n2 == 0)
        return 0;
    return n1/n2;
}


float Potencia(float n1, float n2, float potencia = 1){
    if (n2!=0)
        for (int i = n2; i > 0; i--)
            potencia*=n1;
    return potencia;
}


int main(){

	setlocale(LC_ALL, "Portuguese");

    int opt;
    float n1, n2;

    printf("================================");
    printf("\n   Bem-vindo(a) ao programa:    ");
    printf("\n  'Exercício com funções!'\n");
    printf("================================");

    printf("\n\nInsira os números para realizarmos as operações.\n");
    EntradaValores(&n1, &n2);

    do {
        printf("\nSelecione:");
        printf("\n(1) - Informar novos valores ");
        printf("\n(2) - Soma");
        printf("\n(3) - Divisão");
        printf("\n(4) - Potencia");
        printf("\n(5) - Troca dos valores");
        printf("\n(6) - Sair\n");
        scanf("%d",&opt);
        printf("\n");

        printf("Opção selecionada: ");
        switch (opt) {
            case 1:
                printf("(1) - Informar novos valores.\n");
                EntradaValores(&n1, &n2);
                break;
            case 2:
                printf("(2) - Soma.\n");
                printf("\n%.1f + %.1f = %.2f", n1, n2, Soma(n1, n2));
                break;
            case 3:
                printf("(3) - Divisao.\n");
                printf("\n%.1f / %.1f = %.2f", n1, n2, Divisao(n1, n2));
                break;
            case 4:
                printf("(4) - Potencia.\n");
                printf("\n%.1f ^ %.1f = %.2f", n1, n2, Potencia(n1, n2));
                break;
            case 5:
                printf("(5) - Troca dos valores.\n");
                // Para que a troca seja realizada corretamente, ao invés de utilizar
                // as variáveis como parâmetros, utilizamos os endereços delas
                TrocarValores(&n1, &n2);
                printf("\nValores trocados: %.1f  %.1f", n1, n2);
                break;
            case 6:
                printf("(6) - Sair.\n");
                break;
            default:
                printf("Opção inválida.");
        }
        printf("\n");
    } while (opt != 6);

    printf("\n-------------------");
    printf("\nPrograma encerrado!");
    printf("\n-------------------");
}
