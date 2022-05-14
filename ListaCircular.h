
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

Lista* criar_lista();

void adicionar_elemento(Lista* lista,char nome);
