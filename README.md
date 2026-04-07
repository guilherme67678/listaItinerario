# Itinerário de Ônibus

## Descrição

Sistema em C++ para gerenciar paradas de uma linha de ônibus usando lista duplamente encadeada.

---

## Requisitos

- GCC 9.0 ou superior
- VSCode com extensão **C/C++** (Microsoft)
- No Windows: extensão **WSL** + `wsl --install` no PowerShell

---

## Compilação e Execução

```bash
g++ -std=c++17 -o programa main.cpp src/list.cpp -I include
./programa        # Linux
.\programa.exe    # Windows
```

**Testes:**
```bash
g++ -std=c++17 -o tests tests/tests.cpp src/list.cpp -I include
./tests        # Linux
.\tests.exe    # Windows
```

---

## 1. Qual variação de lista foi escolhida?

Lista **duplamente encadeada**.

---

## 2. Por que essa estrutura é mais adequada?

A operação de **listar em ordem inversa** percorre a lista pelo ponteiro `anterior`, partindo da `cauda` — sem necessidade de recursão ou estrutura auxiliar. A **remoção da última parada** é O(1) pois a `cauda` já conhece seu nó anterior; em uma lista simples seria O(n).

---

## 3. Haveria cenário em que outra variação seria mais vantajosa?

Sim. Em uma **linha circular**, a **lista circular duplamente encadeada** seria mais adequada, pois o último nó aponta de volta para o primeiro, permitindo percorrer o trajeto em loop sem verificar `nullptr` e calcular o caminho mais curto nos dois sentidos naturalmente.
