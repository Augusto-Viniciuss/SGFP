#include "CPFException.h"
#include <string.h>

CPFException::CPFException(const char* e){
    //Fazendo o uso da função strcpy para passar a mensagem
    //recebida para a variável char mensagem[100]
    strcpy(mensagem, e);
}

const char* CPFException::what(){
    return mensagem;
}