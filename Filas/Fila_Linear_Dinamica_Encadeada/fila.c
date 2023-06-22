/**
 * @file fila.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief fila linear dinamica encadeada
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_criar(){
    Fila *fila;
    fila = (Fila*)malloc(sizeof(Fila));
    if(fila != NULL){
        fila->inicio = NULL;
    }
    return fila;
}

void fila_destruir(Fila *fila){
    if(fila != NULL){
        Elemento *auxiliar;
        while(fila->inicio != NULL){
            auxiliar = fila->inicio;
            fila->inicio = auxiliar->proximo;
            free(auxiliar);
        }
        free(fila);
    }
}

int fila_cheia(Fila *fila){
    return 0;
}

int fila_vazia(Fila *fila){
    if(fila == NULL){
        return -1;
    }
    if(fila->inicio == NULL){
        return 1;
    }
    return 0;
}

int fila_tamanho(Fila *fila){
    if(fila == NULL){
        return -1;
    }
    Elemento *auxiliar;
    auxiliar = fila->inicio;
    int contador = 0;
    while(auxiliar != NULL){
        auxiliar = auxiliar->proximo;
        contador++;
    }
    return contador;
}

int fila_inserir(Fila *fila, Pessoa pessoa){
    if(fila == NULL){
        return -1;
    }
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL){
        return -1;
    }
    novo->pessoa = pessoa;
    novo->proximo = NULL;
    if(fila->inicio == NULL){
        fila->inicio = novo;
    }else{
        Elemento *auxiliar;
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;
    }
    return 1;
}

int fila_remover(Fila *fila){
    if(fila == NULL){
        return -1;
    }
    if(fila_vazia(fila)){
        return -1;
    }
    Elemento *anterior, *atual;
    atual = fila->inicio;
    while(atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo;
    };
    if(atual == fila->inicio){
        fila->inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return 1;
}

int fila_buscar_elemento(Fila *fila, int id, Pessoa *pessoa){
    //se existir
    if(fila == NULL){
        return -1;
    }
    //Se nao estiver vazia
    if(lista_vazia(fila)){
        return 0;
    }
    //Criando um ponteiro
    Elemento *auxiliar = fila->inicio;
    //Procura pelo elemento
    while((auxiliar != NULL) && (auxiliar->pessoa.id!= id)){
        auxiliar = auxiliar->proximo;
    }
    //Confere se encontrou
    if(auxiliar == NULL){
        return 0;
    }
    *pessoa = auxiliar->pessoa;
    //Status ok
    return 1;
}

int fila_buscar_posicao(Fila *fila, int posicao, Pessoa *pessoa){
    //Se a lista existir
    if(fila == NULL){
        return -1;
    }
    //Se a fila não estiver vazia
    if(lista_vazia(fila) || posicao <= 0){
        return 0;
    }
    //Criar auxiliar
    Elemento *auxiliar;
    int indice = 1;
    auxiliar = fila->inicio;
    //faz a busca
    while((auxiliar != NULL) && (indice < posicao)){
        auxiliar = auxiliar->proximo;
        indice++;
    }
    //Se não encontrou
    if(auxiliar == NULL){
        return 0;
    }
    //Se sim 
    *pessoa = auxiliar->pessoa;
    //Status
    return 1;
}

Pessoa entrada_dados(){
    Pessoa pessoa;
    //Pegando informação
    printf(BOLD CYAN"@> Digite o ID:\n"NONE);
    scanf("%i", &pessoa.id);
    //Removendo o \n
    while(getchar()!= '\n');
    printf(BOLD CYAN"@> Digite o Nome:\n"NONE);
    //scanf("%s", pessoa.nome);
    //lendo nome pegando espaços em brancos ja que scanf nao faz.
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    //retorna os dados
    return pessoa;
}