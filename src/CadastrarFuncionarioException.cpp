#include "CadastrarFuncionarioException.h"
#include <string.h>

CadastrarFuncionarioException::CadastrarFuncionarioException(const char* e){
    strcpy(mensagem, e);
}

const char* CadastrarFuncionarioException::what(){
    return mensagem;
}