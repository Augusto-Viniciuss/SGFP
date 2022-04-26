#include "funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(std::string designacao, double taxa){
    this->designacao = designacao;
    this->taxaAumento = taxa;
}

int Funcionario::getHorasTrabalhadas(){
    return horasTrabalhadas;
}

int Funcionario::getDiasTrabalhados(){
    return diasTrabalhados;
}

int Funcionario::getCodigo(){
    return codigoFuncionario;
}

int Funcionario::getIdade(){
    return idade;
}

double Funcionario::getSalario(){
    return salario;
}

double Funcionario::getTaxaAumento(){
    return taxaAumento;
}

Endereco Funcionario::getEndereco(){
    return endereco;
}

std::string Funcionario::getTelefone(){
    return telefone;
}

std::string Funcionario::getDesignacao(){
    return designacao;
}

void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setDiasTrabalhados(int dias){
    diasTrabalhados = dias;
}

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}