/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Biblioteca da Lista Dinamica Encadeada
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Definindo as macros da lista
 */
#ifndef LISTA_H
#define LISTA_H

/**
 * @brief Defindo o tipo tipo de dado para a lista
 */
typedef struct dado{
    int valor;
}Dado;

/**
 * @brief Definindo o elemento da lista
 * Ela possui um campo de dado e um campo proximo que aponta para o proximo dado
 */
typedef struct elemento{
    Dado elemento;
    struct elemento *proximo;
}Elemento;

/**
 * @brief Definindo a lista 
 * Ela possui apenas um ponteiro que marca o inicio da lista
 */
typedef struct lista{
     Elemento *inicio;
}Lista;

//PROTOTIPO DE FUNÇÕES DA LISTA

Lista* lista_criar();
void lista_destruir(Lista *lista);
int lista_tamanho(Lista* lista);
int lista_cheia(Lista* lista);
int lista_vazia(Lista* lista);

#endif