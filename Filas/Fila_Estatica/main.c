/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa Principal
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Programa Principal*/
int main(){
    //Criando variavel
    Fila *fila;
    //Pessoa pessoa;
    //Mensagem para usuario
    printf("@> Criando fila\n");
    //Tenta aloca memoria para a lista
    fila = fila_criar();
    //Verifica se a lista foi criada
    if(fila != NULL){
        printf(
            "@> Fila Criada\n"
            "@> Tipo: Fila Estatica\n"
            "@> Tamanho: %d\n", MAX);

    }else{
        printf("@> Erro ao criar a fila\n");
    }
    //Destruindo a fila
    fila_destruir(fila);
    printf("@> Fila destruida\n");
    return 0;
}