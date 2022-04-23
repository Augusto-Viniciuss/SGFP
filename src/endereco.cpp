#include "endereco.h"

Endereco::Endereco(){

}

void Endereco::SetEndereco(std::string numeroEComplemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP){
    this->numeroEComplemento = numeroEComplemento;
    this->rua = rua;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->CEP = CEP;
}

std::string Endereco::GetNumeroEComplemento(){
    return numeroEComplemento;
}
        
std::string Endereco::GetRua(){
    return rua;
}

std::string Endereco::GetBairro(){
    return bairro;
}

std::string Endereco::GetCidade(){
    return cidade;
}

std::string Endereco::GetEstado(){
    return estado;
}

std::string Endereco::GetCEP(){
    return CEP;
}