/** Estrutura: Lista Estattica Linear
 *  Modulo: lista.c
 *  Autor: Michael Thierry 
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Criando a lista
Lista* lista_criar(){

    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        lista->quantidade = 0;
    }
    return lista;
}

//Destruindo a lista
void lista_destruir(Lista *lista){
    free(lista);
}

//Informações da lista
void lista_tamanho(Lista *lista){
    if(lista == NULL){
        return;
    }else{
        printf("Tamanho: %d\n", lista->quantidade);
        return;
    }
}

int lista_cheia(Lista *lista){
    if(lista == NULL){
        return -1;
    }
    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    if(lista == NULL){
        return -1;
    }
    return (lista->quantidade == 0);
}

//Inserção na lista
int lista_inserir_inicio(Lista *lista, Dado Elemento){
    if(lista_cheia(lista)){
        return 0;
    }
    int i;
    for(i = lista->quantidade-1; i >= 0; i--){
        lista->elementos[i+1] = lista->elementos[i];
    }
    lista->elementos[0] = Elemento;
    lista->quantidade++;
    return 1;
}

int lista_inserir_meio(Lista *lista, Dado Elemento){
    if(lista_cheia(lista)){
        return 0;
    }
    int k, i = 0;
    while(i < lista->quantidade && lista->elementos[i].valor < Elemento.valor){
        i++;
    }
    for(k = lista->quantidade - 1; k >= i; k--){
        lista->elementos[k+1] = lista->elementos[k];
    }
    lista->elementos[i] = Elemento;
    lista->quantidade++;
    return 1;
}

int lista_inserir_fim(Lista *lista, Dado Elemento){
    if(lista_cheia(lista)){
        return 0;
    }
    lista->elementos[lista->quantidade] = Elemento;
    lista->quantidade++;
    return 1;
}
//Remover da lista
int lista_remover_inicio(Lista *lista){
    if(lista_vazia(lista)){
        return 0;
    }
    int k;
    for(k = 0; k < lista->quantidade-1; k++){
        lista->elementos[k] = lista->elementos[k+1];
    }
    lista->quantidade--;
    return 1;
}

int lista_remover_meio(Lista *lista, int valor){
    if(lista_vazia(lista)){
        return 0;
    }
    int k, i = 0;
    while(i < lista->quantidade && lista->elementos[i].valor != valor){
        i++;
    }
    if(i == lista->quantidade){
        return 0;
    }
    for(k = i; k < lista->quantidade-1; k++){
        lista->elementos[k] = lista->elementos[k+1];
    }
    lista->quantidade--;
    return 1;
}

int lista_remover_fim(Lista *lista){
    if(lista_vazia(lista)){
        return 0;
    }
    lista->quantidade--;
    return 1;
}

int lista_mostrar(Lista *lista)[
    if(lista_vazia(lista)){
        return 0;
    }
    int i = 0;
    while(i < lista->quantidade){
        printf("[%i]", lista->elementos[i].valor);
        i++;
    }
]
