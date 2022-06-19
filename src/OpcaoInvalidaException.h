#ifndef OPCAOINVALIDAEXCEPTION_H
#define OPCAOINVALIDAEXCEPTION_H

#include <exception>

/*
    Exception personalizado criado para reconhecer e
    informar ao usuário caso haja uma digitação incorreta
    ou uma opção inválida
*/

class OpcaoInvalidaException : public std::exception{
    public:
        /* Construtor que recebe um array de char da mensagem de erro */
        OpcaoInvalidaException(const char* e);
        /* Método para exibir a mensagem de erro */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif