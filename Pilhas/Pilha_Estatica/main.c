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
    Pessoa pessoa;
    //Mensagem para usuario
    printf(BOLD GREEN"@> Criando Pilha\n");
    //Tenta aloca memoria para a pilha
    pilha = pilha_criar();
    //Verifica se a lista foi criada
    if(pilha != NULL){
        printf(BOLD YELLOW
            "@> Pilha Criada\n"
            "@> Tipo: Pilha Estatica\n"
            "@> Tamanho Máximo: %d elementos\n", MAX);
        int opcao;
        do{
            //Mostrando as opções 
            printf(BOLD GREEN
                   "+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir na pilha                      |\n"
                   "|[2] Remover da pilha                      |\n"
                   "|[3] Mostrar pilha                         |\n"
                   "|[4] Consultar (por indice)                |\n"
                   "|[5] Consultar (por ID)                    |\n"
                   "|[0] Sair                                  |\n"
                   "+------------[Insira-sua-opção]------------+\n"
                NONE);
            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opção
            switch(opcao){
                int valida, indice, id;
                case 0:
                    break;
                case 1:
                    //Pegando informação
                    printf(BOLD CYAN"@> Digite o ID:\n"NONE);
                    scanf("%i", &pessoa.id);
                    printf(BOLD CYAN"@> Digite o Nome:\n"NONE);
                    scanf("%s", pessoa.nome);
                    //Chama a insercão
                    valida = pilha_inserir(pilha, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Inserido no topo da Pilha\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao inserir no topo da Pilha\n");
                    }
                    break;
                case 2:
                    //Chama a remoção 
                    valida = pilha_remover(pilha);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Removido do topo da pilha\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao remover do topo da pilha\n");
                    }
                    break;
                case 3:
                    pilha_mostrar(pilha);
                    printf(BOLD YELLOW"@> Pilha mostrada\n"NONE);
                    break;
                case 4:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite a posição:\n"NONE);
                    scanf("%i", &indice);
                    //Chamando a função
                    valida = pilha_buscar_posicao(pilha, indice, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Elemento encontrado\n");
                        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Elemento não pode ser encontrado\n");
                    }
                    break;
                case 5:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite o ID:\n"NONE);
                    scanf("%i", &id);
                    //Chamando a função
                    valida = pilha_buscar_elemento(pilha, id, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Elemento encontrado\n");
                        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Elemento não pode ser encontrado\n");
                    }
                    break;
                default:
                    printf("@> Opção Invalida!\n");
                    break;
            }

        }while(opcao != 0);

    }else{
        printf(BOLD RED"@> Erro ao criar a Pilha\n"NONE);
    }
    //Destruindo a fila
    pilha_destruir(pilha);
    printf(BOLD GREEN"@> Pilha destruida\n"NONE);
    return 0;
}