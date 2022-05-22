#include "Gerente.h"

Gerente::Gerente() {
    /* ... */
}

Gerente::Gerente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaSupervisao) : Funcionario(codigo, nome, CPF, idade, endereco, telefone, data, designacao) {
    setAreaSupervisao(areaSupervisao);
}

std::string Gerente::getAreaSupervisao() {
    return this->areaSupervisao;
}

void Gerente::setAreaSupervisao(std::string areaSupervisao) {
    this->areaSupervisao = areaSupervisao;
}

double Gerente::calcularSalarioMensal(){
   //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    ///setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() + (HORA_EXTRA * getHorasTrabalhadas()); 
}
