#include <iostream>
#include <string>
#include "../include/list.h"
using namespace std;

int totalTestes = 0;
int testsPassaram = 0;

void checar(const string& descricao, bool condicao) {
    totalTestes++;
    if (condicao) {
        testsPassaram++;
        cout << "  [PASS] " << descricao << "\n";
    } else {
        cout << "  [FAIL] " << descricao << "\n";
    }
}

void cabecalho(const string& titulo) {
    cout << " " << titulo << "\n";
    
}

void testarInserirInicio() {
    cabecalho("TESTE: Inserir no Inicio");
    ListaItinerario lista;

    lista.inserirInicio("Parada A");
    checar("Tamanho e 1 apos inserir no inicio", lista.getTamanho() == 1);
    checar("Primeiro elemento e 'Parada A'", lista.getNomeNaPosicao(1) == "Parada A");

    lista.inserirInicio("Parada B");
    checar("Tamanho e 2 apos segunda insercao", lista.getTamanho() == 2);
    checar("Novo primeiro elemento e 'Parada B'", lista.getNomeNaPosicao(1) == "Parada B");
    checar("Segundo elemento ainda e 'Parada A'", lista.getNomeNaPosicao(2) == "Parada A");
}

void testarInserirFim() {
    cabecalho("TESTE: Inserir no Fim");
    ListaItinerario lista;

    lista.inserirFim("Parada X");
    checar("Tamanho e 1 apos inserir no fim", lista.getTamanho() == 1);
    checar("Primeiro elemento e 'Parada X'", lista.getNomeNaPosicao(1) == "Parada X");

    lista.inserirFim("Parada Y");
    checar("Tamanho e 2 apos segunda insercao", lista.getTamanho() == 2);
    checar("Segundo elemento e 'Parada Y'", lista.getNomeNaPosicao(2) == "Parada Y");
}

void testarInserirPorPosicao() {
    cabecalho("TESTE: Inserir por Posicao");
    ListaItinerario lista;

    lista.inserirFim("A");
    lista.inserirFim("C");
    lista.inserirPorPosicao("B", 2);

    checar("Tamanho e 3 apos insercao por posicao", lista.getTamanho() == 3);
    checar("Posicao 1 e 'A'", lista.getNomeNaPosicao(1) == "A");
    checar("Posicao 2 e 'B'", lista.getNomeNaPosicao(2) == "B");
    checar("Posicao 3 e 'C'", lista.getNomeNaPosicao(3) == "C");

    lista.inserirPorPosicao("Inicio", 0);
    checar("Posicao <= 1 insere no inicio", lista.getNomeNaPosicao(1) == "Inicio");

    lista.inserirPorPosicao("Fim", 999);
    checar("Posicao > tamanho insere no fim", lista.getNomeNaPosicao(lista.getTamanho()) == "Fim");
}

void testarRemoverPrimeira() {
    cabecalho("TESTE: Remover Primeira Parada");
    ListaItinerario lista;

    lista.inserirFim("A");
    lista.inserirFim("B");
    lista.inserirFim("C");

    lista.removerPrimeira();
    checar("Tamanho e 2 apos remocao", lista.getTamanho() == 2);
    checar("Novo primeiro e 'B'", lista.getNomeNaPosicao(1) == "B");

    lista.removerPrimeira();
    lista.removerPrimeira();
    checar("Lista vazia apos remover todos", lista.estaVazia());

    lista.removerPrimeira();
    checar("Remover de lista vazia nao causa crash", true);
}

void testarRemoverUltima() {
    cabecalho("TESTE: Remover Ultima Parada");
    ListaItinerario lista;

    lista.inserirFim("A");
    lista.inserirFim("B");
    lista.inserirFim("C");

    lista.removerUltima();
    checar("Tamanho e 2 apos remocao", lista.getTamanho() == 2);
    checar("Ultimo elemento agora e 'B'", lista.getNomeNaPosicao(lista.getTamanho()) == "B");

    lista.removerUltima();
    lista.removerUltima();
    checar("Lista vazia apos remover todos", lista.estaVazia());

    lista.removerUltima();
    checar("Remover de lista vazia nao causa crash", true);
}

void testarBusca() {
    cabecalho("TESTE: Buscar Parada por Nome");
    ListaItinerario lista;

    lista.inserirFim("Terminal Central");
    lista.inserirFim("Rua das Flores");
    lista.inserirFim("Praca da Republica");

    lista.buscarPorNome("flores");
    checar("Busca por 'flores' executada sem crash", true);

    lista.buscarPorNome("terminal");
    checar("Busca por 'terminal' executada sem crash", true);

    lista.buscarPorNome("xyz");
    checar("Busca sem resultado executada sem crash", true);
}

void testarContagem() {
    cabecalho("TESTE: Contar Paradas");
    ListaItinerario lista;

    checar("Lista vazia tem tamanho 0", lista.getTamanho() == 0);
    lista.inserirFim("A");
    lista.inserirFim("B");
    lista.inserirFim("C");
    checar("Tamanho e 3 apos 3 insercoes", lista.getTamanho() == 3);
    lista.removerPrimeira();
    checar("Tamanho e 2 apos remocao", lista.getTamanho() == 2);
}

void testarListagem() {
    cabecalho("TESTE: Listagem (Ida e Inversa)");
    ListaItinerario lista;

    lista.inserirFim("Ponto 1");
    lista.inserirFim("Ponto 2");
    lista.inserirFim("Ponto 3");

    lista.listarIda();
    checar("Listagem ida executada sem crash", true);

    lista.listarInversa();
    checar("Listagem inversa executada sem crash", true);

    checar("Posicao 1 e 'Ponto 1'", lista.getNomeNaPosicao(1) == "Ponto 1");
    checar("Posicao 3 e 'Ponto 3'", lista.getNomeNaPosicao(3) == "Ponto 3");
}

int main() {
    cout << "       SUITE DE TESTES - ITINERARIO     \n";
    

    testarInserirInicio();
    testarInserirFim();
    testarInserirPorPosicao();
    testarRemoverPrimeira();
    testarRemoverUltima();
    testarBusca();
    testarContagem();
    testarListagem();


    cout << "             RESULTADO FINAL            \n";
    cout << "  Testes executados : " << totalTestes << "                   \n";
    cout << "  Testes aprovados  : " << testsPassaram << "                   \n";
    cout << " Testes reprovados : " << (totalTestes - testsPassaram) << " \n";
   

    return (testsPassaram == totalTestes) ? 0 : 1;
}