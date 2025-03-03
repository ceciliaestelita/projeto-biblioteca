// Revista.h
#ifndef REVISTA_H
#define REVISTA_H

#include "Livro.h"
#include <string>
#include <vector>

class Revista : public Livro {
private:
    std::string periodicidade; // Mensal, semanal, etc.
    std::vector<std::string> temas; // Temas abordados na revista

public:
    // Construtor
    Revista(const std::string& titulo, const std::string& autor, int ano_publicacao,
            const std::string& periodicidade, const std::vector<std::string>& temas);

    // Método para exibir informações sobre a revista
    void exibirInformacoes() const override;

    // Métodos getter
    std::string getPeriodicidade() const;
    std::vector<std::string> getTemas() const;
};

#endif // REVISTA_H
