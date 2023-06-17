/**
 * @file fila.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Fila Estatica
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_criar(){
    Fila *fila;
    fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        fila->quantidade = 0;
    }
    return fila;
}
void fila_destruir(Fila *fila){
    free(fila);
}