/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estatica
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Definindo as diretivas e as macros da lista
#ifndef LISTA_H
#define LISTA_H

//Tamanho maximo da lista
#define MAX 10


//Tipo de dado que a lista guarda
typedef struct pessoa{
    int id;
    char nome[30];
    int idade;
    float peso;
}Pessoa;

//Estrutura da Lista Estatica
typedef struct lista{
    int quantidade;
    Pessoa elementos[MAX];
}Lista;

/**
 * @brief Aloca memoria para um ponteiro do tipo lista
 * 
 * @return Lista* : o ponteiro será NULL se a lista não for criada
 */
Lista* lista_criar();

/**
 * @brief Desaloca a memoria alocada para a lista
 * 
 * @param lista : é um ponteiro do tipo lista
 */
void lista_destruir(Lista *lista);

/**
 * @brief Verifica se a lista esta cheia
 * 
 * @param lista : é um ponteiro da lista criada
 * @return int -1 se a lista não existir
 */
int lista_cheia(Lista *lista);

/**
 * @brief Verifica se a lista esta vazia
 * 
 * @param lista : é um ponteiro da lista criada
 * @return int -1 se a lista não existir
 */
int lista_vazia(Lista *lista);

/**
 * @brief Verifica a quantidade de elementos na lista
 * 
 * @param lista : é um ponteiro para o tipo Lista
 * @return int -1 se a lista não existir
 */
int lista_tamanho(Lista *lista);

/**
 * @brief Mostra no console todos os elementos da lista
 * 
 * @param lista : o ponteiro para a lista
 * @return int -1 se a lista não existir.
 */
int lista_mostrar(Lista *lista);

/**
 * @brief Insere uma elemento no inicio da lista
 * 
 * @param lista ponterio para a lista
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int lista_inserir_inicio(Lista *lista, Pessoa pessoa);

/**
 * @brief Insere um elemento de forma ordenada na lista
 * 
 * @param lista ponteiro para o tipo lista
 * @param pessoa elemento a ser inserido na lista
 * @return int 
 */
int lista_inserir_ordenado(Lista *lista, Pessoa pessoa);

/**
 * @brief Insere um elemento no fim da lista
 * 
 * @param lista ponteiro para o tipo lista
 * @param pessoa elemento a ser inserido na lista
 * @return int 
 */
int lista_inserir_fim(Lista *lista, Pessoa pessoa);

/**
 * @brief Remove o primeiro elemento da lista
 * 
 * @param lista ponterio para a lista 
 * @return int 
 */
int lista_remover_inicio(Lista *lista);

/**
 * @brief Procura um elemento na lista e o remove
 * 
 * @param lista ponteiro para a lista
 * @param pessoa elemento a ser procurado
 * @return int 
 */
int lista_remover_elemento(Lista *lista, Pessoa pessoa);

/**
 * @brief Remove o ultimo elemento da lista
 * 
 * @param lista ponteiro para a lista
 * @return int 
 */
int lista_remover_fim(Lista *lista);

/**
 * @brief Busca um elemeto da lista e o atribui a referencia se existir
 * 
 * @param lista ponteiro para lista
 * @param id identidicador do elemento
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa);

/**
 * @brief Busca por um elemento em uma determinada posicao da lista e o atribui a referencia se existir.
 * 
 * @param lista referencia para a lista
 * @param posicao posição da lista para fazer a busca
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa);

#endif