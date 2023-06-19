/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Dinamica Encadeada
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    //Ponteiro para o tipo lista
    Lista *lista;
    //Aloca memoria para a lista
    lista = (Lista*) malloc(sizeof(Lista));
    //Verifica se a lista foi criada;
    if(lista != NULL){
        lista->inicio = NULL;
    }
    //Retorna a referencia
    return lista;
}

void lista_destruir(Lista *lista){
    //Se existir
    if(lista != NULL){
        //Cria um elemento auxiliar
        Elemento *auxiliar;
        //Percorre a lista liberando os elementos
        while(lista->inicio != NULL){
            //Faz auxiliar pegar o inicio
            auxiliar = lista->inicio;
            //faz o inicio pegar o proximo
            lista->inicio = lista->inicio->proximo;
            //libera o auxiliar
            free(auxiliar);
        }
        //libera a lista
        free(lista);
    }
}