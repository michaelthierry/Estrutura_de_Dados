/** Estrutura: Lista Estattica Linear
 *  Modulo: Principal
 *  Autor: Michael Thierry 
*/
#include <stdio.h>
#include "lista.h"

int main(){

    Lista *lista;
    

    lista = lista_criar();

    lista_tamanho(lista);
    

    lista_destruir(lista);

    return 0;
}