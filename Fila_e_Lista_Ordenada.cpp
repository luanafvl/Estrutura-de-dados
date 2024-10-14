#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Este programa cria Filas e Listas Ordenadas estáticas

// A Lista Ordenada organiza seu conteudo em ordem crescente na hora da inserção
// Já a fila, utiliza o metodo FIFO, ou seja o conteudo dela é apresentado em ordem de entrada,
// onde o primeiro a entrar é o primeiro a sair

//Verifica se a lista ou fila está cheia
bool ArrayCheio(int array[], int tamArray) {
    int cheio = false;
    int contCheio = 0;

    for (int i = 0; i < tamArray; i++) {
        if (array[i] == -1)
            contCheio++;
    }

    if(contCheio == 0)
        cheio = true;

    return cheio;
}

//Verifica se a lista ou fila está vazia
bool ArrayVazio(int array[], int tamArray) {
    int vazio = false;
    int contVazio = 0;
    for (int i = 0; i < tamArray; i++) {
        if (array[i] == -1)
            contVazio++;
    }

    if(contVazio == tamArray)
        vazio = true;

    return vazio;
}

//Alocando os espaços "nulos" no array
int* criarArray(int array[], int tamArray) {
    for (int i=0; i<tamArray; i++)
        array[i]=-1;
    return array;
}

//Funcao para criar fila
void funcFila() {
    //A variavel tipo diferencia a lista da fila
    int tamFila, tipo = 0;
    do {
        printf("Informe o tamanho da fila: ");
        scanf("%d", &tamFila);
    } while (tamFila <= 0);

    int auxFila[tamFila];
    int aux, resposta=0;

    int *fila = criarArray(auxFila, tamFila);

    while (resposta!=4) {

    printf("\n Operacoes em Filas:");
    printf("\n (1) - Enqueue");
    printf("\n (2) - Dequeue");
    printf("\n (3) - Mostra fila");
    printf("\n (4) - Sair");
    printf("\n Digite a opcao: ");
    scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                if (ArrayCheio(fila, tamFila))
                    printf("\n Fila cheia! Impossivel adicionar outro numero");
                else {
                    printf(" Insira um numero (diferente de -1): ");
                    scanf("%d", &aux);
                    if (aux==-1)
                        printf(" Numero invalido!");
                    else
                      for (int i=0; i<tamFila; i++) {
                        //Se a posicao estiver preenchida, passa para a proxima
                        if (fila[i] != -1)
                            continue;
                        //Senao, a posicao passa a valer o numero informado
                        fila[i] = aux;
                        printf("\n Elemento %i inserido com sucesso na posicao %i", aux, i);
                        break;
                    }
                }
                break;
            case 2:
                if (ArrayVazio(fila, tamFila)) {
                    printf("\n Fila vazia!");
                } else {
                    printf("\n Elemento %i retirado da Fila na posicao zero!", fila[0]);
                    //Ao utilizar a funcao dequeue, removemos o primeiro elemento da lista, igualando-o a -1
                    fila[0]=-1;
                    //Depois, reorganizamos a lista, passando o -1 para o final, ja que um novo elemento so pode ser adicionado
                    //se a posicao i for preenchida com o numero -1
                    for (int j=1; j<tamFila-1; j++)
                        if (fila[j-1]==-1) {
                            fila[j-1]=fila[j];
                            fila[j]=-1;
                        }
                        else
                            break;
                }
                break;
            case 3:
                //Se o primeiro elemento do array for -1, significa que a fila esta vazia
                if (ArrayVazio(fila, tamFila)) {
                    printf("\n Fila vazia!!!\n");
                } else {
                	  printf("\n Fila: [");
                    for (int i = 0; i < tamFila; i++)
                        if (fila[i] != -1)
                            printf(" %d ", fila[i]);
                    printf("]. \n");
                }
                break;
            default:
                printf("\n Operacao invalida!");
                break;
        }
    }
}

