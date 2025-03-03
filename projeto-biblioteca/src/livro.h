// Livro.h
#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    int ano_publicacao;

public:
    // Construtor
    Livro(const std::string& titulo, const std::string& autor, int ano_publicacao);

    // Métodos getter
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAnoPublicacao() const;

    // Método para exibir informações sobre o livro
    void exibirInformacoes() const;
};

#endif // LIVRO_H
