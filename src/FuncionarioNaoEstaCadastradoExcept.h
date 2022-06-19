#ifndef FUNCIONARIONAOESTACADASTRADOEXCEPT_H
#define FUNCIONARIONAOESTACADASTRADOEXCEPT_H

#include <exception>

/*
    Exception personalizado criado para reconhecer e
    informar ao usuário na hora de utilizar algum método
    que exija a existência de um funcionário
*/

class FuncionarioNaoEstaCadastradoExcept : public std::exception{
    public:
        FuncionarioNaoEstaCadastradoExcept(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif