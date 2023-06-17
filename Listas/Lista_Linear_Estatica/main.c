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
    Pessoa pessoa;
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
            printf(BOLD GREEN
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
                   "+------------[Insira-sua-opção]------------+\n"
                   NONE);

            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opcao
            switch(opcao){
                int valida;
                case 0:
                    break;
                case 1:
                    //Pegando informação
                    printf("@> Digite o ID:\n");
                    scanf("%i", &pessoa.id);
                    //Chama a inserção no inicio
                    valida = lista_inserir_inicio(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Inserido no Inicio\n");
                    }else{
                        printf("@> Falha: Ao inserir no inicio\n");
                    }
                    break;
                case 2:
                    //Pegando informação
                    printf("@> Digite o ID:\n");
                    scanf("%i", &pessoa.id);
                    //Chama a inserção no inicio
                    valida = lista_inserir_ordenado(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Inserido no Meio\n");
                    }else{
                        printf("@> Falha: Ao inserir no Meio\n");
                    }
                    break;
                case 3:
                    //Pegando informação
                    printf("@> Digite o ID:\n");
                    scanf("%i", &pessoa.id);
                    //Chama a inserção no inicio
                    valida = lista_inserir_fim(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Inserido no Fim\n");
                    }else{
                        printf("@> Falha: Ao inserir no Fim\n");
                    }
                    break;
                case 4:
                    //Chama a remoção do inicio
                    valida = lista_remover_inicio(lista);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Removido no Inicio\n");
                    }else{
                        printf("@> Falha: Ao remover no inicio\n");
                    }
                    break;
                case 5:
                    //Pegando as informações
                    printf("@> Digite o ID a ser removido:\n");
                    scanf("%i", &pessoa.id);
                    //Chama a remoção do inicio
                    valida = lista_remover_elemento(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Elemento removido\n");
                    }else{
                        printf("@> Falha: Ao remover elemento\n");
                    }
                    break;
                case 6:
                    //Chama a remoção do inicio
                    valida = lista_remover_fim(lista);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Removido do fim\n");
                    }else{
                        printf("@> Falha: Ao remover do fim\n");
                    }
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