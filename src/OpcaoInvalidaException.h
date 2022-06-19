#ifndef OPCAOINVALIDAEXCEPTION_H
#define OPCAOINVALIDAEXCEPTION_H

#include <exception>

class OpcaoInvalidaException : public std::exception{
    public:
        OpcaoInvalidaException(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif