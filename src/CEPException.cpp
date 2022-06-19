#include "CEPException.h"
#include <string.h>

CEPException::CEPException(const char* e){
    /*
        Fazendo o uso da função strcpy para passar a mensagem
        recebida para a variável char mensagem[100]
    */
    strcpy(mensagem, e);
}

const char* CEPException::what(){
    return mensagem;
}