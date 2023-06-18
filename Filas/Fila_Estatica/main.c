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
    Pessoa pessoa;
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
        int opcao;
        do{
            //Mostrando as opções 
            printf(
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
                    valida = fila_inserir(fila, pessoa);
                    if(valida > 0){
                        printf("@> Sucesso: Inserido no fim\n");
                    }else{
                        printf("@> Falha: Ao inserir no inicio\n");
                    }
                    break;
                case 2:
                    //Chama a remoção 
                    valida = fila_remover(fila);
                    //Verifica validação
                    if(valida > 0){
                        printf("@> Sucesso: Elemento removido do inico \n");
                    }else{
                        printf("@> Falha: Ao remover elemento\n");
                    }
                    break;
                case 3:
                    fila_mostrar(fila);
                    printf("@> Fila mostrada\n");
                    break;
                case 4:
                    //Pegando informaçao
                    printf("@> Digite aposição:\n");
                    scanf("%i", &indice);
                    //Chamando a função
                    valida = fila_buscar_posicao(fila, indice, &pessoa);
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
                    valida = fila_buscar_elemento(fila, id, &pessoa);
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
    fila_destruir(fila);
    printf("@> Fila destruida\n");
    return 0;
}