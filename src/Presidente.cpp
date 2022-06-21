#include "Presidente.h"

Presidente::Presidente() {
    Funcionario::setCodigoFuncionario(0);
    /*
        Para facilitar na leitura dos arquivos
        os códigos são inicializados como 0
    */
}

Presidente::Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax) : Funcionario(codigo, nome, CPF, idade, endereco, numeroResidencia, telefone, data, designacao) {
    setAreaFormacao(areaFormacao);
    setFormacaoMax(formacaoMax);
    /*
        As únicas variáveis de Presidente que não são
        herdadas de funcionário são FormacaoMax e
        areaFormacao, que precisar ser inicializadas
        no construtor próprio
    */
}

std::string Presidente::getAreaFormacao() {
    return this->areaFormacao;
}

std::string Presidente::getFormacaoMax() {
    return this->formacaoMax;
}

void Presidente::setAreaFormacao(std::string areaFormacao) {
    /*
        Verifica se areaFormacao tem mais de 99 caracteres.
        Caso tenha, só é lido até areaFormacao[98] e o último
        indice recebe o '\0'
    */
    if(areaFormacao.size() > 99){
        for(int i = 0; i < 98; i++){
            this->areaFormacao[i] = areaFormacao[i];
        }
        this->areaFormacao[99] = '\0';
    }else{
        /*
            Caso tenha menos de 99 caracteres, a string é salva por
            completo no array de char
        */
        for(int i = 0; i < areaFormacao.size(); i++){
            this->areaFormacao[i] = areaFormacao[i];
        }
        this->areaFormacao[areaFormacao.size()] = '\0';
    }
}

void Presidente::setFormacaoMax(std::string formacaoMax) {
    /*
        Verifica se formacaoMax tem mais de 99 caracteres.
        Caso tenha, só é lido até formacaoMax[98] e o último
        indice recebe o '\0'
    */
    if(formacaoMax.size() > 99){
        for(int i = 0; i < 98; i++){
            this->formacaoMax[i] = formacaoMax[i];
        }
        this->formacaoMax[99] = '\0';
    }else{
        /*
            Caso tenha menos de 99 caracteres, a string é salva por
            completo no array de char
        */
        for(int i = 0; i < formacaoMax.size(); i++){
            this->formacaoMax[i] = formacaoMax[i];
        }
        this->formacaoMax[formacaoMax.size()] = '\0';
    }
}

void Presidente::calcularSalarioMensal(int mes) {
      
    if(getHorasTrabalhadas(mes) == 0) {
        
        /* As horas trabalhadas são geradas aleatóriamente até o máximo de 260 horas */
        setHorasTrabalhadas(mes ,gerarAleatorio(260));
    }

    double salarioLiquido;

    /* A partir de 194 horas trabalhadas no mês, é considerado hora extra */
    if (getHorasTrabalhadas(mes) > 194) {
        /* Se trabalhar mais do que 194, o diretor recebe por suas horas extras */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas(mes) - 194) * HORA_EXTRA);
    } else {
        /* Se trabalhar menos do que 194 recebe apenas seu salário base */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
