#include "Diretor.h"

Diretor::Diretor(){
    /* ... */
}

Diretor::Diretor(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaSupervisao, std::string areaFormacao) : Funcionario(codigo, nome, CPF, idade, endereco, telefone, data, designacao) {
    setAreaSupervisao(areaSupervisao);
    setAreaFormacao(areaFormacao);
}

std::string Diretor::getAreaSupervisao() {
    return this->areaSupervisao;
}

std::string Diretor::getAreaFormacao() {
    return this->areaFormacao;
}

void Diretor::setAreaSupervisao(std::string areaSupervisao) {
    this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaFormacao(std::string areaFormacao) {
    this->areaFormacao = areaFormacao;
}

double Diretor::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    //setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}
