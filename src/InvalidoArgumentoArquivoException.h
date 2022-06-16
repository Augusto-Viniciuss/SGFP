#ifndef INVALIDOARGUMENTOARQUIVO_H
#define INVALIDOARGUMENTOARQUIVO_H


#include <stdexcept>

// Função exception que invalida a alteração do presidente
class InvalidoArgumentoArquivoExcept : public std::invalid_argument {

    public:
        InvalidoArgumentoArquivoExcept()
        :invalid_argument("Nao eh possivel alterar o presidente.\n") {}
};








#endif