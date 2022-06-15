#include "Operador.h"

Operador::Operador() {
    Funcionario::setCodigoFuncionario(0);
}

Operador::Operador(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, std::string telefone, int *data, int designacao) : Funcionario(codigo, nome, CPF, idade, CEP, telefone, data, designacao) {}

void Operador::calcularSalarioMensal(int mes){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    

    double salarioLiquido;

    if (getHorasTrabalhadas() > 172) {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas() - 172) * HORA_EXTRA);
    } else {
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
