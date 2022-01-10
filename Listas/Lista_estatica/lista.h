/**
 * @file lista.h
 * @author Michael (michaelthierry86@gmail.com)
 * @brief Lista Estattica Linear
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Definindo as macros da lista 
 * Definido o tamanho Maximo da lista 10
 */
#ifndef LISTA_H
#define LISTA_H
#define MAX 10

/**
 * Definindo o tipo de dados para a lista
 * O tipo dado possui um valor inteiro
 */
typedef struct dado{
    int valor;
}Dado;

/**
 * Definindo o tipo lista
 * Ela possui um campo inteiro para guardar a quantidade e um vetor de elementos
 */
typedef struct lista{
    int quantidade;
    Dado elementos[MAX];
}Lista;

//PROTOTIPO DE FUNÇÕES DA LISTA

/**
 * @brief Essa função aloca memoria para um ponteiro do tipo lista.
 * 
 * @return Lista* 
 */
Lista* lista_criar();

/**
 * @brief Essa função destrói a lista alocada
 * 
 * @param lista 
 */
void lista_destruir(Lista *lista);

/**
 * @brief Essa função diz o tamanho da lista passada
 * 
 * @param lista 
 */
void lista_tamanho(Lista *lista);

/**
 * @brief Essa função diz se a lista esta cheia
 * Ela retorna -1 se a lista for nula, 1 se esta cheia, 0 se nao estiver
 * @param lista 
 * @return int 
 */
int lista_cheia(Lista *lista);

/**
 * @brief Essa função diz se lista esta vazia
 * Ela retorna -1 se a lista for nula, 1 se esta vazia, 0 se nao estiver
 * @param lista 
 * @return int 
 */
int lista_vazia(Lista *lista);

/**
 * @brief Essa função insere um elemento no incio da lista
 * Ela ela retorna 0 se esta cheia 1 se obteve sucesso.
 * @param lista 
 * @param Elemento 
 * @return int 
 */
int lista_inserir_inicio(Lista *lista, Dado Elemento);

/**
 * @brief Essa função insere um elemento no meio da lista
 * de forma ordenda pelos valores no elementos já presentes nela.
 * @param lista 
 * @param Elemento 
 * @return int 
 */
int lista_inserir_meio(Lista *lista, Dado Elemento);

/**
 * @brief Essa função insere o elemento no fim da lista
 * 
 * @param lista 
 * @param Elemento 
 * @return int 
 */
int lista_inserir_fim(Lista *lista, Dado Elemento);

/**
 * @brief Essa função remove o elemento que esta no incio da lista
 * 
 * @param lista 
 * @return int 
 */
int lista_remover_inicio(Lista *lista);

/**
 * @brief Essa função remove o elemento por meio do valor no meio da lista(se la ele estiver)
 * 
 * @param lista 
 * @param valor 
 * @return int 
 */
int lista_remover_meio(Lista *lista, int valor);

/**
 * @brief Essa função remove o elemento do fim da lista
 * 
 * @param lista 
 * @return int 
 */
int lista_remover_fim(Lista *lista);

/**
 * @brief Essa função mostra toda a lista
 * 
 * @param lista 
 * @return int 
 */
int lista_mostrar(Lista *lista);

#endif