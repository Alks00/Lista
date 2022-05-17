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
        
        default:
            break;
        }
    } while (opc < 11);
    

    return;
}