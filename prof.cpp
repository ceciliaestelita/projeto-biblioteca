#include "Professor.h"

Professor::Professor(std::string nome, std::string disciplina) : Usuario(nome), disciplina(disciplina) {}

std::string Professor::getDisciplina() const {
    return disciplina;
}
