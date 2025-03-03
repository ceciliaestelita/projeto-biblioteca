#include <iostream>
#include "Usuario.h"
#include "Aluno.h"
#include "Professor.h"
#include "Livro.h"
#include "Revista.h"

int main() {
    // Exemplo de uso das classes
    Aluno aluno("Cecilia", 12345678);
    Professor prof("Guilherme", "Eletronica");

    std::cout << "Aluno: " << aluno.getNome() << ", Matricula: " << aluno.getMatricula() << std::endl;
    std::cout << "Professor: " << prof.getNome() << ", Disciplina: " << prof.getDisciplina() << std::endl;

    return 0;
}
