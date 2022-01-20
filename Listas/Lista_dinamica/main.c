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
    int tamanho, cheia, vazia;

    lista = lista_criar();
    tamanho = lista_tamanho(lista);
    cheia = lista_cheia(lista);
    vazia = lista_vazia(lista);

    printf("Lista-->Tamanho:[%i]\n", tamanho);
    printf("Lista-->Cheia:[%i]\n", cheia);
    printf("Lista-->Vazia:[%i]\n", vazia);

    lista_destruir(lista);


    return 0;
}