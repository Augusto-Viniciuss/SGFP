#include "Gerente.h"

Gerente::Gerente() {
    Funcionario::setCodigoFuncionario(0);
    /*
        Para facilitar na leitura dos arquivos
        os códigos são inicializados como 0
    */
}

Gerente::Gerente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao) : Funcionario(codigo, nome, CPF, idade, endereco, numeroResidencia, telefone, data, designacao) {
    setAreaSupervisao(areaSupervisao);
    /*
        A única variável de Gerente que não é
        herdada de funcionário é areaSupervisao,
        que precisar ser inicializada
        no construtor próprio
    */
} 

std::string Gerente::getAreaSupervisao() {
    return this->areaSupervisao;
}

void Gerente::setAreaSupervisao(std::string areaSupervisao) {
    /*
        Verifica se areaSupervisao tem mais de 99 caracteres.
        Caso tenha, só é lido até areaSupervisao[98] e o último
        indice recebe o '\0'
    */
    if(areaSupervisao.size() > 99){
        for(int i = 0; i < 98; i++){
            this->areaSupervisao[i] = areaSupervisao[i];
        }
        this->areaSupervisao[99] = '\0';
    }else{
        /*
            Caso tenha menos de 99 caracteres, a string é salva por
            completo no array de char
        */
        for(int i = 0; i < areaSupervisao.size(); i++){
            this->areaSupervisao[i] = areaSupervisao[i];
        }
        this->areaSupervisao[areaSupervisao.size()] = '\0';
    }
}


void Gerente::calcularSalarioMensal(int mes){
    /* As horas trabalhadas são geradas aleatóriamente até o máximo de 260 horas */
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    /* A partir de 172 horas trabalhadas no mês, é considerado hora extra */
    if (getHorasTrabalhadas() > 172) {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas() - 172) * HORA_EXTRA);
    } else {
        /* Se trabalhar menos do que 172 recebe apenas seu salário base */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
