#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Livro {
public:
    string nome;
    Livro(string nome) : nome(nome) {}
};

class Usuario {
public:
    string nome, cpf;
    Usuario(string nome, string cpf) : nome(nome), cpf(cpf) {}
};

class Emprestimo {
public:
    static int contador;
    int id;
    Usuario usuario;
    vector<Livro> livros;
    string dataEmprestimo;
    int diasParaDevolucao;

    Emprestimo(Usuario usuario, vector<Livro> livros, string dataEmprestimo, int diasParaDevolucao)
        : usuario(usuario), livros(livros), dataEmprestimo(dataEmprestimo), diasParaDevolucao(diasParaDevolucao) {
        id = ++contador;
    }
};

int Emprestimo::contador = 0;

class Biblioteca {
public:
    string nome, localizacao;
    vector<Livro> livros;
    vector<Usuario> usuarios;
    vector<Emprestimo> emprestimos;

    Biblioteca(string nome, string localizacao) : nome(nome), localizacao(localizacao) {}

    void cadastrarLivro(string nomeLivro) {
        livros.push_back(Livro(nomeLivro));
        cout << "Livro cadastrado com sucesso!\n";
    }

    void cadastrarUsuario(string nome, string cpf) {
        usuarios.push_back(Usuario(nome, cpf));
        cout << "Usuario cadastrado com sucesso!\n";
    }

    void emprestarLivro(string cpf, string nomeLivro, string dataEmprestimo, int dias) {
        auto usuario = find_if(usuarios.begin(), usuarios.end(), [&cpf](Usuario& u) { return u.cpf == cpf; });
        auto livro = find_if(livros.begin(), livros.end(), [&nomeLivro](Livro& l) { return l.nome == nomeLivro; });

        if (usuario != usuarios.end() && livro != livros.end()) {
            vector<Livro> livrosEmprestados = {*livro};
            emprestimos.push_back(Emprestimo(*usuario, livrosEmprestados, dataEmprestimo, dias));
            livros.erase(livro);
            cout << "Emprestimo realizado com sucesso!\n";
        } else {
            cout << "Erro: Usuario ou livro nao encontrado!\n";
        }
    }

    void devolverLivro(int idEmprestimo) {
        auto it = find_if(emprestimos.begin(), emprestimos.end(), [idEmprestimo](Emprestimo& e) { return e.id == idEmprestimo; });
        if (it != emprestimos.end()) {
            livros.insert(livros.end(), it->livros.begin(), it->livros.end());
            emprestimos.erase(it);
            cout << "Livro devolvido com sucesso!\n";
        } else {
            cout << "Emprestimo nao encontrado!\n";
        }
    }
};

int main() {
    Biblioteca biblioteca("Biblioteca Central", "Rua Principal, 123");
    int opcao;

    do {
        cout << "\n1. Cadastrar Livro\n2. Cadastrar Usuario\n3. Emprestar Livro\n4. Devolver Livro\n5. Sair\nEscolha: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            string nomeLivro;
            cout << "Nome do Livro: ";
            getline(cin, nomeLivro);
            biblioteca.cadastrarLivro(nomeLivro);
        } else if (opcao == 2) {
            string nome, cpf;
            cout << "Nome do Usuario: ";
            getline(cin, nome);
            cout << "CPF: ";
            getline(cin, cpf);
            biblioteca.cadastrarUsuario(nome, cpf);
        } else if (opcao == 3) {
            string cpf, nomeLivro, data;
            int dias;
            cout << "CPF do Usuario: ";
            getline(cin, cpf);
            cout << "Nome do Livro: ";
            getline(cin, nomeLivro);
            cout << "Data do Emprestimo: ";
            getline(cin, data);
            cout << "Dias para Devolucao: ";
            cin >> dias;
            biblioteca.emprestarLivro(cpf, nomeLivro, data, dias);
        } else if (opcao == 4) {
            int id;
            cout << "ID do Emprestimo: ";
            cin >> id;
            biblioteca.devolverLivro(id);
        }
    } while (opcao != 5);

    return 0;
}
