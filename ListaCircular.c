#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCircular.h"

Lista* criar_lista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista -> tam = 0;
    lista -> inicio = NULL;
    lista -> fim = NULL;
    return lista;
}

void adicionar_elemento(Lista* lista,char nome,int n){
    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));
    elemento -> nome = nome;
    elemento -> num = n;

    if (lista -> tam == 0)
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
        lista -> fim -> prox = elemento -> prox;
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
    if(pos > lista -> tam){
        printf("Posição não existe!\n");
    }else if (lista -> tam == 0)
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
            aux = aux -> prox;
        }
        printf("(%d ", aux -> num);
        printf("%s) Removido da lista!\n", aux -> nome);
        free(aux);
        lista -> tam--;
    }
    
    
}