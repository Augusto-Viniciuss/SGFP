#include "Presidente.h"

Presidente::Presidente() {
    /* ... */
}

Presidente::Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax) : Funcionario(codigo, nome, CPF, idade, endereco, telefone, data, designacao) {
    setAreaFormacao(areaFormacao);
    setFormacaoMax(formacaoMax);
    
}

std::string Presidente::getAreaFormacao() {
    return this->areaFormacao;
}

std::string Presidente::getFormacaoMax() {
    return this->formacaoMax;
}

void Presidente::setAreaFormacao(std::string areaFormacao) {
    this->areaFormacao = areaFormacao;
}

void Presidente::setFormacaoMax(std::string formacaoMax) {
    this->formacaoMax = formacaoMax;
}

void Presidente::calcularSalarioMensal(int mes) {
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    if (getHorasTrabalhadas() > 194) {
        salarioLiquido = getFolhaSalarial(mes).getSalarioBase() + ((getHorasTrabalhadas() - 194) * HORA_EXTRA);
    } else {
        salarioLiquido = getFolhaSalarial(mes).getSalarioBase();
    }
   
    getFolhaSalarial(mes).setSalarioLiquido(salarioLiquido);
}
