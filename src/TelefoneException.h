#ifndef TELEFONEEXCEPTION_H
#define TELEFONEEXCEPTION_H

#include <exception>

/**
* Exception personalizado criado para reconhecer e
* informar ao usuário na hora de utilizar um código
* que já está em uso
*/

class TelefoneException : public std::exception{
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        TelefoneException(const char* e);
        
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