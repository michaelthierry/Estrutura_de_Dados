/**
 * @file pilha.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Pilha Estática
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* pilha_criar(){
    //Ponteiro para a pilha
    Pilha *pilha;
    //Aloca memoria para a pilha
    pilha = (Pilha*) malloc(sizeof(Pilha));
    //Verfica se a pilha nao é nula
    if(pilha != NULL){
        pilha->quantidade = 0;
    }
    //Retona a referencia
    return pilha;
}

void pilha_destruir(Pilha *pilha){
    //Libera memoria alocada
    free(pilha);
}

int pilha_vazia(Pilha *pilha){
    //verifica se a pilha existe
    if(pilha == NULL){
        return 1;
    }
    //verifica se tem elementos
    if(pilha->quantidade == 0){
        return 1;
    }
    return 0;
}

int pilha_cheia(Pilha *pilha){
    //Verifica se a pilha existe
    if(pilha == NULL){
        return -1;
    }
    //verifica se esta cheia
    if(pilha->quantidade == MAX){
        return 1;
    }
    return 0;
}
int pilha_tamanho(Pilha *pilha){
    //Verifica se a pilha existe
    if(pilha == NULL){
        return -1;
    }
    //Retorna a quantidade
    return pilha->quantidade;
}
int pilha_mostrar(Pilha *pilha){
    //Verifica se a pilha existe
    if(pilha == NULL){
        return -1;
    }
    //Mostra a pilha
    int iterador = 0;
    printf("@> Pilha\n");
    while(iterador < pilha->quantidade){
        printf("[%i]|ID:[%i]\n", 
            iterador+1,
            pilha->elementos[iterador].id
        );
        iterador++;
    }
    return 1;
}