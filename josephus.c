#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaCircular.h"

int main(void){
    Lista* l;
    char nome[] = "Soldado";
    int quant,num,count = 0;
    Elemento* aux;

    l = criar_lista();

    printf("Digite a quantidade de soldados:\n");
    scanf("%d",&quant);


    for (int i = 0; i < quant; i++)
    {
        adicionar_final(l,nome,(i+1));
    }

    for (int i = 0; i < quant; i++)
    {
        if (l -> tam != 1)
        {
        srand( (unsigned)time(NULL) );

        num = rand() % (l->tam*2);
        printf("Numero sorteado: %d\n", num);

        num = (num + count) - l -> tam;

        while (num > l -> tam)
        {
            num = num - l -> tam;
        }
        
        remover_pos(l,num);

        count = num - 1;

        printf("Restam %d soldados\n",l -> tam);
        print_lista(l);
        
        }
    }

    printf("Soldado sobrevivente:\n");
    print_lista(l);

    return 0;
}