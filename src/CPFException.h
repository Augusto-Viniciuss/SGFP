#ifndef CPFEXCEPTION_H
#define CPFEXCEPTION_H

#include <exception>

class CPFException : public std::exception{
    public:
        CPFException(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif