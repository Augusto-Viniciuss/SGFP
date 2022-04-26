#include "Endereco.h"

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

bool Endereco::validaCEP(std::string CEP, std::string rua){
    /*
    Ainda vou implementar, mas a ideia é:
    True -> CEP condiz com a rua
    False -> CEP não condiz com a rua
    */
}

void Endereco::exibeEndereco() {
    std::cout << getRua() << ", " << getNumeroEComplemento() << ", " << getBairro() << ", " << getCidade() << ", " << getEstado() << ", " << getCEP() << std::endl;
}

