#include <stdio.h>
#include <locale.h>


float* criarPilha(float pilha[], int tam) {
    for (int i = 0; i < tam; i++) {
        pilha[i] = -1;
    }
    return pilha;
}


bool pilhaVazia(float* pilha) {
    bool vazia = false;
        if (pilha[0] == -1)
            vazia = true;
    return vazia;
}

bool pilhaCheia(float* pilha, int tam) {
    bool cheia = false;
        if (pilha[tam-1] != -1)
            cheia = true;
    return cheia;
}

float* ins(float* pilha, int tam) {
    float numero;
    printf("Numero a ser inserido: \n");
    scanf("%f", &numero);
    int ultimoElemento = tam-1;

    for (int i = 0; i < tam; i++)
        if (pilha[i] != -1)
            ultimoElemento = i;

    for (int i = ultimoElemento; i >= 0; i--)
        pilha[i+1] = pilha[i];

    pilha[0] = numero;
    return pilha;
}

float* rem(float* pilha, int tam) {
    pilha[0] = -1;
    int ultimoElemento = tam-1;
    for (int i = 0; i < tam; i++)
        if (pilha[i] != -1)
            ultimoElemento = i;
    for (int i = 1; i < tam; i++)
        if (pilha[i] != -1)
            pilha[i-1] = pilha[i];
    pilha[ultimoElemento] = -1;
    return pilha;
}

void imprimir(float* pilha, int tam) {
    for (int i = 0; i < tam; i++)
        if (pilha[i] != -1)
            printf("%.1f  ", pilha[i]);
    printf("\n");
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int tam;
    printf("Tamanho pilha: ");
    scanf("%d", &tam);

    float auxPilha[tam];

    float* pilha = criarPilha(auxPilha, tam);

    int opt = 0;
    while (opt!=5) {
        printf("Escolha um serviço:\n");
        printf("(1) - Ins\n(2) - Rem\n(3) - Top\n(4) - Mostrar Pilha\n(5) - Sair\n");
        scanf("%d", &opt);

        printf("Opção escolhida: ");
        switch (opt) {
            case 1:
                printf("Inserir elemento\n");
            if (pilhaCheia(pilha, tam))
                printf("Pilha cheia! Impossível inserir novo elemento.\n");
            else
                pilha = ins(pilha, tam);
                break;
            case 2:
                printf("Remover elemento\n");
                if (pilhaVazia(pilha))
                    printf("Pilha vazia! Não é possível remover elementos.\n");
                else
                    pilha = rem(pilha, tam);
                    break;
            case 3:
                printf("Top element\n");
                if (pilhaVazia(pilha))
                    printf("Pilha vazia! Não há elementos no topo da pilha.\n");
                else
                    printf("%.1f", pilha[0]);
                    printf("\n");
                break;
            case 4:
                printf("Mostrar Pilha\n");
                if (pilhaVazia(pilha))
                    printf("Pilha vazia!\n");
                else
                    imprimir(pilha, tam);
                break;
            case 5:
                printf("Sair\n");
                break;
            default:
                printf("Opção inválida");
        }
    }
    printf("\nServiço encerrado.");
}
