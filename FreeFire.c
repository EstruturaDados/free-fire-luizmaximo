#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=== Menu da Mochila ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Adicionar item
                if (totalItens >= MAX_ITENS) {
                    printf("A mochila esta cheia!\n");
                } else {
                    printf("Digite o nome do item: ");
                    scanf(" %[^\n]", mochila[totalItens].nome);
                    printf("Digite o tipo do item: ");
                    scanf(" %[^\n]", mochila[totalItens].tipo);
                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2: // Remover item
                if (totalItens == 0) {
                    printf("A mochila esta vazia!\n");
                } else {
                    char nomeRemover[30];
                    printf("Digite o nome do item a remover: ");
                    scanf(" %[^\n]", nomeRemover);

                    int encontrado = 0;
                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Desloca os itens restantes
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Item nao encontrado!\n");
                    }
                }
                break;

            case 3: // Listar itens
                if (totalItens == 0) {
                    printf("A mochila esta vazia!\n");
                } else {
                    printf("\n%-20s %-15s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("------------------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
