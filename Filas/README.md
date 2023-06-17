# FILAS
São estruturas que são uma sequência de elementos do mesmo tipo
Seus elementos elementos possuem estrutura interna abstraída

_Filas são um tipo especial de lista_: 
 - Inserção e exclusão de elementos ocorrem nas extremidades 
 
_Aplicações_: aplicações onde há
 - Controle de fluxo
 - Recursos compartilhado (impressora, transação de banco de dados)
 - etc

__Tipos de Filas__
- _Estática_:
    - O espaço de memoria é alocada no momento da compilação
    - Exige a definição do numero maximo de elementos da fila
    - Acesso sequencial: elementos consecutivos na memoria

 - _Dinâmica_:
    - O espaço de memoria é alocada em tempo de execução
    - A fila cresce e diminui a medida que novos elementos são a inseridos ou removidos
    - Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento, é preciso percorrer todos os seus antecessores na fila.

__Operações Básicas__
 - Criar fila
 - Inserir elemento no final
 - Remover um elemento no inicio
 - Acessar ao elemento do inicio
 - Destruição da fila


 