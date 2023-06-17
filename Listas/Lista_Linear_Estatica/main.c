/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa Principal
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Programa principal*/
int main(){
    //Criando varivel
    Lista *lista;
    //Mensagem para o usuario
    printf(BOLD GREEN "@> Criando lista\n");
    //Tenta alocar memoria para a lista
    lista = lista_criar();
    //Verifica se a lista foi criada
    if(lista != NULL){
        //Mostrando informações da lista
        printf(BOLD YELLOW 
            "@> Lista Criada\n"
            "@> Tipo: Lista Linear Estatica\n"
            "@> Tamanho: %d\n", MAX);
        //Variavel de opçao
        int opcao;
        do{
            //Mostrando as opções 
            printf(BOLD BLUE
                   "+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir no inicio da lista            |\n"
                   "|[2] Inserir no meio da lista (ordenado)   |\n"
                   "|[3] Inserir no fim da lista               |\n"
                   "|[4] Remover do inicio da lista            |\n"
                   "|[5] Remover do meio (por valor)           |\n"
                   "|[6] Remover do fim da lista               |\n"
                   "|[7] Mostrar lista                         |\n"
                   "|[8] Consulta (por posição)                |\n"
                   "|[9] Consulta (por valor)                  |\n"
                   "|[0] Sair                                  |\n"
                   "+------------[Inserira-sua-opção]----------+\n"
                   NONE);

            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opcao
            switch(opcao){
                case 0:
                    break;
                case 7:
                    lista_mostrar(lista);
                    printf("@> Lista Mostrada\n"NONE);
                    break;
                default:
                    printf(BOLD RED "@> Opção Invalida!\n"NONE);
                    break;
            }

        }while(opcao != 0);

    }else{
        printf(RED "@> Erro ao criar a lista\n");
    }
    
    //Destruir a lista
    lista_destruir(lista);
    printf(BOLD GREEN "@> Lista Destruida\n" NONE);

    return 0;
}