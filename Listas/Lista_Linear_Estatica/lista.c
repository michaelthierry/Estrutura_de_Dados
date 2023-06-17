/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estática
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    //Declara ponteiro do tipo lista
    Lista *lista;
    //Tenta alocar memoria
    lista = (Lista*) malloc(sizeof(Lista));
    //Verifica se foi alocado
    if(lista != NULL){
        //Adiciona zero ao campo quantidade
        lista->quantidade = 0;
    }
    //Retorna o ponteiro
    return lista; 
}

void lista_destruir(Lista *lista){
    //Libera a memoria alocada para a lista
    free(lista);
}

int lista_cheia(Lista *lista){
    //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta cheia
    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    //Verifica se a lista existe 
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta vazia
    return (lista->quantidade == 0);
}

int lista_tamanho(Lista *lista){
    //Verifica a lista existe 
    if(lista == NULL){
        return -1;
    }
    //Retorna a quantidade
    return lista->quantidade;
}

int lista_mostrar(Lista *lista){
    //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Mostra na tela os elementos
    int iterador = 0;
    printf(BOLD YELLOW "@> Lista\n");
    while(iterador < lista->quantidade){
        printf(
            "----\n"
            "ID:[%i]\n"
            "Nome:[%s]\n"
            "----\n",
            lista->elementos[iterador].id,
            lista->elementos[iterador].nome);
        iterador++;
    }
    //Retorna 1
    return 1;
}