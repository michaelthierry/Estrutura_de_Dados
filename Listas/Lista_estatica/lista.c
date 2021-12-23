/** Estrutura: Lista Estattica Linear
 *  Modulo: lista.c
 *  Autor: Michael Thierry 
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Criação e destruição 
Lista* lista_criar(){
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        lista->quantidade = 0;
    }
    return lista;
}
/*
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
        return 0;
    }
    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    if(lista == NULL){
        return 0;
    }
}

int lista_inserir_inicio(Lista *lista, Dado Elemento);

int lista_inserir_meio(Lista *lista, Dado Elemento);

int lista_inserir_fim(Lista *lista, Dado Elemento);

int lista_remover_inicio(Lista *lista);

int lista_remover_meio(Lista *lista);

int lista_remover_fim(Lista *lista);

int lista_mostrar(Lista *lista);
*/