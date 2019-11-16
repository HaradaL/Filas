#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum Boolean{FALSE, TRUE} Boolean;
typedef int Tipo;

typedef struct{
    Tipo *vetor;
    int tam;
    int inicio;
    int fim;
}Fila;


Fila* fila_criar();
void fila_destruir(Fila* f);

Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo *fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);

Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);

/*
Cria a fila 
@return endereço da fila criada e inicializada
*/
Fila* fila_criar(int tamanho) {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = 0;
        fila->fim = 0;
        fila->tam = tamanho;
    }
    return fila;
}

/*
Destrói a fila  
@return endereço da fila criada e inicializada
*/
void fila_destruir(Fila* f) {
    free(f);
}


/*
Inseri um elemento no final da fila 
@param: fila
@param: elemento a ser inserido
@return true se conseguir inserir, do contrário false;
*/
Boolean fila_inserir(Fila* f, Tipo elemento) {
    if(f->inicio == f->fim) {
        f->vetor[f->inicio] = elemento;
    } else if (f->tam == f->fim) return FALSE;
    //incremento e inserção
    f->vetor[f->fim] = elemento;
    f->fim++; 
    f->tam++;
    return TRUE;
}

/*
Informa o tamanho da fila
@return 
*/
int fila_tamanho(Fila* f) {
    return f->tam;
}

/*
Informa se fila está cheia
@return 
*/
int fila_cheia(Fila *f) {
    return (f->tam-1 == f->fim);
}

/*
Informa se fila está vazia
@return 
*/
int fila_vazia(Fila *f) {
    return (f->tam == 0);
}

/*
Remove o primeiro elemento da fila (FIFO)
@return 
*/
Tipo *fila_remover1(Fila* f) {
    Tipo *temp;
    if (f->tam == 0)    return temp;
    *temp = f->vetor[f->inicio];
    f->tam--;
    return temp;
}

Boolean fila_remover2(Fila* f, Tipo* endereco) {
    if (f->tam == 0) return FALSE;
    int i;
    *endereco = f->vetor[f->inicio];
    for (i = 0; i <= f->fim; i++) {
        if (f->vetor[i] == *endereco)
            return TRUE;
    }
    return TRUE;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco) {
    if (f->tam == 0) return FALSE;
    *endereco = f->vetor[f->inicio];
    return TRUE;
}

int fila_contem(Fila* f, Tipo elemento) {
    int i;
    for (i = 0; i < f->tam-1; i++) {
        if (f->vetor[i] == elemento) {
            return 1;
        } else 
            return 0;
    }
}

void fila_imprimir(Fila* f) {
    int i;
    for (i = 0; i < f->tam-1; i++) {
        printf("%d ", f->vetor[i]);
    }
    printf("\n");
}
