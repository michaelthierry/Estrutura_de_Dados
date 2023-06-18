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

#endif