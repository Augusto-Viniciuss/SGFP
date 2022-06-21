#include "Diretor.h"

Diretor::Diretor(){
    Funcionario::setCodigoFuncionario(0);
    /*
        Para facilitar na leitura dos arquivos
        os códigos são inicializados como 0
    */
}

Diretor::Diretor(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao, std::string areaFormacao) : Funcionario(codigo, nome, CPF, idade, endereco, numeroResidencia, telefone, data, designacao) {
    /*
        As únicas variáveis de Diretor que não são
        herdadas de funcionário são areaSupervisao e
        areaFormacao, que precisar ser inicializadas
        no construtor próprio
    */
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

void Diretor::setAreaFormacao(std::string areaFormacao) {
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

void Diretor::calcularSalarioMensal(int mes){
    
    if(getHorasTrabalhadas(mes) == 0) {
        
        /* As horas trabalhadas são geradas aleatóriamente até o máximo de 260 horas */
        setHorasTrabalhadas(mes ,gerarAleatorio(260));
    }
    double salarioLiquido;

    /* A partir de 168 horas trabalhadas no mês, é considerado hora extra */
    if (getHorasTrabalhadas(mes) > 168) {
        /* Se trabalhar mais do que 168, o diretor recebe por suas horas extras */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas(mes) - 168) * HORA_EXTRA);
    } else {
        /* Se trabalhar menos do que 168 recebe apenas seu salário base */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
