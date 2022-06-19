#include "FuncionarioJaCadastradoExcept.h"
#include <string.h>

FuncionarioJaCadastradoExcept::FuncionarioJaCadastradoExcept(const char* e){
    //Fazendo o uso da função strcpy para passar a mensagem
    //recebida para a variável char mensagem[100]
    strcpy(mensagem, e);
}

const char* FuncionarioJaCadastradoExcept::what(){
    return mensagem;
}