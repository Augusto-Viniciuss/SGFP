#include "FuncionarioJaCadastradoExcept.h"
#include <string.h>

FuncionarioJaCadastradoExcept::FuncionarioJaCadastradoExcept(const char* e){
    strcpy(mensagem, e);
}

const char* FuncionarioJaCadastradoExcept::what(){
    return mensagem;
}