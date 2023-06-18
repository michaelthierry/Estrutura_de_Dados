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
