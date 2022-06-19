#ifndef CADASTRARFUNCIONARIOEXCEPTION_H
#define CADASTRARFUNCIONARIOEXCEPTION_H

#include <exception>

/*
    Exception personalidado usado para detectar e informar os erros
    que podem ocorrer durante o cadastramento de um funcionário
*/

class CadastrarFuncionarioException : public std::exception{
    public:
        /* Construtor que recebe um array de char da mensagem de erro */
        CadastrarFuncionarioException(const char* e);
        /* Método para exibir a mensagem de erro */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif