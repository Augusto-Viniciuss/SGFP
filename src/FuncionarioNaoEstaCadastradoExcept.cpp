#include "FuncionarioNaoEstaCadastradoExcept.h"
#include <string.h>

FuncionarioNaoEstaCadastradoExcept::FuncionarioNaoEstaCadastradoExcept(const char* e){
    strcpy(mensagem, e);
}

const char* FuncionarioNaoEstaCadastradoExcept::what(){
    return mensagem;
}