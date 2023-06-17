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
    char *nome;
}Pessoa;

//Estrutura da fila
typedef struct fila{
    int quantidade;
    Pessoa elemento[MAX];
}Fila;

//Criando e destruindo a fila
Fila* fila_criar();
void fila_destruir(Fila *fila);

#endif