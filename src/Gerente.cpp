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

void Gerente::calcularSalarioMensal(int mes){
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    if (getHorasTrabalhadas() > 172) {
        salarioLiquido = getFolhaSalarial(mes).getSalarioBase() + ((getHorasTrabalhadas() - 172) * HORA_EXTRA);
    } else {
        salarioLiquido = getFolhaSalarial(mes).getSalarioBase();
    }
   
    getFolhaSalarial(mes).setSalarioLiquido(salarioLiquido);
}
