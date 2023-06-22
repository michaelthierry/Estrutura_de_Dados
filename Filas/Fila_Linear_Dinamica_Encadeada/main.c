/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa principal
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    //Criando variavel
    Fila *fila;
    Pessoa pessoa;
    //Mensagem para usuario
    printf(BOLD GREEN"@> Criando fila\n");
    //Tenta aloca memoria para a lista
    fila = fila_criar();
    //Verifica se a lista foi criada
    if(fila != NULL){
        printf(BOLD YELLOW
            "@> Fila Criada\n"
            "@> Tipo: Fila Linear Estatica \n"
            "@> Tamanho: Dinamica\n");
        int opcao;
        do{
            //Mostrando as opções 
            printf(BOLD GREEN
                   "+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir na fila                       |\n"
                   "|[2] Remover da fila                       |\n"
                   "|[3] Mostrar fila                          |\n"
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
                    valida = fila_inserir(fila, pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Inserido na fila\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao inserir na fila\n");
                    }
                    break;
                case 2:
                    //Chama a remoção 
                    valida = fila_remover(fila);
                    //Verifica validação
                    if(valida > 0){
                        printf(BOLD GREEN"@> Sucesso:"NONE" Removido da fila\n");
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Ao remover da fila\n");
                    }
                    break;
                case 3:
                    fila_mostrar(fila);
                    printf(BOLD YELLOW"@> Fila mostrada\n"NONE);
                    break;
                case 4:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite a posição:\n"NONE);
                    scanf("%i", &indice);
                    //Chamando a função
                    valida = fila_buscar_posicao(fila, indice, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Suceso:"NONE" Elemento encontrado\n");
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
                    valida = fila_buscar_elemento(fila, id, &pessoa);
                    if(valida > 0){
                        printf(BOLD GREEN"@> Suceso:"NONE" Elemento encontrado\n");
                        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
                    }else{
                        printf(BOLD RED"@> Falha:"NONE" Elemento não pode ser encontrado\n");
                    }
                    break;
                default:
                    printf(BOLD RED"@> Opção Invalida!\n"NONE);
                    break;
            }

        }while(opcao != 0);

    }else{
        printf(BOLD RED"@> Erro ao criar a fila\n"NONE);
    }
    //Destruindo a fila
    fila_destruir(fila);
    printf(BOLD GREEN"@> Fila destruida\n"NONE);
    return 0;

}