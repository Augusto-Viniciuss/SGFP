#ifndef CEPEXCEPTION_H
#define CEPEXCEPTION_H

#include <exception>

/*
    Exception personalizado criado para reconhecer e
    informar ao usuário possíveis erros durante o cadastro
    do CEP do funcionário
*/

class CEPException : public std::exception{
    public:
        /* Construtor que recebe um array de char da mensagem de erro */
        CEPException(const char* e);
        /* Método para exibir a mensagem de erro */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif