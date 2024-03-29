/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa principal
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
            "@> Tamanho Maximo: Dinâmico\n");
        //Variavel de opçao
        int opcao;
        do{
            //Mostrando as opções 
            printf(BOLD GREEN
                   "+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir no inicio da lista            |\n"
                   "|[2] Inserir em ordem na lista (por ID)    |\n"
                   "|[3] Inserir no fim da lista               |\n"
                   "|[4] Remover do inicio da lista            |\n"
                   "|[5] Remover do meio (por ID)              |\n"
                   "|[6] Remover do fim da lista               |\n"
                   "|[7] Mostrar lista                         |\n"
                   "|[8] Consultar (por indice)                |\n"
                   "|[9] Consultar (por ID)                    |\n"
                   "|[0] Sair                                  |\n"
                   "+------------[Insira-sua-opção]------------+\n"
                   NONE);

            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opcao
            switch(opcao){
                int valida, indice, id;
                case 0:
                    break;
                case 1:
                    //Pegando dados do usuario
                    pessoa = entrada_dados();
                    //tenta inserir no inicio
                    valida = lista_inserir_inicio(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Inserido no inicio da lista\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao inserir no inicio da lista\n");
                    }
                    break;
                case 2:
                    //Pegando dados do usuario
                    pessoa = entrada_dados(); 
                    //Chama a inserção no inicio
                    valida = lista_inserir_ordenado(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Inserido em ordem na lista\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao inserir em ordem na lista\n");
                    }
                    break;
                case 3:
                    //Pegando dados do usuario
                    pessoa = entrada_dados(); 
                    //Chama a inserção no inicio
                    valida = lista_inserir_fim(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Inserido no fim da lista\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao inserir no fim da lista\n");
                    }
                    break;
                case 4:
                    //Chama a remoção do inicio
                    valida = lista_remover_inicio(lista);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Removido do inicio da lista\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao remover do inicio da lista\n");
                    }
                    break;
                case 5:
                    //Pegando as informações
                    printf(BOLD CYAN"@> Digite o ID a ser removido:\n"NONE);
                    scanf("%i", &pessoa.id);
                    //Chama a remoção do inicio
                    valida = lista_remover_elemento(lista, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Elemento removido da lista\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao remover elemento da lista\n");
                    }
                    break;
                case 6:
                    //Chama a remoção do inicio
                    valida = lista_remover_fim(lista);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Removido do fim da lista\n");
                    }else{
                        printf(BOLD RED"@> Falha: Ao remover do fim da lista\n");
                    }
                    break;
                case 7:
                    lista_mostrar(lista);
                    printf(BOLD YELLOW"@> Lista Mostrada\n"NONE);
                    break;
                case 8:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite a posição:\n"NONE);
                    scanf("%i", &indice);
                    //Chamando a função
                    valida = lista_buscar_posicao(lista, indice, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Elemento encontrado\n");
                        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Elemento não pode ser encontrado\n");
                    }
                    break;
                case 9:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite o ID:\n"NONE);
                    scanf("%i", &id);
                    //Chamando a função
                    valida = lista_buscar_elemento(lista, id, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Elemento encontrado\n");
                        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Elemento não pode ser encontrado\n");
                    }
                    break;
                default:
                    printf(BOLD RED "@> Opção Invalida!\n"NONE);
                    break;
            }

        }while(opcao != 0);

    }else{
        printf(BOLD RED "@> Erro ao criar a lista\n"NONE);
    }
    
    //Destruir a lista
    lista_destruir(lista);
    printf(BOLD GREEN "@> Lista Destruida\n" NONE);

    return 0;
}