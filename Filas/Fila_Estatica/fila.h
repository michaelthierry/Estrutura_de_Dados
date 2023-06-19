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

//Efeitos
#define NONE        "\033[0m"
#define BOLD        "\033[1m"

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

/**
 * @brief Remove o primeiro elemnto da fila
 * 
 * @param fila é referencia para a fila
 * @return int 
 */
int fila_remover(Fila *fila);

/**
 * @brief Busca por um elemento na fila
 * 
 * @param fila é a referecia para a fila
 * @param id é o identificador do elemento
 * @param pessoa referencia que recebe o elemento encontrado
 * @return int 
 */
int fila_buscar_elemento(Fila *fila, int id, Pessoa *pessoa);

/**
 * @brief Busca por um elemento de uma determinada posicao
 * 
 * @param fila é a referencia para fila
 * @param posicao é o indice da fila onde esta o elemento
 * @param pessoa referencia que recebe o elemento do indice
 * @return int 
 */
int fila_buscar_posicao(Fila *fila, int posicao, Pessoa *pessoa);

#endif