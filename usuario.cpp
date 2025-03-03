#include "Usuario.h"

Usuario::Usuario(std::string nome) : nome(nome) {}

std::string Usuario::getNome() const {
    return nome;
}
