#include "Presidente.h"

Presidente::Presidente() {
    Funcionario::setCodigoFuncionario(0);
}

Presidente::Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax) : Funcionario(codigo, nome, CPF, idade, endereco, numeroResidencia, telefone, data, designacao) {
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

void Presidente::setFormacaoMax(std::string formacaoMax) {
    if(formacaoMax.size() > 99){
        for(int i = 0; i < 98; i++){
            this->formacaoMax[i] = formacaoMax[i];
        }
        this->formacaoMax[99] = '\0';
    }else{
        for(int i = 0; i < formacaoMax.size(); i++){
            this->formacaoMax[i] = formacaoMax[i];
        }
        this->formacaoMax[formacaoMax.size()] = '\0';
    }
}

void Presidente::calcularSalarioMensal(int mes) {
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    if (getHorasTrabalhadas() > 194) {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas() - 194) * HORA_EXTRA);
    } else {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
