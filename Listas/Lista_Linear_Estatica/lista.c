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
            "-------\n"
            "ID:[%i]\n"
            "-------\n",
            lista->elementos[iterador].id);
        iterador++;
    }
    //Retorna 1
    return 1;
}

int lista_inserir_inicio(Lista *lista, Pessoa pessoa){
    //verificar se a lista esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Declara um indice
    int indice;
    //Move todos os elementos uma casa para frente
    for(indice = lista->quantidade - 1; indice >= 0; indice--){
        lista->elementos[indice + 1] = lista->elementos[indice];
    }
    //Adicioan o elemento na primeira posiçao
    lista->elementos[0] = pessoa;
    lista->quantidade++;
    //Retorna sucesso
    return 1;
}

int lista_inserir_ordenado(Lista *lista, Pessoa pessoa){
    //Verifica se esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Percore a lista procurando o posição certa
    int posicao, indice = 0;
    while((indice < lista->quantidade) && (lista->elementos[indice].id < pessoa.id)){
        indice++;
    }
    //Move todos da posicão encontrada para a direita
    for(posicao = lista->quantidade -1; posicao >= indice; posicao--){
        lista->elementos[posicao + 1] = lista->elementos[posicao];
    }
    //Insere o elemento na posição e incrementa a quantidade
    lista->elementos[indice] = pessoa;
    lista->quantidade++;
    //Retorna sucesso
    return 1;
}

int lista_inserir_fim(Lista *lista, Pessoa pessoa){
    //Verifica se a lista existe
    if(lista_cheia(lista)){
        return -1;
    }
    //Adiciona o elemento na ultima posiçao
    lista->elementos[lista->quantidade] = pessoa;
    //Incrementa quantidade
    lista->quantidade++;
    //Retorna sucesso
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //Verifica se alista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    int indice;
    //Move todos elemento uma posicão anterior
    for(indice = 0; indice < lista->quantidade - 1; indice++){
        lista->elementos[indice] = lista->elementos[indice + 1];
    }
    //Decrementa a quantidade
    lista->quantidade--;
    //Retorna sucesso
    return 1;
}

int lista_remover_elemento(Lista *lista, Pessoa pessoa){
    //Verifica se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    int posicao, indice = 0;
    //Percorre a lista procurando pelo elemento
    while((indice < lista->quantidade) && (lista->elementos[indice].id != pessoa.id)){
        indice++;
    }
    //Verifica se encontrou 
    if(indice == lista->quantidade){
        return -1;
    }
    //Move os elementos uma posição para a esquerda
    for(posicao = indice; posicao < lista->quantidade-1; posicao++){
        lista->elementos[posicao] = lista->elementos[posicao + 1];
    }
    //Decrementa quantidade
    lista->quantidade--;
    //retorna sucesso
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Verifica se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Apenas decrementa a quantidade
    lista->quantidade--;
    //Retorna sucesso
    return 1;
}