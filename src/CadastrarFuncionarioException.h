#ifndef CADASTRARFUNCIONARIOEXCEPTION_H
#define CADASTRARFUNCIONARIOEXCEPTION_H

#include <exception>

class CadastrarFuncionarioException : public std::exception{
    public:
        CadastrarFuncionarioException(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif