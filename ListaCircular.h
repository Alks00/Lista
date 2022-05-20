#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento
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

void adicionar_final(Lista* lista,char *nome,int n){
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
    printf("%s", aux -> nome);
    printf("-%d\n", aux -> num);
    aux = aux -> prox;
    if (lista -> tam > 1)
    {
        while (aux != lista -> inicio)
        {
            printf("%s", aux -> nome);
            printf("-%d\n", aux -> num);
            aux = aux -> prox;
        }
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
    printf("Lista limpa\n");
}

void selection_sort(Lista* lista){
    int i = 0,j,min;
    Elemento aux;
    Elemento vetor[lista -> tam];
    Elemento* auxV = lista -> inicio;

    while (auxV -> prox != lista -> inicio)
    {
        vetor[i].num = auxV->num;
        strcpy(vetor[i].nome,auxV -> nome);
        auxV = auxV -> prox;
        i++;
    }

    for (i = 0; i < (lista -> tam-1); i++)
    {
        min = i;
        for (j = i+1; j < lista -> tam; j++)
        {
            if(vetor[j].num < vetor[min].num){
                min = j;
            }
        }
        if(i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;

        }   
    }

    for (i = 0; i < lista -> tam; i++)
    {
        printf("-%d ", vetor[i].num);
        printf("%s\n", vetor[i].nome);
    }
    
}

/*void quick_sort(Lista* lista,int inicio,int fim){
    int i = inicio;
    int j = fim;
    Elemento pivot;
    Elemento aux;
    Elemento vetor[lista -> tam];
    Elemento* auxV = lista -> inicio;

    while (auxV -> prox != lista -> inicio)
    {
        vetor[i].num = auxV->num;
        strcpy(vetor[i].nome,auxV -> nome);
        auxV = auxV -> prox;
        i++;
    }

    pivot = vetor[(i+j)/2];

    while (i <= j) {
        while ((vetor[i].num < pivot.num) && (i < fim)) {
            i++;
        }

        while ((vetor[j].num > pivot.num) && j > inicio) {
            j--;
        }

        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;

            i++;
            j--;
        }
    }

    if (inicio < j) {
        quick_sort(vetor, inicio, j);
    }

    if (i < fim) {
        quick_sort(vetor, i, fim);
    }
}*/