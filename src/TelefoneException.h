#ifndef TELEFONEEXCEPTION_H
#define TELEFONEEXCEPTION_H

#include <exception>

class TelefoneException : public std::exception{
    public:
        TelefoneException(const char* e);
        virtual const char* what();
    protected:
        char mensagem[100];
};

#endif