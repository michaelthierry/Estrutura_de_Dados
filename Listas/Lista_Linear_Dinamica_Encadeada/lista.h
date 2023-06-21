/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Dinamica Linear Encadeada
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Defindo as diretivas e as macro das lista
#ifndef LISTA_H
#define LISTA_H

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
typedef struct lista{
    //Referencia para o primeiro elemento da lista
    Elemento *inicio;
}Lista;

/**
 * @brief Aloca memoria para uma lista
 * 
 * @return Lista* 
 */
Lista* lista_criar();

/**
 * @brief Desaloca memoria para uma lista
 * 
 * @param lista é a referencia da lista
 */
void lista_destruir(Lista *lista);

/**
 * @brief Informa se a lista esta cheia (nunca vai estar)
 * a nao ser que falte memoria
 * @param lista referencia para a lista
 * @return int 
 */
int lista_cheia(Lista *lista);

/**
 * @brief Informa se a lista esta vazia
 * 
 * @param lista referencia para a lista
 * @return int 
 */
int lista_vazia(Lista *lista);

/**
 * @brief Informa quantos elemento tem na lista
 * 
 * @param lista referencia para lista
 * @return int 
 */
int lista_tamanho(Lista *lista);

/**
 * @brief Mostra todos os elementos da lista
 * 
 * @param lista referencia para a lista
 * @return int 
 */
int lista_mostrar(Lista *lista);

/**
 * @brief Insere um elemento no incio da lista
 * 
 * @param lista Referencia para a lista
 * @param pessoa Elemento a ser inserido
 * @return int 
 */
int lista_inserir_inicio(Lista *lista, Pessoa pessoa);

/**
 * @brief Insere um elemento de forma ordenada na lista
 * 
 * @param lista Referencia para a lista
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int lista_inserir_ordenado(Lista *lista, Pessoa pessoa);

/**
 * @brief Insere um elemento no fim da lista
 * 
 * @param lista referencia para a lista
 * @param pessoa elemento a ser inserido
 * @return int 
 */
int lista_inserir_fim(Lista *lista, Pessoa pessoa);

/**
 * @brief Remove o primeiro elemento da lista
 * 
 * @param lista ponterio para a lista 
 * @return int 
 */
int lista_remover_inicio(Lista *lista);

/**
 * @brief Procura um elemento na lista e o remove
 * 
 * @param lista ponteiro para a lista
 * @param pessoa elemento a ser procurado
 * @return int 
 */
int lista_remover_elemento(Lista *lista, Pessoa pessoa);

/**
 * @brief Remove o ultimo elemento da lista
 * 
 * @param lista ponteiro para a lista
 * @return int 
 */
int lista_remover_fim(Lista *lista);

/**
 * @brief Busca um elemeto da lista e o atribui a referencia se existir
 * 
 * @param lista ponteiro para lista
 * @param id identidicador do elemento
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_elemento(Lista *lista, int id, Pessoa *pessoa);

/**
 * @brief Busca por um elemento em uma determinada posicao da lista e o atribui a referencia se existir.
 * 
 * @param lista referencia para a lista
 * @param posicao posição da lista para fazer a busca
 * @param pessoa referencia para atribuir o elemento
 * @return int 
 */
int lista_buscar_posicao(Lista *lista, int posicao, Pessoa *pessoa);


#endif