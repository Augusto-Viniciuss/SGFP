#ifndef CEPEXCEPTION_H
#define CEPEXCEPTION_H

#include <exception>

/**
* Exception personalizado criado para reconhecer e
* informar ao usuário possíveis erros durante o cadastro
* do CEP do funcionário
*/

class CEPException : public std::exception{
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        CEPException(const char* e);
        
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