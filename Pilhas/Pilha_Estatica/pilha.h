/**
 * @file pilha.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Pilha Estatica
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Definido diretivas e macros da pilha
#ifndef PILHA_H
#define PILHA_H

//Tamanho maximo da pilha
#define MAX 10

//Tipo de dados que a pilha guarda
typedef struct pessoa{
    int id;
    char nome[30];
}Pessoa;

//Defindo estrutura da pilha
typedef struct pilha{
    int quantidade;
    Pessoa elementos[MAX];
}Pilha;

/**
 * @brief Aloca memoria para uma pilha
 * 
 * @return Pilha* 
 */
Pilha* pilha_criar();

/**
 * @brief Desaloca memoria alocada para uma pilha
 * 
 * @param pilha é a referencia para a pilha
 */
void pilha_destruir(Pilha *pilha);

/**
 * @brief Informa se a pilha esta vazia
 * 
 * @param pilha referencia pra pilha
 * @return int 
 */
int pilha_vazia(Pilha *pilha);

/**
 * @brief Informa se a pilha esta cheia
 * 
 * @param pilha referencia para a pilha
 * @return int 
 */
int pilha_cheia(Pilha *pilha);

/**
 * @brief Informa o tamanho da pilha
 * 
 * @param pilha referencia para a pilha
 * @return int 
 */
int pilha_tamanho(Pilha *pilha);

/**
 * @brief Mostra os elementos da pilha
 * 
 * @param pilha referenccia para a pilha
 * @return int 
 */
int pilha_mostrar(Pilha *pilha);

/**
 * @brief Insere um elemento no topo da pilha
 * 
 * @param pilha referencia para a pilha
 * @param pessoa elemento a ser adicionado na pilha
 * @return int 
 */
int pilha_inserir(Pilha *pilha, Pessoa pessoa);

/**
 * @brief Remove o elemento do topo da pilha
 * 
 * @param pilha referencia para a pilha
 * @return int 
 */
int pilha_remover(Pilha *pilha);

/**
 * @brief Busca um elemento na pilha pelo id
 * 
 * @param pilha referencia para a pilha
 * @param id identificador do elemento
 * @param pessoa referencia que recebe o elemento
 * @return int 
 */
int pilha_buscar_elemento(Pilha *pilha, int id, Pessoa *pessoa);

/**
 * @brief Encontra um elemento na pilha pela posicão, se houver
 * 
 * @param pilha referencia para pilha
 * @param posicao indice onde se encontra o elemento
 * @param pessoa referencia que recebe o elemento do indice
 * @return int 
 */
int pilha_buscar_posicao(Pilha *pilha, int posicao, Pessoa *pessoa);

#endif