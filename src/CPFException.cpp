#include "CPFException.h"
#include <string.h>

CPFException::CPFException(const char* e){
    strcpy(mensagem, e);
}

const char* CPFException::what(){
    return mensagem;
}