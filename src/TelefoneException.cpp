#include "TelefoneException.h"
#include <string.h>

TelefoneException::TelefoneException(const char* e){
     //Fazendo o uso da função strcpy para passar a mensagem
    //recebida para a variável char mensagem[100]
    strcpy(mensagem, e);
}

const char* TelefoneException::what(){
    return mensagem;
}