#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

/*typedef struct elemento
{
    char nome[30];
    int num;
    struct elemento *prox;
    
}Elemento;

typedef struct lista
{
    int tam;
    Elemento *inicio;
    Elemento *fim;
}Lista;

Lista* criar_lista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista -> tam = 0;
    lista -> inicio = NULL;
    lista -> fim = NULL;
    return lista;
}

int lista_vazia(Lista* lista){
    return(lista -> inicio == NULL);
}

void adicionar_elemento(Lista* lista,char *nome,int n){
    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));
    strcpy(elemento -> nome,nome);
    elemento -> num = n;

    if (lista_vazia(lista))
    {
        lista -> inicio = elemento;
        lista -> fim = elemento;
        lista -> tam++;
        elemento -> prox = NULL;
    }else if (lista -> tam == 1)
    {
        lista -> inicio -> prox = elemento;
        lista -> fim = elemento;
        elemento -> prox = lista -> inicio;
        lista -> tam++;
    }else
    {
        elemento -> prox = lista -> inicio;
        lista -> fim -> prox = elemento;
        lista -> fim = elemento;
        lista -> tam++;
    }
}

void print_lista(Lista* lista){
    Elemento* aux = lista -> inicio;
    printf("-%d ", aux -> num);
    printf("%s\n", aux -> nome);
    aux = aux -> prox;
    while (aux != lista -> inicio)
    {
        printf("-%d ", aux -> num);
        printf("%s\n", aux -> nome);
        aux = aux -> prox;
    }
}

void remover_pos(Lista* lista,int pos){
    Elemento* aux = lista -> inicio;
    Elemento* aux1 = NULL;
    if(pos > lista -> tam){
        printf("Posição não existe!\n");
    }else if (lista_vazia(lista))
    {
        printf("Lista vazia.\n");
    }else if (lista -> tam == 1)
    {
        printf("(%d ", aux -> num);
        printf("%s) Removido da lista!\n", aux -> nome);
        free(aux);
        lista -> tam--;
    }else
    {
        for(int i=1;i<pos;i++){
            aux1 = aux;
            aux = aux -> prox;
        }
        printf("(%d ", aux -> num);
        printf("%s) Removido da lista!\n", aux -> nome);
        aux1 -> prox = aux -> prox;
        free(aux);
        lista -> tam--;
    }
}

void adicionar_inicio(Lista* lista,char *nome,int n){
    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));
    strcpy(elemento -> nome,nome);
    elemento -> num = n;
    
    if (lista_vazia(lista))
    {
        lista -> inicio = elemento;
        lista -> fim = elemento;
        lista -> tam++;
        elemento -> prox = NULL;
    }else if (lista -> tam == 1)
    {
        lista -> fim -> prox = elemento;
        lista -> inicio = elemento;
        elemento -> prox = lista -> fim;
        lista -> tam++;
    }else
    {
        lista -> fim -> prox = elemento;
        elemento -> prox = lista -> inicio;
        lista -> inicio = elemento;
        lista -> tam++;
    }
    
}

void adicionar_posicao(Lista* lista,char *nome,int n,int pos){
    Elemento* aux = lista -> inicio;
    Elemento* aux1 = NULL;
    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));
    strcpy(elemento -> nome,nome);
    elemento -> num = n;

    if(pos > (lista -> tam + 1)){
        printf("Posição não existe!\n");
    }else{
    for(int i=1;i<pos;i++){
            aux1 = aux;
            aux = aux -> prox;
        }
    aux1 -> prox = elemento;
    elemento -> prox = aux;
    lista -> tam++;
    }
}

void remover_final(Lista* lista){
    Elemento* aux = lista -> fim;
    Elemento* aux1 = lista -> inicio;
    if(lista_vazia(lista)){
        printf("Lista vazia!");
    }else if (lista -> tam == 1)
    {
        free(aux);
        lista -> tam--;
    }else{
        while (aux1 -> prox != lista -> fim)
        {
            aux1 = aux1 -> prox;
        }
        lista -> fim = aux1;
        lista -> fim -> prox = lista -> inicio;
        free(aux);
        lista -> tam--;
    }
}

void remover_inicio(Lista* lista){
    Elemento* aux = lista -> inicio;
    Elemento* aux1 = lista -> inicio -> prox;
    if(lista_vazia(lista)){
        printf("Lista vazia!");
    }else if (lista -> tam == 1)
    {
        free(aux);
        lista -> tam--;
    }else{
        lista -> inicio = aux1;
        lista -> inicio -> prox = aux1 -> prox;
        lista -> fim -> prox = lista -> inicio;
        free(aux);
        lista -> tam--;
    }
}

int tamanho_lista(Lista* lista){
    return lista -> tam;
}

void finalizar_lista(Lista* lista){
    Elemento *aux,*aux1;

    aux = lista -> inicio;

    while(aux!=NULL){
        aux1 = aux -> prox;
        free(aux);
        aux = aux1;
    }
    free(lista);
}
*/

int main(void){
    
    int opc=0,num,pos;
    char nome[30];
    Lista* l;

    do
    {
        printf("===============Menu===============\n");
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
        printf("10 - Limpar lista e Sair\n");
        printf("11 - Sair\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            l = criar_lista();
            break;
        case 2:
            getchar();
            printf("Digite um nome:\n");
            gets(nome);
            printf("Digite um valor:\n");
            scanf("%d",&num);
            printf("\n\n");

            adicionar_final(l,nome,num);

            break;
        case 3:
            getchar();
            printf("Digite um nome:\n");
            gets(nome);
            printf("Digite um valor:\n");
            scanf("%d",&num);
            printf("\n\n");

            adicionar_inicio(l,nome,num);

            break;
        case 4:
            getchar();
            printf("Digite um nome:\n");
            gets(nome);
            printf("Digite um valor:\n");
            scanf("%d",&num);
            printf("Digite a posição onde adicionar:");
            scanf("%d",&pos);
            printf("\n\n");

            adicionar_posicao(l,nome,num,pos);
            break;
        case 5:
            remover_final(l);
            break;
        case 6:
            remover_inicio(l);
            break;
        case 7:
            printf("Digite a posição a ser removida:\n");
            scanf("%d",&pos);
            printf("\n\n");
            
            remover_pos(l,pos);
            break;
        case 8:
            print_lista(l);
            break;
        case 9:
            if(lista_vazia(l)){
                printf("Lista vazia\n\n");
            }else printf("A lista possui %d elementos.\n\n",tamanho_lista(l));
            break;
        case 10:
            finalizar_lista(l);
            break;
        case 11:
            selection_sort(l);
        break;
        
        default:
            break;
        }
    } while (opc < 12);
    

    return 0;
}