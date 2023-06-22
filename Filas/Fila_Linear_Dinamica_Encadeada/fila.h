/**
 * @file fila.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief fila linear dinamica encadeada
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FILA_H
#define FILA_H

//Tipo de dado que a lista guarda
typedef struct pessoa{
    int id;
    char nome[30];
}Pessoa;

//Estrutura dos elementos
typedef struct elemento{
    //Campo de dados
    Pessoa pessoa;
    //Referencia pra o proximo elemento
    struct elemento *proximo;
}Elemento;

//Estrutura da lista
typedef struct fila{
    //Referencia para o primeiro elemento da lista
    Elemento *inicio;
}Fila;


#endif