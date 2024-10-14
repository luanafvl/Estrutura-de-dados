#include <stdio.h>
#include <locale.h>

//Este programa cria uma fila com funções de enqueue, dequeue e mostrar lista

int main() {

    setlocale(LC_ALL, "Portuguese");

    int fila[10];
    int opt=0;
    int aux=0;

    //Preenchendo a lista com o elemento "nulo"(0)
    //Se a posição i == 0, quer dizer que a posição da fila não está ocupada
    for (int i = 0; i < 10; i++) {
        fila[i] = 0;
    }
    printf("Serviços:\n");
    printf("(1) - Enqueue\n(2) - Dequeue\n(3) - Mostra fila\n(4) - Sair\n");
    scanf("%d", &opt);
    while (opt != 4) {

        switch (opt) {
            case 1:
                //Se a última posição do array fila estiver preenchida, ou seja, se for diferente de 0, quer dizer que
                //a fila está cheia e não é possível adicionar mais números
                if(fila[9]!=0)
                    printf("Lista cheia. Impossível adicionar outro número.\n");
                else {
                    printf("Insira um numero (diferente de 0):\n");
                    scanf("%d", &aux);
                    if(aux==0) {
                        printf("Número inválido.\n");
                    }
                    for (int i = 0; i < 10; i++) {
                        //Se a posição estiver preenchida, passa para a próxima
                        if (fila[i] != 0)
                            continue;
                        //Senão, a posição passa a valer o número informado
                        if (aux!=0)
                            fila[i] = aux;
                        break;
                    }
                }
                break;
            case 2:
                //Ao utilizar a função dequeue, removemos o primeiro elemento da lista, igualando-o a 0
                fila[0] = 0;
                    //Depois, reorganizamos a lista, passando o 0 para o final, já que um novo elemento só pode ser adicionado
                    //se a posição i for preenchida com o número 0
                    for (int i = 0; i < 10; i++)
                        for (int j = 1; j < 10-i-1; j++)
                            if(fila[j-1]==0) {
                                fila[j-1] = fila[j];
                                fila[j] = 0;
                            }
                break;
            case 3:
                //Se o primeiro elemento do array for 0, significa que a fila está vazia
                if (fila[0]==0) {
                    printf("Fila vazia!!!\n");
                } else {
                    for (int i = 0; i < 10; i++)
                        if (fila[i] != 0)
                            printf("%d\t", fila[i]);
                }
            default:
                break;
        }
        printf("\n(1) - Enqueue\n(2) - Dequeue\n(3) - Mostra fila\n(4) - Sair\n");
        scanf("%d", &opt);
        if (opt == 4)
            printf("Tchau!");
    }
}
