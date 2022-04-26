#include "endereco.h"

Endereco::Endereco(){

}

void Endereco::setEndereco(std::string numeroEComplemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP){
    this->numeroEComplemento = numeroEComplemento;
    this->rua = rua;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->CEP = CEP;
}

std::string Endereco::getNumeroEComplemento(){
    return numeroEComplemento;
}
        
std::string Endereco::getRua(){
    return rua;
}

std::string Endereco::getBairro(){
    return bairro;
}

std::string Endereco::getCidade(){
    return cidade;
}

std::string Endereco::getEstado(){
    return estado;
}

std::string Endereco::getCEP(){
    return CEP;
}