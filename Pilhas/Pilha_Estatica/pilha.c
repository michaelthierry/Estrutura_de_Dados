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
    printf(BOLD YELLOW"@> Pilha\n"NONE);
    while(iterador < pilha->quantidade){
        printf(BOLD YELLOW
            "+------------------------------------------+\n"
            "|"GREEN"[%02i]"YELLOW"|ID:[%i]              \n"            
            "|    |Nome:[%s]                             \n"
            "+------------------------------------------+\n"NONE,
            iterador+1,
            pilha->elementos[iterador].id,
            pilha->elementos[iterador].nome
        );
        iterador++;
    }
    //Retorna sucesso
    return 1;
}

int pilha_inserir(Pilha *pilha, Pessoa pessoa){
    //Verifica se a pilha esta cheia
    if(pilha_cheia(pilha)){
        return -1;
    }
    //Adiciona um elemento no topo da pilha
    pilha->elementos[pilha->quantidade] = pessoa;
    //Incrementa quantidade
    pilha->quantidade++;
    //Retorna sucesso
    return 1;
}

int pilha_remover(Pilha *pilha){
    //Verifica se a pilha esta vazia
    if(pilha_vazia(pilha)){
        return -1;
    }
    //Remove elemento do topo da pilha
    pilha->quantidade--;
    //Retorna sucesso;
    return 1;
}

int pilha_buscar_elemento(Pilha *pilha, int id, Pessoa *pessoa){
    //Verifica se a pilha existe
    if(pilha == NULL){
        return -1;
    }
    //Tenta encontrar o elemento
    int indice = 0;
    while((indice < pilha->quantidade) && (pilha->elementos[indice].id != id)){
        indice++;
    }
    //Verifica se encontrou
    if(indice == pilha->quantidade){
        return -1;
    }
    //Se encontrou
    *pessoa = pilha->elementos[indice];
    //Retorna sucesso
    return 1;
}

int pilha_buscar_posicao(Pilha *pilha, int posicao, Pessoa *pessoa){
    //Verifica se a fila existe
    if(pilha == NULL){
        return -1;
    }
    //Verifica se a busca é possivel
    if(posicao <= 0 || posicao > pilha->quantidade){
        return -1;
    }
    //Recebe o elemento diretamente
    *pessoa = pilha->elementos[posicao - 1];
    //Retorna sucesso
    return 1;
}