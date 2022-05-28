#include "Endereco.h"

Endereco::Endereco(){

}

void Endereco::setEndereco(std::string numero, std::string complemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP){
    this->numero = numero;
    this->complemento = complemento;
    this->rua = rua;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->CEP = CEP;
}

std::string Endereco::getNumero(){
    return numero;
}

std::string Endereco::getComplemento(){
    return complemento;
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
    std::cout << getRua() << ", " << getNumero() << ", " << getComplemento() << ", " << getBairro() << ", " << getCidade() << ", " << getEstado() << ", " << getCEP() << std::endl;
}

bool Endereco::comparaEndereco(std::string endereco) {
    if (endereco.find(getCEP()) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

