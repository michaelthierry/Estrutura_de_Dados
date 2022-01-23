/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Funções da Lista Dinamica Encadeada
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Criando a lista
Lista* lista_criar(){

    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        lista->inicio = NULL;
    }
    printf("LISTA CRIADA\n");
    return lista;
}
//Destruindo a lista
void lista_destruir(Lista *lista){
    if(lista != NULL){
        Elemento *auxiliar;
        while(lista->inicio != NULL){
            auxiliar = lista->inicio;
            lista->inicio = lista->inicio->proximo;
            free(auxiliar);

        }
        free(lista);
    }
    printf("LISTA LIBERADA\n");
    return;
}
//Informações da lista
int lista_tamanho(Lista* lista){
    if(lista == NULL){
        return 0;
    }
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    int contador = 0;
    while(auxiliar != NULL){
        contador++;
        auxiliar = auxiliar->proximo;
    }
    return contador;
}

int lista_cheia(Lista* lista){
    return 0;
}

int lista_vazia(Lista* lista){
    if(lista == NULL || lista->inicio ==NULL){
        return 1;
    }
    return 0;
}

int lista_mostrar(Lista *lista){
    if(lista == NULL){
        return 0;
    }
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    int contador = 0;
    while(auxiliar != NULL){
        printf("[%i]", auxiliar->elemento.valor);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
    return 1;
}

int lista_inserir_inicio(Lista *lista, Dado dado){
    if(lista == NULL){
        return 0;
    }
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL){
        return 0;
    }
    novo->elemento = dado;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    return 1;
}

int lista_inserir_fim(Lista *lista, Dado dado){
    if(lista == NULL){
        return 0;
    }
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL){
        return 0;
    }

    novo->elemento = dado;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        Elemento *auxiliar;
        auxiliar = lista->inicio;
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;    
    }
    return 1;
}

int lista_inserir_meio(Lista *lista, Dado dado){
    if(lista == NULL){
        return 0;
    }
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL){
        return 0;
    }
    novo->elemento = dado;
    if(lista_vazia(lista)){
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }else{
        Elemento *anterior, *atual;
        atual = lista->inicio;
        while(atual != NULL && atual->elemento.valor < dado.valor){
            anterior = atual;
            atual = atual->proximo;
        }
        if(atual == lista->inicio){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
        return 1;
    }
}