// Revista.cpp
#include "Revista.h"
#include <iostream>

// Construtor
Revista::Revista(const std::string& titulo, const std::string& autor, int ano_publicacao,
                 const std::string& periodicidade, const std::vector<std::string>& temas)
    : Livro(titulo, autor, ano_publicacao), periodicidade(periodicidade), temas(temas) {}

// Método para exibir informações sobre a revista
void Revista::exibirInformacoes() const {
    // Chama o método da classe base (Livro)
    Livro::exibirInformacoes();
    std::cout << "Periodicidade: " << periodicidade << std::endl;

    std::cout << "Temas abordados: ";
    for (const auto& tema : temas) {
        std::cout << tema << ", ";
    }
    std::cout << std::endl;
}

// Métodos getter
std::string Revista::getPeriodicidade() const {
    return periodicidade;
}

std::vector<std::string> Revista::getTemas() const {
    return temas;
}
