#include "TelefoneException.h"
#include <string.h>

TelefoneException::TelefoneException(const char* e){
    strcpy(mensagem, e);
}

const char* TelefoneException::what(){
    return mensagem;
}