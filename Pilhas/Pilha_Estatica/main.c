/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa Principal
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    //Criando varivel
    Pilha *pilha;
    //Mensagem para usuario
    printf("@> Criando Pilha\n");
    //Tenta aloca memoria para a pilha
    pilha = pilha_criar();
    //Verifica se a lista foi criada
    //Destruindo a fila
    pilha_destruir(pilha);
    printf("@> Fila destruida\n");

    return 0;
}