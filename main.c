#include "ListaCircular.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    
    int opc,num,pos;
    char nome[30];

    do
    {
        switch (opc)
        {
            printf("Selecione uma opção:\n");
            printf("1  - Criar lista\n");
            printf("2  - Adicionar no final da lista\n");
            printf("3  - Adicionar no inicio da lista\n");
            printf("4  - Adicionar na posição\n");
            printf("5  - Remover no final da lista\n");
            printf("6  - Remover no inicio da lista\n");
            printf("7  - Remover na posição\n");
            printf("8  - Imprimir lista\n");
            printf("9  - Verificar lista\n");
            printf("10 - Limpar lista\n");
            printf("11 - Sair\n");
        case 1:
            Lista* l = criar_lista();
            break;
        case 2:
            printf("Digite um nome:\n");
            scanf("%s",&nome);
            printf("Digite um valor:\n");
            scanf("%d",&num);

            adicionar_elemento(l,nome,num);

            break;
        case 3:
            printf("Digite um nome:\n");
            scanf("%s",&nome);
            printf("Digite um valor:\n");
            scanf("%d",&num);

            adicionar_inicio(l,nome,num);

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            remover_inicio(l);
            break;
        case 7:
            printf("Digite a posição a ser removida:\n");
            scanf("%d",&pos);
            remover_pos(l,pos);
            break;
        case 8:
            print_lista(l);
            break;
        case 9:
            if(lista_vazia(l)){
                printf("Lista vazia");
            }else printf("A lista possui %d elementos.",tamanho_lista(l));
            break;
        case 10:
            finalizar_lista(l);
            break;
        case 11:
            break;
        
        default:
            break;
        }
    } while (opc < 11);
    

    return;
}