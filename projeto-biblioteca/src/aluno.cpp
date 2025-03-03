#include "Aluno.h"

Aluno::Aluno(std::string nome, int matricula) : Usuario(nome), matricula(matricula) {}

int Aluno::getMatricula() const {
    return matricula;
}