void funcLista() {

    int auxMenor=0, tamLista, resposta=0, numero, cont=0;

    printf("Informe o tamanho da lista: ");
    scanf("%d", &tamLista);

    int ultimoIndice = tamLista-1;

    int auxLista[tamLista], *lista = criarArray(auxLista, tamLista);

    while (resposta<5) {
        printf("\n Operacoes em Listas Ordenadas:");
        printf("\n (1) - Ins");
        printf("\n (2) - Rem");
        printf("\n (3) - Find");
        printf("\n (4) - Mostrar lista");
        printf("\n (5) - Sair");
        printf("\n Digite a opcao: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                if (ArrayCheio(lista, tamLista)) {
                    printf("\n Lista cheia!");
                } else {
                    ultimoIndice--;
                    printf("Número a ser inserido: ");
                    scanf("%d", &numero);
                    //Se estiver vazia, o ultimo elemento vira o numero informado
                    if (lista[tamLista-1] == -1)
                        lista[tamLista-1] = numero;
                    // Senão, vamos procurar até encontrar um número menor que o informado
                    else {
                        int posicao = 0;
                        for (int i = tamLista-1; i >= 0; i--) {
                            // Se encontrarmos, a posição do número informado será aquela onde está o
                            // "primeiro número menor que ele"
                            if (lista[i] != -1 && lista[i] < numero) {
                                posicao = i;
                                break;
                            }
                            // Essa condição verifica se o número de entrada é o menor dentre todos os já existentes na lista
                            if (lista[i] > numero && lista[i-1] == -1) {
                                posicao = i-2;
                                break;
                            }
                        }

                        // Este caso serve especificamente para quando a condição acima for atingida
                        if (lista[posicao+1] == -1) {
                            for(int i=posicao; i<tamLista-1; i++) {
                                if (lista[i+1] == -1) {
                                    lista[i+1] = numero;
                                    lista[i] = -1;
                                }
                            }
                        } else {
                            // Nesta condição, verificamos se o número anterior é o "nulo"
                            // Se não for, temos que levar todos os elementos - a partir do "primeiro menor" em relação
                            // ao numero de entrada - para a esquerda
                            if (lista[posicao-1] != -1) {
                                // O "último índice" é o primeiro valor não nulo do Array (da esquerda para a direita)
                                for (int i = ultimoIndice; i <= posicao; i++) {
                                    lista[i-1] = lista[i];
                                }
                                // Assim que os elementos forem levados para a esquerda, podemos colocar o número de entrada
                                // em seu devido lugar
                                lista[posicao] = numero;

                            } else {
                                for (int i = posicao; i > 0; i--) {
                                    if (lista[i-1] != -1) {
                                        auxMenor = lista[i];
                                        lista[i] = lista[i-1];
                                        lista[i-1] = auxMenor;
                                    } else {
                                        lista[i-1] = lista[i];
                                        break;
                                    }
                                }
                                lista[posicao] = numero;
                            }
                        }
                    }
                }

                break;
            case 2:
                cont=0;
                int posicao;

                if(ArrayVazio(lista, tamLista)) {
                    printf("\n Lista vazia!");
                } else {
                    ultimoIndice++;
                    //Removendo o número especificado da lista, apenas se ele existir nela
                    printf("Número a ser removido: ");
                    scanf("%d", &numero);
                    for (int i=0; i<tamLista; i++) {
                        if (lista[i] == numero) {
                            lista[i] = -1;
                            cont++;
                            posicao = i;
                            break;
                        }
                    }

                    if (cont==1){
                        printf("Numero %d removido da posição %d", numero, posicao);
                        for(int j=0; j<tamLista-2; j++) {
                            if (lista[j+1] == -1) {
                                lista[j+1] = lista[j];
                                lista[j] = -1;
                            }
                        }
                    } else {
                        printf("\n O número %d não está na lista!", numero);
                    }
                }
                break;
            case 3:
                if(ArrayVazio(lista, tamLista)) {
                    printf("\n Lista vazia!");
                } else {
                    cont=0;
                    printf("Número a ser buscado: ");
                    scanf("%d", &numero);
                    for (int i=0; i<tamLista; i++)
                        if (lista[i] == numero)
                            cont++;

                    if (cont==0)
                        printf("O número %d não está na lista!", numero);
                    else {
                        printf("O número %i está na posição: ", numero);
                        for (int i=0; i<tamLista; i++) {
                            if (lista[i] == numero){
                                printf("%d", i);
                            }
                        }
                    }
                }

                break;
            case 4:
                if (ArrayVazio(lista, tamLista)) {
                    printf("\n Lista vazia!");
                } else {
                    for (int i=0; i<tamLista; i++) {
                        if (lista[i] != -1)
                            printf(" %i", lista[i]);
                    }
                }

                break;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int servico;

    printf("Bem-vindo(a)!\n");

    do{
        printf("Escolha um serviço:");
        printf("\n(1) - Fila");
        printf("\n(2) - Lista ordenada");
        printf("\n(3) - Sair\n");
        scanf("%d", &servico);

        switch (servico) {
            case 1:
                funcFila();
                break;
            case 2:
                funcLista();
                break;
            case 3:
                printf("Serviço finalizado.");
                break;
            default:
                printf("\nServiço inválido\n\n");
        }
    } while (servico != 3);
}

