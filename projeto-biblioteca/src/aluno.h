#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"

class Aluno : public Usuario {
private:
    int matricula;
public:
    Aluno(std::string nome, int matricula);
    int getMatricula() const;
};

#endif
