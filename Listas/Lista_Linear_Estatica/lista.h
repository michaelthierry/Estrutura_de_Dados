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

//Efeitos
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"

//Cores
#define BLACK     "\033[30m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"
#define GRAY      "\033[37m"

//Tipo de dado que a lista guarda
typedef struct pessoa{
    int id;
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

#endif