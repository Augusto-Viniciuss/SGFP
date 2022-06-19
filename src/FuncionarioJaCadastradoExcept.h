#ifndef FUNCIONARIOJACADASTRADOEXCEPT_H
#define FUNCIONARIOJACADASTRADOEXCEPT_H

#include <exception>

/*
    Exception personalizado criado para reconhecer e
    informar ao usuário na hora de utilizar um código
    que já está em uso
*/

class FuncionarioJaCadastradoExcept : public std::exception{
    public:
        /* Construtor que recebe um array de char da mensagem de erro */
        FuncionarioJaCadastradoExcept(const char* e);
        /* Método para exibir a mensagem de erro */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif