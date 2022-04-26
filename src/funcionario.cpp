#include "funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(std::string designacao, double taxa)/*:Empresa(nome, CNPJ, data)*/{
    this->designacao = designacao;
    this->taxaAumento = taxa;
}

/* Inicio dos Get */
int Funcionario::GetHorasTrabalhadas(){
    return horasTrabalhadas;
}

int Funcionario::GetDiasTrabalhados(){
    return diasTrabalhados;
}

int Funcionario::GetCodigo(){
    return codigoFuncionario;
}

int Funcionario::GetIdade(){
    return idade;
}

double Funcionario::GetSalario(){
    return salario;
}

double Funcionario::GetTaxaAumento(){
    return taxaAumento;
}

Endereco Funcionario::GetEndereco(){
    return endereco;
}

std::string Funcionario::GetTelefone(){
    return telefone;
}

std::string Funcionario::GetDesignacao(){
    return designacao;
}

std::string Funcionario::GetNomeFuncionario(){
    return nomeFuncionario;
}

Data Funcionario::GetDataIngresso(){
    return dataIngresso;
}

/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::SetHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::SetDiasTrabalhados(int dias){
    diasTrabalhados = dias;
}

void Funcionario::SetSalario(double salario){
    this->salario = salario;
}

void Funcionario::SetDesignacao(std::string designacao){
    this->designacao = designacao;
}

void Funcionario::SetEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Funcionario::SetTelefone(std::string telefone){
    this->telefone = telefone;
}

void Funcionario::SetNomeFuncionario(std::string nome){
    this->nomeFuncionario = nome;
}

void Funcionario::SetDataIngresso(Data data){
    this->dataIngresso = data;
}

void Funcionario::SetCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

/* Fim dos Set */

int Funcionario::GerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}