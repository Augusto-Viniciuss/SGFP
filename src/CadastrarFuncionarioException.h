#ifndef CADASTRARFUNCIONARIOEXCEPTION_H
#define CADASTRARFUNCIONARIOEXCEPTION_H

#include <exception>

/**
* Exception personalidado usado para detectar e informar os erros
* que podem ocorrer durante o cadastramento de um funcionário
*/

class CadastrarFuncionarioException : public std::exception{
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        CadastrarFuncionarioException(const char* e);
        
        /**
        * what( )
        * 
        * Método para a exibição da mensagem de erro
        */
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif