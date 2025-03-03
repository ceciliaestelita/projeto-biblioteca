// Livro.cpp
#include "Livro.h"
#include <iostream>

// Construtor
Livro::Livro(const std::string& titulo, const std::string& autor, int ano_publicacao)
    : titulo(titulo), autor(autor), ano_publicacao(ano_publicacao) {}

// Métodos getter
std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

int Livro::getAnoPublicacao() const {
    return ano_publicacao;
}

// Método para exibir informações sobre o livro
void Livro::exibirInformacoes() const {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Ano de publicacao: " << ano_publicacao << std::endl;
}
