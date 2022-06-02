#include "CEPException.h"
#include <string.h>

CEPException::CEPException(const char* e){
    strcpy(mensagem, e);
}

const char* CEPException::what(){
    return mensagem;
}