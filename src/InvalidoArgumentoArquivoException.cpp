#include "InvalidoArgumentoArquivoException.h"
#include <string.h>

InvalidoArgumentoArquivoExcept::InvalidoArgumentoArquivoExcept(const char* e){
    strcpy(mensagem, e);
}

const char* InvalidoArgumentoArquivoExcept::what(){
    return mensagem;
}