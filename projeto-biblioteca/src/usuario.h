#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
public:
    Usuario(std::string nome);
    std::string getNome() const;
};

#endif
