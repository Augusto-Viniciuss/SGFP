#include "Operador.h"

Operador::Operador() {
    /* ... */
}

Operador::Operador(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao) : Funcionario(codigo, nome, CPF, idade, endereco, telefone, data, designacao) {
    setSalarioBase(1212);
}

void Operador::calcularSalarioMensal(int mes){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));

    double salarioLiquido;

    if (getHorasTrabalhadas() > 172) {
        salarioLiquido = getSalarioLiquido() + ((getHorasTrabalhadas() - 172) * HORA_EXTRA);
    } else {
        salarioLiquido = getSalarioLiquido();
    }
   
    this->folhaSalarial[mes - 1] = salarioLiquido;
}
