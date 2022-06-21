#ifndef CPFEXCEPTION_H
#define CPFEXCEPTION_H

#include <exception>

/**
* Exception personalizado criado para reconhecer e
* informar ao usuário possíveis erros durante o cadastro
* do CPF do funcionário
*/

class CPFException : public std::exception{
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        CPFException(const char* e);
        
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