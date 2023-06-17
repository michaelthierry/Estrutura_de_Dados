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
    char *nome;
}Pessoa;

//Estrutura da Lista
typedef struct lista{
    int quantidade;
    Pessoa elementos[MAX];
}Lista;

//Criando e destruindo a lista
Lista* lista_criar();
void lista_destruir(Lista *lista);
//Informações da lista


#endif