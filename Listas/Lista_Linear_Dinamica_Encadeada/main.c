/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Programa Principal
int main(){

    Lista *lista;
    
    printf("@> Criando a lista\n");

    lista = lista_criar();

    lista_destruir(lista);
    printf("@> Lista destruida\n");
    
    return 0;
}