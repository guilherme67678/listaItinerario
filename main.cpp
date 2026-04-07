#include <iostream>
#include <string>
#include "include/list.h"
using namespace std;

void exibirMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Inserir parada no inicio\n";
    cout << "2. Inserir parada no fim\n";
    cout << "3. Inserir parada por posicao\n";
    cout << "4. Remover primeira parada\n";
    cout << "5. Remover ultima parada\n";
    cout << "6. Buscar parada por nome\n";
    cout << "7. Listar rota (ida)\n";
    cout << "8. Listar rota (inversa)\n";
    cout << "9. Contar paradas\n";
    cout << "0. Sair\n";
    cout << "Opcao: ";
}

int main() {
    ListaItinerario rota;
    int opcao;

    cout << "Bem-vindo ao Sistema de Gerenciamento de Itinerario!\n";

    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();

        string nome;
        int posicao;

        switch (opcao) {
            case 1:
                cout << "Nome da parada: ";
                getline(cin, nome);
                rota.inserirInicio(nome);
                break;
            case 2:
                cout << " Nome da parada: ";
                getline(cin, nome);
                rota.inserirFim(nome);
                break;
            case 3:
                cout << "Nome da parada: ";
                getline(cin, nome);
                cout << "Posicao (numero): ";
                cin >> posicao;
                cin.ignore();
                rota.inserirPorPosicao(nome, posicao);
                break;
            case 4:
                rota.removerPrimeira();
                break;
            case 5:
                rota.removerUltima();
                break;
            case 6:
                cout << "Termo de busca: ";
                getline(cin, nome);
                rota.buscarPorNome(nome);
                break;
            case 7:
                rota.listarIda();
                break;
            case 8:
                rota.listarInversa();
                break;
            case 9:
                rota.contarParadas();
                break;
            case 0:
                cout << "Encerrando o sistema. Ate logo!\n";
                break;
            default:
                cout << "[ERRO] Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}