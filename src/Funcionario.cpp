#include "Funcionario.h"
#include "TelefoneException.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(){
    /* ... */
}

Funcionario::Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao) {
    setCodigoFuncionario(codigo);
    setNomeFuncionario(nome);
    setCPF(CPF);
    setIdade(idade);
    setEndereco(endereco);
    setDataIngresso(data);
    setDesignacao(designacao);
    setTaxaAumento();
}

/* Inicio dos Get */
int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigo(){
    return this->codigoFuncionario;
}

int Funcionario::getIdade(){
    return this->idade;
}

double Funcionario::getSalario(){
    return this->salario;
}

double Funcionario::getTaxaAumento(){
    return this->taxaAumento;
}

Endereco Funcionario::getEndereco(){
    return this->endereco;
}

std::string Funcionario::getTelefone(){
    return this->telefone;
}


std::string Funcionario::getDesignacaoStr(){
    switch(this->designacao){
        case 1:
            return "Operador";
            break;
        case 2:
            return "Gerente";
            break;
        case 3:
            return "Diretor";
            break;
        case 4:
            return "Presidente";
            break;
    }
}

int Funcionario::getDesignacaoInt() {
    return this->designacao;
}

std::string Funcionario::getNomeFuncionario(){
    return this->nomeFuncionario;
}

Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}
/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setSalario(double salario){
    this->salario = salario;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

void Funcionario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Funcionario::setTelefone(std::string telefone){
    if(telefone.size() == 11){
        for(int i = 0; i < 11; i++){
            if(telefone[i] < '0' || telefone[i] > 9){
                throw TelefoneException("Numero invalido digitado");
            }
        }
        int j = 0;
        for(int i = 0; i < 16; i++){
            if(i == 0){
                this->telefone[i] = '(';
                continue;
            }
            if(i == 3){
                this->telefone[i] = ')';
                continue;
            }
            if(i == 9){
                this->telefone[i] = '-';
                continue;
            }
            this->telefone[i] = telefone[j++];
        }
    }else{
        throw TelefoneException("Quantidade insuficiente de caracteres");
    }
}

void Funcionario::setNomeFuncionario(std::string nome){
    this->nomeFuncionario = nome;
}

void Funcionario::setDataIngresso(Data data){
    this->dataIngresso = data;
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

void Funcionario::setTaxaAumento() {
    if(getDesignacaoInt() == 0) {
        this->taxaAumento = 0.05;
    } else if(getDesignacaoInt() == 1) {
        this->taxaAumento = 0.10;
    } else if(getDesignacaoInt() == 2) {
        this->taxaAumento = 0.20;
    } else if(getDesignacaoInt() == 3) {
        this->taxaAumento = 0.30;
    }
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
