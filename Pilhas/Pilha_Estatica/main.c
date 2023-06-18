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
    printf("@> Criando Pilha\n");
    //Tenta aloca memoria para a pilha
    pilha = pilha_criar();
    //Verifica se a lista foi criada
    if(pilha != NULL){
        printf(
            "@> Fila Criada\n"
            "@> Tipo: Fila Estatica\n"
            "@> Tamanho: %d\n", MAX);
        int opcao;
        do{
            //Mostrando as opções 
            printf(
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
                );
            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opção
            switch(opcao){
                int valida, indice, id;
                case 0:
                    break;
                case 1:
                    //Pegando informação
                    printf("@> Digite o ID:\n");
                    scanf("%i", &pessoa.id);
                    printf("@> Digite o Nome:\n");
                    scanf("%s", pessoa.nome);
                    //Chama a insercão
                    valida = pilha_inserir(pilha, pessoa);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Inserido na Pilha\n");
                    }else{
                        printf("@> Falha: Ao inserir na Pilha\n");
                    }
                    break;
                case 2:
                    //Chama a remoção 
                    valida = pilha_remover(pilha);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Elemento removido do topo \n");
                    }else{
                        printf("@> Falha: Ao remover elemento\n");
                    }
                    break;
                case 3:
                    pilha_mostrar(pilha);
                    printf("@> Pilha mostrada\n");
                    break;
                case 4:
                    //Pegando informaçao
                    printf("@> Digite aposição:\n");
                    scanf("%i", &indice);
                    //Chamando a função
                    //valida = fila_buscar_posicao(fila, indice, &pessoa);
                    if(valida > 0){
                        printf("@> Suceso: Elemento encontrado\n");
                        printf("@> Elemento: |%d|\n", pessoa.id);
                    }else{
                        printf("@> Falha: Elemento não pode ser encontrado\n");
                    }
                    break;
                case 5:
                    //Pegando informaçao
                    printf("@> Digite o id:\n");
                    scanf("%i", &id);
                    //Chamando a função
                    //valida = fila_buscar_elemento(fila, id, &pessoa);
                    if(valida > 0){
                        printf("@> Suceso: Elemento encontrado\n");
                        printf("@> Elemento: |%d|\n", pessoa.id);
                    }else{
                        printf("@> Falha: Elemento não pode ser encontrado\n");
                    }
                    break;
                default:
                    printf("@> Opção Invalida!\n");
                    break;
            }

        }while(opcao != 0);

    }else{
        printf("@> Erro ao criar a fila\n");
    }
    //Destruindo a fila
    pilha_destruir(pilha);
    printf("@> Fila destruida\n");
    return 0;
}