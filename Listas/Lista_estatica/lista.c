/** Estrutura: Lista Estattica Linear
 *  Modulo: Incrementado
 *  Autor: Michael Thierry 
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar();

void lista_destruir(Lista *lista);

void lista_tamanho(Lista *lista);

int lista_cheia(Lista *lista);

int lista_vazia(Lista *lista);

int lista_inserir_inicio(Lista *lista, Dado Elemento);

int lista_inserir_meio(Lista *lista, Dado Elemento);

int lista_inserir_fim(Lista *lista, Dado Elemento);

int lista_remover_inicio(Lista *lista);

int lista_remover_meio(Lista *lista);

int lista_remover_fim(Lista *lista);

int lista_mostrar(Lista *lista);