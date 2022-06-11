#ifndef CEPEXCEPTION_H
#define CEPEXCEPTION_H

#include <exception>

class CEPException : public std::exception{
    public:
        CEPException(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif