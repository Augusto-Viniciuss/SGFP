#include "CadastrarFuncionarioException.h"
#include <string.h>

CadastrarFuncionarioException::CadastrarFuncionarioException(const char* e){
    /*
        Fazendo o uso da função strcpy para passar a mensagem
        recebida para a variável char mensagem[100]
    */
    strcpy(mensagem, e);
}

const char* CadastrarFuncionarioException::what(){
    return mensagem;
}