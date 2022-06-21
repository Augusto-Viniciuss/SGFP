#ifndef INVALIDOARGUMENTOARQUIVOEXCEPTION_H
#define INVALIDOARGUMENTOARQUIVOEXCEPTION_H

#include <exception>

/**
* Função exception que invalida a alteração do presidente
*/

class InvalidoArgumentoArquivoExcept : public std::exception {
    public:
        /**
        * Construtor
        * 
        * Inicializa o atributo mensagem[] com a mensagem passada pela chamada do erro.
        * \param char*-e array de char referente a mensagem de erro
        */
        InvalidoArgumentoArquivoExcept(const char* e);

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