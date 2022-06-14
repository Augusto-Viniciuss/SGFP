#include "FolhaSalarial.h"

FolhaSalarial::FolhaSalarial() {}

FolhaSalarial::FolhaSalarial(int designacao){
    setSalarioBase(designacao);
    setTaxaAumento(designacao);
    setSalarioLiquido(0);
}

FolhaSalarial::~FolhaSalarial() {}

void FolhaSalarial::setTaxaAumento(int designacao) {
    if(designacao == 0) {
        this->taxaAumento = 0.05;
    } else if(designacao == 1) {
        this->taxaAumento = 0.10;
    } else if(designacao == 2) {
        this->taxaAumento = 0.20;
    } else if(designacao == 3) {
        this->taxaAumento = 0.30;
    }
}

void FolhaSalarial::setSalarioBase(int designacao){
    if(designacao == 0) {
        this->salarioBase = 1212;
    } else if(designacao == 1) {
        this->salarioBase = 3454;
    } else if(designacao == 2) {
        this->salarioBase = 6256;
    } else if(designacao == 3) {
        this->salarioBase = 9432;
    }
}

void FolhaSalarial::setSalarioLiquido(double salario) {
    double  aux;

    aux = salario;
    
    if (aux <= 1212.00) {
        aux -= aux * 0.075;
    } else if (aux >= 1212.01 and aux <= 2427.35) {
        aux -= aux * 0.09;
    } else if (aux >= 2427.36 and aux <= 3641.03) {
        aux -= aux * 0.12;
    } else if (aux >= 3641.04 and aux <= 7087.22) {
        aux -= aux * 0.14;
    }

    setDescontoPrevidencia(salario - aux);

    aux = salario;

    if (aux >= 1903.99 and aux <= 2826.65) {
        aux -= aux * 0.075;
    } else if (aux >= 2826.66 and aux <= 3751.05) {
        aux -= aux * 0.15;
    } else if (aux >= 3751.06 and aux <= 4664.68) {
        aux -= aux * 0.2250;
    } else if (aux > 4664.68) {
        aux -= aux * 0.2750;
    }

    setDescontoImpostoRenda(aux - salario);

    this->salarioLiquido = salario - (getDescontoImpostoRenda() + getDescontoPrevidencia());
}

void FolhaSalarial::setDescontoImpostoRenda(double desconto) {
    this->descontoImpostoRenda = desconto;
}

void FolhaSalarial::setDescontoPrevidencia(double desconto) {
    this->descontoPrevidencia = desconto;
}

double FolhaSalarial::getTaxaAumento() {
    return this->taxaAumento;
}

double FolhaSalarial::getSalarioBase(){
    return this->salarioBase;
}

double FolhaSalarial::getSalarioLiquido(){
    return this->salarioLiquido;
}

double FolhaSalarial::getDescontoImpostoRenda() {
    return this->descontoImpostoRenda;
}

double FolhaSalarial::getDescontoPrevidencia() {
    return this->descontoPrevidencia;
}

void FolhaSalarial::aumentarSalarioBase() {
    this->salarioBase += getSalarioBase() * getTaxaAumento();
}