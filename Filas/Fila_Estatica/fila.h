/**
 * @file fila.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Fila Estática
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Definindo as diretivas e as macros da Fila
#ifndef FILA_H
#define FILA_H

//Tamanho maximo da fila
#define MAX 10

//Tipo de dado que a lista guarda
typedef struct pessoa{
    int id;
    char nome[30];
}Pessoa;

//Estrutura da fila
typedef struct fila{
    int quantidade;
    Pessoa elementos[MAX];
}Fila;

/**
 * @brief Aloca memoria para a fila estatica
 * 
 * @return Fila* 
 */
Fila* fila_criar();

/**
 * @brief Desaloca memoria alocada para a fila
 * 
 * @param fila é a referencia para fila 
 */
void fila_destruir(Fila *fila);

/**
 * @brief Informa se a fila esta vazia
 * 
 * @param fila é uma referencia para a fila
 * @return int 
 */
int fila_vazia(Fila *fila);

/**
 * @brief Informa se a fila cheia
 * 
 * @param fila é a referencia para fila
 * @return int 
 */
int fila_cheia(Fila *fila);

/**
 * @brief Informa a quantidade de elemento da fila
 * 
 * @param fila é uma referencia para a fila
 * @return int 
 */
int fila_tamanho(Fila *fila);

/**
 * @brief Mostra no console os elementos da fila
 * 
 * @param fila é a referencia para a fila
 * @return int 
 */
int fila_mostrar(Fila *fila);

/**
 * @brief Insere um elemento no final da fila
 * 
 * @param fila é a referencia para a fila
 * @param pessoa elemento a ser adicionado
 * @return int 
 */
int fila_inserir(Fila *fila, Pessoa pessoa);

#endif