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

//Estrutura da fila
typedef struct fila{
    //Referencia para o primeiro elemento da fila;
    Elemento *inicio;
}Fila;

/**
 * @brief Aloca memoria para a fila
 * 
 * @return Fila* 
 */
Fila *fila_criar();

/**
 * @brief libera a memoria alocada para a fila
 * 
 * @param fila 
 */
void fila_destruir(Fila *fila);

/**
 * @brief Informa se a fila esta cheia (nunca estara ate a memoria acabar)
 * 
 * @param fila 
 * @return int 
 */
int fila_cheia(Fila *fila);

/**
 * @brief informa se a fila esta vazia
 * 
 * @param fila 
 * @return int 
 */
int fila_vazia(Fila *fila);

/**
 * @brief Informa a quantidade de elementos na fila
 * 
 * @param fila 
 * @return int 
 */
int fila_tamanho(Fila *fila);

/**
 * @brief Mostra para o usuario os elemento da fila
 * 
 * @param fila 
 * @return int 
 */
int fila_mostrar(Fila *fila);

/**
 * @brief insere um elemento no inicio da fila se ela estiver vazia ou insere no fim se ja
 * houver elementos
 * @param fila referenicia para a fila
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int fila_inserir(Fila *fila, Pessoa pessoa);

/**
 * @brief Remove um elemento do fim da fila
 * 
 * @param fila referencia para a fila
 * @return int 
 */
int fila_remover(Fila *fila);

/**
 * @brief busca pro um elemento na fila
 * 
 * @param fila referencia para a fila
 * @param id informação do elemento a ser buscado
 * @param pessoa refrencia que recebera o elemento
 * @return int 
 */
int fila_buscar_elemento(Fila *fila, int id, Pessoa *pessoa);

/**
 * @brief Busca um elemento na fila pela posicao
 * 
 * @param fila referencia para a fila
 * @param posicao indice onde o elemento se encontra
 * @param pessoa referencia que recebe o elemento
 * @return int 
 */
int fila_buscar_posicao(Fila *fila, int posicao, Pessoa *pessoa);

/**
 * @brief Cria um elemento pessoa lendo do usuario.
 * 
 * @return Pessoa 
 */
Pessoa entrada_dados();

#endif