#include "FuncionarioNaoEstaCadastradoExcept.h"
#include <string.h>

FuncionarioNaoEstaCadastradoExcept::FuncionarioNaoEstaCadastradoExcept(const char* e){
    //Fazendo o uso da função strcpy para passar a mensagem
    //recebida para a variável char mensagem[100]
    strcpy(mensagem, e);
}

const char* FuncionarioNaoEstaCadastradoExcept::what(){
    return mensagem;
}