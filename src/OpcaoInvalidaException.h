#ifndef OPCAOINVALIDAEXCEPTION_H
#define OPCAOINVALIDAEXCEPTION_H

#include <exception>

/**
* Exception personalizado criado para reconhecer e
* informar ao usuário caso haja uma digitação incorreta
* ou uma opção inválida
*/

class OpcaoInvalidaException : public std::exception{
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        OpcaoInvalidaException(const char* e);
        
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