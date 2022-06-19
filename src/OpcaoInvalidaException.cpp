#include "OpcaoInvalidaException.h"
#include <string.h>

OpcaoInvalidaException::OpcaoInvalidaException(const char* e){
     //Fazendo o uso da função strcpy para passar a mensagem
    //recebida para a variável char mensagem[100]
    strcpy(mensagem, e);
}

const char* OpcaoInvalidaException::what(){
    return mensagem;
}