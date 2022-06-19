#ifndef TELEFONEEXCEPTION_H
#define TELEFONEEXCEPTION_H

#include <exception>

/*
    Exception personalizado criado para reconhecer e
    informar ao usuário na hora de utilizar um código
    que já está em uso
*/

class TelefoneException : public std::exception{
    public:
        /* Construtor que recebe um array de char da mensagem de erro */
        TelefoneException(const char* e);
        /* Método para exibir a mensagem de erro */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif