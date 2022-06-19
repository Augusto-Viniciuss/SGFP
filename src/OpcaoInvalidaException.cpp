#include "OpcaoInvalidaException.h"
#include <string.h>

OpcaoInvalidaException::OpcaoInvalidaException(const char* e){
    strcpy(mensagem, e);
}

const char* OpcaoInvalidaException::what(){
    return mensagem;
}