#include "../include/list.h"
#include <iostream>
#include <algorithm>
using namespace std;

ListaItinerario::ListaItinerario()
    : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

ListaItinerario::~ListaItinerario() {
    No* atual = cabeca;
    while (atual != nullptr) {
        No* temp = atual->proximo;
        delete atual;
        atual = temp;
    }
}

void ListaItinerario::inserirInicio(const string& nome) {
    No* novo = new No(nome);
    if (cabeca == nullptr) {
        cabeca = cauda = novo;
    } else {
        novo->proximo = cabeca;
        cabeca->anterior = novo;
        cabeca = novo;
    }
    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida no inicio da rota.\n";
}

void ListaItinerario::inserirFim(const string& nome) {
    No* novo = new No(nome);
    if (cauda == nullptr) {
        cabeca = cauda = novo;
    } else {
        novo->anterior = cauda;
        cauda->proximo = novo;
        cauda = novo;
    }
    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida no fim da rota.\n";
}

void ListaItinerario::inserirPorPosicao(const string& nome, int posicao) {
    if (posicao <= 1) {
        inserirInicio(nome);
        return;
    }
    if (posicao > tamanho) {
        inserirFim(nome);
        return;
    }

    No* novo = new No(nome);
    No* atual = cabeca;
    for (int i = 1; i < posicao - 1; i++)
        atual = atual->proximo;

    novo->proximo = atual->proximo;
    novo->anterior = atual;
    if (atual->proximo != nullptr)
        atual->proximo->anterior = novo;
    atual->proximo = novo;

    tamanho++;
    cout << "[OK] Parada \"" << nome << "\" inserida na posicao " << posicao << ".\n";
}

void ListaItinerario::removerPrimeira() {
    if (cabeca == nullptr) {
        cout << "[ERRO] A rota esta vazia.\n";
        return;
    }
    string nome = cabeca->nome;
    No* temp = cabeca;
    cabeca = cabeca->proximo;
    if (cabeca != nullptr)
        cabeca->anterior = nullptr;
    else
        cauda = nullptr;
    delete temp;
    tamanho--;
    cout << "[OK] Parada \"" << nome << "\" removida do inicio da rota.\n";
}

void ListaItinerario::removerUltima() {
    if (cauda == nullptr) {
        cout << "[ERRO] A rota esta vazia.\n";
        return;
    }
    string nome = cauda->nome;
    No* temp = cauda;
    cauda = cauda->anterior;
    if (cauda != nullptr)
        cauda->proximo = nullptr;
    else
        cabeca = nullptr;
    delete temp;
    tamanho--;
    cout << "[OK] Parada \"" << nome << "\" removida do fim da rota.\n";
}

void ListaItinerario::buscarPorNome(const string& termo) {
    if (cabeca == nullptr) {
        cout << "[ERRO] A rota esta vazia.\n";
        return;
    }

    string termoBusca = termo;
    transform(termoBusca.begin(), termoBusca.end(), termoBusca.begin(), ::tolower);

    No* atual = cabeca;
    int posicao = 1;
    bool encontrou = false;

    cout << "\n--- Resultado da Busca por \"" << termo << "\" ---\n";
    while (atual != nullptr) {
        string nomeMin = atual->nome;
        transform(nomeMin.begin(), nomeMin.end(), nomeMin.begin(), ::tolower);
        if (nomeMin.find(termoBusca) != string::npos) {
            cout << "  Posicao " << posicao << ": " << atual->nome << "\n";
            encontrou = true;
        }
        atual = atual->proximo;
        posicao++;
    }

    if (!encontrou)
        cout << "  Nenhuma parada encontrada com o termo \"" << termo << "\".\n";
    cout << "--------------------------------------------\n";
}

void ListaItinerario::listarIda() {
    if (cabeca == nullptr) {
        cout << "[AVISO] A rota esta vazia.\n";
        return;
    }

    cout << "\n========== ROTA COMPLETA (IDA) ==========\n";
    No* atual = cabeca;
    int posicao = 1;
    while (atual != nullptr) {
        cout << "  " << posicao << ". " << atual->nome;
        if (atual->proximo != nullptr) cout << " -->";
        cout << "\n";
        atual = atual->proximo;
        posicao++;
    }
    cout << "=========================================\n";
    cout << "Total de paradas: " << tamanho << "\n";
}

void ListaItinerario::listarInversa() {
    if (cauda == nullptr) {
        cout << "[AVISO] A rota esta vazia.\n";
        return;
    }

    cout << "\n========= ROTA INVERSA (VOLTA) =========\n";
    No* atual = cauda;
    int posicao = tamanho;
    while (atual != nullptr) {
        cout << "  " << posicao << ". " << atual->nome;
        if (atual->anterior != nullptr) cout << " -->";
        cout << "\n";
        atual = atual->anterior;
        posicao--;
    }
  
    cout << "Total de paradas: " << tamanho << "\n";
}

void ListaItinerario::contarParadas() {
    cout << "[INFO] Total de paradas cadastradas na rota: " << tamanho << "\n";
}

int ListaItinerario::getTamanho() const {
    return tamanho;
}

bool ListaItinerario::estaVazia() const {
    return tamanho == 0;
}

string ListaItinerario::getNomeNaPosicao(int posicao) const {
    if (posicao < 1 || posicao > tamanho) return "";
    No* atual = cabeca;
    for (int i = 1; i < posicao; i++)
        atual = atual->proximo;
    return atual->nome;
}