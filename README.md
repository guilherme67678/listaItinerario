
## 1. Qual variação de lista foi escolhida?

Lista **duplamente encadeada**.


## 2. Por que essa estrutura é mais adequada para esse problema do que as demais?

A lista duplamente encadeada é a mais adequada porque duas das operações exigidas dependem diretamente da navegação bidirecional.

A operação de **listar em ordem inversa** percorre a lista de trás para frente usando o ponteiro `anterior`, partindo da `cauda`. Com uma lista simplesmente encadeada isso exigiria recursão ou estrutura auxiliar.

A operação de **remover a última parada** é O(1) porque a `cauda` conhece seu nó anterior diretamente. Em uma lista simplesmente encadeada seria necessário percorrer toda a lista para encontrar o penúltimo nó (O(n)).

As demais operações — inserção no início, no fim, por posição, remoção da primeira, busca e contagem — funcionam igualmente bem nas duas variações, portanto a lista duplamente encadeada não apresenta desvantagem neste contexto.


## 3. Haveria algum cenário real em que outra variação seria mais vantajosa?

Sim. Em uma **linha circular de ônibus**, onde o trajeto não tem início nem fim fixos e o veículo percorre os pontos em loop contínuo, a **lista circular duplamente encadeada** seria mais vantajosa.

Nesse modelo, o ponteiro `proximo` do último nó aponta de volta para o primeiro, e o ponteiro `anterior` do primeiro aponta para o último. Isso permite simular o percurso em loop sem verificar `nullptr`, avançar para a próxima parada sem tratamento de borda e calcular o caminho mais curto nos dois sentidos de forma natural — comportamentos impossíveis com a lista linear.