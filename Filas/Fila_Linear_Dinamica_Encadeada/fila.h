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

Fila *fila_criar();
void Fila_destruir(Fila *fila);

int fila_cheia(Fila *fila);
int fila_vazia(Fila *fila);
int fila_tamanho(Fila *fila);

int fila_inserir(Fila *fila, Pessoa pessoa);
int fila_remover(Fila *fila);

int fila_buscar_elemento(Fila *fila, int id, Pessoa *pessoa);
int fila_buscar_posicao(Fila *fila, int posicao, Pessoa *pessoa);

/**
 * @brief Cria um elemento pessoa e lendo do usuario.
 * 
 * @return Pessoa 
 */
Pessoa entrada_dados();

#endif