#ifndef FUNCIONARIONAOESTACADASTRADOEXCEPT_H
#define FUNCIONARIONAOESTACADASTRADOEXCEPT_H

#include <exception>

class FuncionarioNaoEstaCadastradoExcept : public std::exception{
    public:
        FuncionarioNaoEstaCadastradoExcept(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif