/** Estrutura: Lista Estattica Linear
 *  Modulo: lista.h
 *  Autor: Michael Thierry 
*/
#ifndef LISTA_H
#define LISTA_H
#define MAX 3

//DEFININDO O TIPO DE DADOS PARA A LISTA
typedef struct dado{
    int valor;
}Dado;

//DEFININDO A LISTA 
typedef struct lista{
    int quantidade;
    Dado elementos[MAX];
}Lista;

//PROTOTIPO DE FUNÇÕES DA LISTA

/*  Essa função não recebe parametros 
    Ela aloca memoria para um ponteiro do tipo lista
    E restorna essa ponteiro
*/

Lista* lista_criar();

/*  Essa função recebe um ponteiro do tipo lista
    Ela libera a lista alocada 
    E não retorna nada
*/
void lista_destruir(Lista *lista);

/*  Essa função recebe o ponteiro do tipo lista 
    Ela acessa o campo quantidade da lista e retorna o valor
    Ela não retorna nada
*/
void lista_tamanho(Lista *lista);

/*  Essa função recebe um ponteiro do tipo lista 
    Ela retorna 1 se a lista não existe ou se a lista esta cheia
    Ela retorna zero se a lista não esta cheia
*/
int lista_cheia(Lista *lista);

/*  Essa função recebe 
*/
int lista_vazia(Lista *lista);

int lista_inserir_inicio(Lista *lista, Dado Elemento);

int lista_inserir_meio(Lista *lista, Dado Elemento);

int lista_inserir_fim(Lista *lista, Dado Elemento);

int lista_remover_inicio(Lista *lista);

int lista_remover_meio(Lista *lista, int valor);

int lista_remover_fim(Lista *lista);

int lista_mostrar(Lista *lista);

#endif