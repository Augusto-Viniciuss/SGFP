#ifndef INVALIDOARGUMENTOARQUIVO_H
#define INVALIDOARGUMENTOARQUIVO_H


#include <stdexcept>

// Função exception que invalida a alteração do presidente
class InvalidoArgumento : public std::invalid_argument {

    public:
        InvalidoArgumento()
        :invalid_argument("Nao eh possivel alterar o presidente.\n") {}
};








#endif