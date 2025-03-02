#include <iostream>
#include <string>
#include "biblioteca.hpp" // Inclui as classes da biblioteca

using namespace std;

int main() {
    Biblioteca biblioteca("Biblioteca Central", "Rua da UFPE, 123");
    
    int opcao;
    string nome, cpf, tituloLivro;
    
    do {
        cout << "\n===== SISTEMA DA BIBLIOTECA =====\n";
        cout << "1. Cadastrar usuario\n";
        cout << "2. Buscar livro\n";
        cout << "3. Realizar emprestimo\n";
        cout << "4. Devolver livro\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpa o buffer do teclado
        
        switch (opcao) {
            case 1: // Cadastrar usuário
                cout << "Nome: ";
                getline(cin, nome);
                cout << "CPF: ";
                getline(cin, cpf);
                biblioteca.cadastrarUsuario(Usuario(nome, cpf));
                cout << "Usuario cadastrado com sucesso!\n";
                break;

            case 2: // Buscar livro
                cout << "Digite o titulo do livro: ";
                getline(cin, tituloLivro);
                if (biblioteca.buscarLivro(tituloLivro)) {
                    cout << "Livro encontrado!\n";
                } else {
                    cout << "Livro nao encontrado.\n";
                }
                break;

            case 3: // Realizar empréstimo
                cout << "Nome do usuario: ";
                getline(cin, nome);
                cout << "Titulo do livro: ";
                getline(cin, tituloLivro);
                biblioteca.realizarEmprestimo(nome, tituloLivro);
                break;

            case 4: // Devolver livro
                cout << "Nome do usuario: ";
                getline(cin, nome);
                cout << "Titulo do livro: ";
                getline(cin, tituloLivro);
                biblioteca.devolverLivro(nome, tituloLivro);
                break;

            case 5:
                cout << "Saindo do sistema...\n";
                break;

            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
