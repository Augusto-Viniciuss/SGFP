#include "Endereco.h"
#include "CEPException.h"

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

void Endereco::validaCEP(std::string CEP){
    if(CEP.size() == 8){
        for(int i = 0; i < 8; i++){
            if(CEP[i] < '0' || CEP[i] > '9'){
                throw CEPException("Caracter inválido digitado");
            }
        }

            /*
                Falta a implementação do download da url
            */
    }else{
        throw CEPException("Quantidade inválida de caracteres");
    }
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

