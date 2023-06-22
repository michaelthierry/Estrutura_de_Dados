/**
 * @file console.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Interface que exibe as opções para os usuarios
 * @version 0.1 
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Bibliotecas 
#include <stdio.h>
#include "lista.h"
#include "constantes.h"

/**
 * @brief Pega informações do usario para construir um elemento pesssoa
 * 
 * @return Pessoa 
 */
Pessoa pega_dados();

/**
 * @brief Fornece uma interface para obter dados do usario via
 * prompt e manipular a estrutura.
 * 
 * @return int 
 */
int usuario();

/**
 * @brief Valida as operações de inserçao e remoçao
 * 
 * @param valida retorno da função
 * @param codigo codigo de operação
 */
void valida_operacao(int valida, int codigo );

/**
 * @brief valida as operaçoes de busca
 * 
 * @param valida retorno da função
 * @param pessoa elemento a ser mostrado
 */
void valida_busca(int valida, Pessoa pessoa);

Pessoa pega_dados(){
    Pessoa pessoa;
    //Pegando informação
    printf(
        BOLD CYAN
        "+------------------------------------------+\n"
        "@> Digite o ID:\n"
        NONE
    );
    scanf("%i", &pessoa.id);
    //Removendo o \n
    while(getchar()!= '\n');
    printf(BOLD CYAN"@> Digite o Nome:\n"NONE);
    //scanf("%s", pessoa.nome);
    //lendo nome pegando espaços em brancos ja que scanf nao faz.
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    printf(
        BOLD CYAN
        "+------------------------------------------+\n"
        NONE
    );
    //retorna os dados
    return pessoa;
}

int usuario(){
    //Criando varivel
    Lista *lista;
    Pessoa pessoa;
    //Mensagem para o usuario
    printf(BOLD GREEN "@> Criando lista\n");
    //Tenta alocar memoria para a lista
    lista = lista_criar();
    //Verifica se a lista foi criada
    int opcao;
    if(lista != NULL){
        //Mostrando informações da lista
        printf(BOLD YELLOW 
            "@> Lista Criada\n"
            "@> Tipo: Lista Linear Estatica\n"
            "@> Tamanho Maximo: %d elementos\n", MAX
        );
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
                   NONE
            );

            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opcao
            switch(opcao){
                int valida, indice, id;
                case 0:
                    break;
                case 1:
                    //Pegando informação
                    pessoa = pega_dados();
                    //Chama a inserção no inicio
                    valida = lista_inserir_inicio(lista, pessoa);
                    //Verifica validação
                    valida_operacao(valida, INSERIR);
                    break;
                case 2:
                    //Pegando informação
                    pessoa = pega_dados();
                    //Chama a inserção no inicio
                    valida = lista_inserir_ordenado(lista, pessoa);
                    //Verifica validação
                    valida_operacao(valida, INSERIR);
                    break;
                case 3:
                    //Pegando informação
                    pessoa = pega_dados();
                    //Chama a inserção no inicio
                    valida = lista_inserir_fim(lista, pessoa);
                    //Verifica validação
                    valida_operacao(valida, INSERIR);
                    break;
                case 4:
                    //Chama a remoção do inicio
                    valida = lista_remover_inicio(lista);
                    //Verifica validação
                    valida_operacao(valida, REMOVER);
                    break;
                case 5:
                    //Pegando as informações
                    printf(BOLD CYAN"@> Digite o ID a ser removido:\n"NONE);
                    scanf("%i", &pessoa.id);
                    //Chama a remoção do inicio
                    valida = lista_remover_elemento(lista, pessoa);
                    //Verifica validação
                    valida_operacao(valida, REMOVER);
                    break;
                case 6:
                    //Chama a remoção do fim
                    valida = lista_remover_fim(lista);
                    //Verifica validação
                    valida_operacao(valida, REMOVER);
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
                    //Chama a validação da operação
                    valida_busca(valida, pessoa);
                    break;
                case 9:
                    //Pegando informaçao
                    printf(BOLD CYAN"@> Digite o ID:\n"NONE);
                    scanf("%i", &id);
                    //Chamando a função
                    valida = lista_buscar_elemento(lista, id, &pessoa);
                    //Chama a validação da operação
                    valida_busca(valida, pessoa);
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

    return 1;
}

void valida_operacao(int valida, int codigo){
    switch(codigo){
        case 1:
            if(valida > 0){
                printf(SUCESSO "Ao inserir na lista\n");
            }else{
                printf(FALHA "Ao inserir na lista\n");
            }
            break;
        case 2:
            if(valida > 0){
                printf(SUCESSO "Ao remover da lista\n");
            }else{
                printf(FALHA "Ao remover da lista\n");
            }
            break;
        default:
            printf(FALHA "Código invalido\n");
            break;
    }
}

void valida_busca(int valida, Pessoa pessoa){
    if(valida > 0){
        printf(SUCESSO "Elemento encontrado\n");
        printf(BOLD YELLOW"@> Elemento:\nID:[%d]\nNome:[%s]\n"NONE, pessoa.id, pessoa.nome);
    }else{
        printf(FALHA "Elemento não pode ser encontrado\n");
    }
}