
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

int lista_vazia(Lista* lista);

void adicionar_elemento(Lista* lista,char nome,int n);

void print_lista(Lista* lista);

void remover_pos(Lista* lista,int pos);

void adicionar_inicio(Lista* lista,char nome,int n);

void remover_inicio(Lista* lista);

int tamanho_lista(Lista* lista);

void finalizar_lista(Lista* lista);



