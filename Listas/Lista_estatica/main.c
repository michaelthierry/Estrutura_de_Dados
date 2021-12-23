/** Estrutura: Lista Estattica Linear
 *  Modulo: Principal
 *  Autor: Michael Thierry 
*/
#include <stdio.h>
#include "lista.h"

int main(){

    Lista *lista;

    lista = lista_criar();
    printf("%p\n", lista);

    return 0;
}