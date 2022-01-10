/**
 * @file main.c
 * @author Michael (michaelthierry86@gmail.com)
 * @brief Modo usuario
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "lista.h"

int main(){

    Lista *lista;
    int opcao;
    Dado elemento;
    
    lista = lista_criar();

    do{
        printf("\t--------------- LISTA LINEAR ESTATICA------------------\n"
               "\t|[1] Inserir no inicio da lista\n"
               "\t|[2] Inserir no meio da lista (ordenado)\n"
               "\t|[3] Inserir no fim da lista\n"
               "\t|[4] Remover do inicio da lista\n"
               "\t|[5] Remover do meio (por valor)\n"
               "\t|[6] Remover do fim da lista\n"
               "\t|[7] Mostrar lista\n"
               "\t|[0] Sair\n"
               "\t------------------Inserira sua opção-------------------\n");

        scanf("%i", &opcao);

        if(opcao == 1){
            int valida_operacao;

            printf("Digite o valor:\n");

            scanf("%i", &elemento.valor);

            valida_operacao = lista_inserir_inicio(lista, elemento);

            if(valida_operacao == 1){
                printf("Inserido no inicio\n");
            }else{
                printf("Erro na operação\n");
            }

        }else if(opcao == 2){
            int valida_operacao;

            printf("Digite o valor:\n");

            scanf("%i", &elemento.valor);

            valida_operacao = lista_inserir_meio(lista, elemento);

            if(valida_operacao == 1){
                printf("Inserido no meio\n");
            }else{
                printf("Erro na operação\n");
            }
            
        }else if(opcao == 3){
            int valida_operacao;

            printf("Digite o valor:\n");

            scanf("%i", &elemento.valor);

            valida_operacao = lista_inserir_fim(lista, elemento);

            if(valida_operacao == 1){
                printf("Inserido no fim\n");
            }else{
                printf("Erro na operação\n");
            }
            
        }else if(opcao == 4){
            int valida_operacao;
            valida_operacao = lista_remover_inicio(lista);
            if(valida_operacao == 1){
                printf("Removido do inicio\n");
            }else{
                printf("Erro na operação\n");
            }

        }else if(opcao == 5){
            int valida_operacao, valor;

            printf("Digite o valor a ser removido:\n");
            scanf("%i", &valor);
            
            valida_operacao = lista_remover_meio(lista, valor);

            if(valida_operacao == 1){
                printf("Removido do meio\n");
            }else{
                printf("Erro na operação\n");
            }
            
        }else if(opcao == 6){
            int valida_operacao;

            valida_operacao = lista_remover_fim(lista);

            if(valida_operacao == 1){
                printf("Removido do fim\n");
            }else{
                printf("Erro na operação\n");
            }
            
        }else if(opcao == 7){
            lista_mostrar(lista);
            printf("Lista mostrada\n");
        }else if(opcao == 0){
            printf("Lista destruida\n");
            break;
        }

    }while(opcao > 0 && opcao <= 7);
    
    lista_destruir(lista);

    return 0;
}