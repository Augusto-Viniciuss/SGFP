#include "funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(std::string designacao, double taxa){
    this->designacao = designacao;
    this->taxaAumento = taxa;
}

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

void Funcionario::SetHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::SetDiasTrabalhados(int dias){
    diasTrabalhados = dias;
}

int Funcionario::GerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}