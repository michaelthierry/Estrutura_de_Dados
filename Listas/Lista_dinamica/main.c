/**
 * @file mian.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Modo usuário
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "lista.h"

int main(){
    Lista *lista;
    int tamanho, cheia, vazia, I_inicio;
    Dado dado;
    dado.valor = 30;

    lista = lista_criar();
    
    lista_inserir_inicio(lista, dado);
    dado.valor = 10;
    lista_inserir_inicio(lista, dado);
    dado.valor = 40;
    lista_inserir_fim(lista, dado);
    dado.valor = 20;
    lista_inserir_meio(lista, dado);

    lista_mostrar(lista);

    tamanho = lista_tamanho(lista);
    cheia = lista_cheia(lista);
    vazia = lista_vazia(lista);
    
    printf("Lista-->Tamanho:[%i]\n", tamanho);
    printf("Lista-->Cheia:[%i]\n", cheia);
    printf("Lista-->Vazia:[%i]\n", vazia);

    lista_destruir(lista);


    return 0;
}