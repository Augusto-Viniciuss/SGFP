#ifndef FUNCIONARIOJACADASTRADOEXCEPT_H
#define FUNCIONARIOJACADASTRADOEXCEPT_H

#include <exception>

class FuncionarioJaCadastradoExcept : public std::exception{
    public:
        FuncionarioJaCadastradoExcept(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif