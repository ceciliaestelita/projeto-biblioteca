#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"

class Professor : public Usuario {
private:
    std::string disciplina;
public:
    Professor(std::string nome, std::string disciplina);
    std::string getDisciplina() const;
};

#endif
