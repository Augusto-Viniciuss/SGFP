#include "Funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario() {
    setCodigoFuncionario(0);
    
}

Funcionario::Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao) : Pessoa(nome, telefone, CPF, idade, CEP, numeroResidencia) {
    
    setCodigoFuncionario(codigo);
    setDataIngresso(data);
    setDesignacao(designacao);

    for(int i = 0; i < 12; i++) {
        this->folhaSalarial[i] = FolhaSalarial(designacao);
    }
    
}

Funcionario::~Funcionario() {}

/* Inicio dos Get */
int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigoFuncionario(){
    return this->codigoFuncionario;
}

std::string Funcionario::getDesignacaoStr() {
    switch(getDesignacaoInt()){
        case 0:
            return "Operador";
            break;
        case 1:
            return "Gerente";
            break;
        case 2:
            return "Diretor";
            break;
        case 3:
            return "Presidente";
            break;
    }

    return nullptr;
}

int Funcionario::getDesignacaoInt() {
    return this->designacao;
}
 
Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}

FolhaSalarial* Funcionario::getFolhaSalarial(int mes) {
    return &this->folhaSalarial[mes - 1];
}

/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

void Funcionario::setDataIngresso(int *data){
    this->dataIngresso = Data(data[0], data[1], data[2]);
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
