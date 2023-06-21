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

int lista_cheia(Lista *lista){
    return 0;
}

int lista_vazia(Lista *lista){
    //se nao existir
    if(lista == NULL){
        return -1;
    }
    //verifica se esta vazia
    if(lista->inicio == NULL){
        return 1;
    }
    return 0;
}

int lista_tamanho(Lista *lista){
    //Se nao existe
    if(lista == NULL){
        return -1;
    }
    //Conta os elementos
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    int contador = 0;
    while(auxiliar != NULL){
        contador++;
        auxiliar = auxiliar->proximo;
    }
    //Retorna a quantidade
    return contador;
}

int lista_mostrar(Lista *lista){
    //se nao existe
    if(lista == NULL){
        return -1;
    }
    //Cria um elemento auxiliar
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    printf(BOLD YELLOW"@> Lista\n"NONE);
    //Percorre a lista
    int contador = 0;
    while(auxiliar != NULL){
        printf(BOLD YELLOW
            "+------------------------------------------+\n"
            "|"GREEN"[%02i]"YELLOW"|ID:[%i]              \n"            
            "|    |Nome:[%s]                             \n"
            "+------------------------------------------+\n"NONE,
            contador+1,
            auxiliar->pessoa.id,
            auxiliar->pessoa.nome
        );
        auxiliar = auxiliar->proximo;
        contador++;
    }
    //retorna sucesso
    return 1;
}

int lista_inserir_inicio(Lista *lista, Pessoa pessoa){
    //Se nao existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Verifica se foi alocado
    if(novo == NULL){
        return -1;
    }
    //Insere o elemento
    novo->pessoa = pessoa;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    //Sucesso
    return 1;
}

int lista_inserir_ordenado(Lista *lista, Pessoa pessoa){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //verifica se alocou
    if(novo == NULL){
        return -1;
    }
    //Atribui o valor
    novo->pessoa = pessoa;
    //se a lista esta vazia
    if(lista_vazia(lista)){
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }else{
        //cria auxiliares
        Elemento *anterior, *atual;
        atual = lista->inicio;
        //Percorre a lista para encontra o local certo
        while((atual != NULL) && (atual->pessoa.id < pessoa.id)){
            anterior = atual;
            atual = atual->proximo;
        }
        //Se o atual é o inicio
        if(atual == lista->inicio){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
    }
    //Sucesso
    return 1;
}

int lista_inserir_fim(Lista *lista, Pessoa pessoa){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Se foi alocado
    if(novo == NULL){
        return -1;
    }
    novo->pessoa = pessoa;
    novo->proximo = NULL;
    //Se o inicio for nulo
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        //Cria um auxiliar
        Elemento *auxiliar;
        auxiliar = lista->inicio;
        //Percorre a lista ate o fim
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        //insere no fim
        auxiliar->proximo = novo;
    }
    //Sucesso
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //se exitir
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria um elemento
    Elemento *auxiliar;
    //Remove do inicio
    auxiliar = lista->inicio;
    lista->inicio = auxiliar->proximo;
    //Libera o auxiliar
    free(auxiliar);
    //sucesso
    return 1;
}

int lista_remover_elemento(Lista *lista, Pessoa pessoa){
    //Se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria auxiliares
    Elemento *anterior, *atual;
    atual = lista->inicio;
    //Encontra o elemento
    while((atual != NULL) && (atual->pessoa.id != pessoa.id)){
        anterior = atual;
        atual = atual->proximo;
    }
    //Verifica se encontrou
    if(atual == NULL){
        return 0;
    }
    //Remove o elemento
    Elemento *remover;
    remover = atual;
    anterior->proximo = remover->proximo;
    //libera o elemento
    free(remover);
    //status ok
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria auxiliares
    Elemento *anterior, *atual;
    atual = lista->inicio;
    //Percorre a lista
    while(atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    //Se estiver removendo o primeiro
    if(atual == lista->inicio){
        lista->inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    //libera o atual
    free(atual);
    //status ok
    return 1;
}

int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa){
    //se existir
    if(lista == NULL){
        return -1;
    }
    //Se nao estiver vazia
    if(lista_vazia(lista)){
        return 0;
    }
    //Criando um ponteiro
    Elemento *auxiliar = lista->inicio;
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

int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa){
    //Se a lista existir
    if(lista == NULL){
        return -1;
    }
    //Se a lista não estiver vazia
    if(lista_vazia(lista) || posicao <= 0){
        return 0;
    }
    //Criar auxiliar
    Elemento *auxiliar;
    int indice = 1;
    auxiliar = lista->inicio;
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
