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

void adicionar_elemento(Lista* lista,char nome){
    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));
    elemento -> nome = nome;

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