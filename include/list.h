#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

struct No {
    string nome;
    No* anterior;
    No* proximo;

    No(string n) : nome(n), anterior(nullptr), proximo(nullptr) {}
};

class ListaItinerario {
private:
    No* cabeca;
    No* cauda;
    int tamanho;

public:
    ListaItinerario();
    ~ListaItinerario();

    void inserirInicio(const string& nome);
    void inserirFim(const string& nome);
    void inserirPorPosicao(const string& nome, int posicao);
    void removerPrimeira();
    void removerUltima();
    void buscarPorNome(const string& termo);
    void listarIda();
    void listarInversa();
    void contarParadas();

    int getTamanho() const;
    bool estaVazia() const;
    string getNomeNaPosicao(int posicao) const;
};

#endif