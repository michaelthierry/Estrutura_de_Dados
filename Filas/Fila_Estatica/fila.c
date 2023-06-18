/**
 * @file fila.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Fila Estatica
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_criar(){
    //Ponterio para fila
    Fila *fila;
    //Aloca memoria
    fila = (Fila*) malloc(sizeof(Fila));
    //Verifica se a fila é Nulla
    if(fila != NULL){
        //Inicializa os campos
        fila->quantidade = 0;
    }
    //Retorna a referencia
    return fila;
}

void fila_destruir(Fila *fila){
    //Libera a memoria para a fila
    free(fila);
}

int fila_vazia(Fila *fila){
    //Verifica se a fila existe
    if(fila == NULL){
        return -1;
    }
    //Verifica a quantidade
    if(fila->quantidade == 0){
        return 1;
    }
    return 0;
}

int fila_cheia(Fila *fila){
    //Verifica se fila existe
    if(fila == NULL){
        return -1;
    }
    //Verifica a quantidade
    if(fila->quantidade == MAX){
        return 1;
    }
    return 0;
}

int fila_tamanho(Fila *fila){
    //Verifica se existe
    if(fila == NULL){
        return -1;
    }
    //Retorna a quantidade
    return fila->quantidade;
}

int fila_mostrar(Fila *fila){
    //Verfica se a fila existe
    if(fila == NULL){
        return -1;
    }
    //Mostra na tela os elementos
    int iterador = 0;
    printf("@> Fila\n");
    while(iterador < fila->quantidade){
        printf("[%i]|ID:[%i]\n",
            iterador+1,
            fila->elementos[iterador].id
        );
        iterador++;
    }
    //Retorna sucesso
    return 1;
}

int fila_inserir(Fila *fila, Pessoa pessoa){
    //verifica se a fila esta cheia
    if(fila_cheia(fila)){
        return -1;
    }
    //Adiciona o elemento no ultima posiçao
    fila->elementos[fila->quantidade] = pessoa;
    //Incrementa quantidade
    fila->quantidade++;
    //Retorna sucesso
    return 1;
}

int fila_remover(Fila* fila){
    //Verifica se fila esta vazia
    if(fila_vazia(fila)){
        return -1;
    }
    //Remove o primeiro elemento
    int indice;
    for(indice = 0; indice < fila->quantidade - 1; indice++){
        fila->elementos[indice] = fila->elementos[indice + 1];
    }
    //Decrementa da quantidade
    fila->quantidade--;
    //Retorna sucesso
    return 1;
}
