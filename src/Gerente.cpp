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
    if(areaSupervisao.size() > 99){
        for(int i = 0; i < 98; i++){
            this->areaSupervisao[i] = areaSupervisao[i];
        }
        this->areaSupervisao[99] = '\0';
    }else{
        for(int i = 0; i < areaSupervisao.size(); i++){
            this->areaSupervisao[i] = areaSupervisao[i];
        }
        this->areaSupervisao[areaSupervisao.size()] = '\0';
    }
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
