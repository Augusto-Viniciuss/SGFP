#include "Funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(std::string designacao, double taxa)/*:Empresa(nome, CNPJ, data)*/{
    this->designacao = designacao;
    this->taxaAumento = taxa;
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

std::string Funcionario::getDesignacao(){
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

void Funcionario::setDesignacao(std::string designacao){
    this->designacao = designacao;
}

void Funcionario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Funcionario::setTelefone(std::string telefone){
    this->telefone = telefone;
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

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
