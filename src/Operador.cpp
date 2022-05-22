#include "Operador.h"

Operador::Operador() {
    /* ... */
}

Operador::Operador(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao) : Funcionario(codigo, nome, CPF, idade, endereco, telefone, data, designacao) {
    /* ... */
}

double Operador::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    //setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}
