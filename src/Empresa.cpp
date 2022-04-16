#include "Empresa.h"

Empresa::Empresa(std::string nome, std::string CNPJ, Data data) {
    this->nome = nome;
    this->CNPJ = CNPJ;
    this->dataFundacao = data;
    this->qtdFuncionarios = 0;
    this->folhaSalarial = {-1, -1};
}

void Empresa::setNome(std::string nome) {
    this->nome = nome;
}

void Empresa::setCNPJ(std::string CNPJ) {
    this->CNPJ = CNPJ;
}

void Empresa::setDataFundacao(Data data) {
    this->dataFundacao = data;
}

std::string Empresa::getNome() {
    return this->nome;
}

std::string Empresa::getCNPJ() {
    return this->CNPJ;
}

Data Empresa::getDataFundacao() {
    return this->dataFundacao;
}

int Empresa::getQtdFuncionarios() {
    return this->qtdFuncionarios;
}

void addFuncionario(Funcionario funcionario) {
    
}