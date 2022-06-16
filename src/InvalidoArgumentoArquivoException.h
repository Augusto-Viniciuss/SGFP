#ifndef INVALIDOARGUMENTOARQUIVOEXCEPTION_H
#define INVALIDOARGUMENTOARQUIVOEXCEPTION_H

#include <exception>

// Função exception que invalida a alteração do presidente
class InvalidoArgumentoArquivoExcept : public std::exception {
    public:
        InvalidoArgumentoArquivoExcept(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif