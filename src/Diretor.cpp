#include "Diretor.h"

Diretor::Diretor(){
    Funcionario::setCodigoFuncionario(0);
}

Diretor::Diretor(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao, std::string areaFormacao) : Funcionario(codigo, nome, CPF, idade, endereco, numeroResidencia, telefone, data, designacao) {
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

void Diretor::setAreaFormacao(std::string areaFormacao) {
    if(areaFormacao.size() > 99){
        for(int i = 0; i < 98; i++){
            this->areaFormacao[i] = areaFormacao[i];
        }
        this->areaFormacao[99] = '\0';
    }else{
        for(int i = 0; i < areaFormacao.size(); i++){
            this->areaFormacao[i] = areaFormacao[i];
        }
        this->areaFormacao[areaFormacao.size()] = '\0';
    }
}

void Diretor::calcularSalarioMensal(int mes){
    
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    if (getHorasTrabalhadas() > 168) {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas() - 168) * HORA_EXTRA);
    } else {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
