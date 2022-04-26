#include "operador.h"

Operador::Operador():Funcionario("Operador", 0.05){
    /* ... */
}

double Operador::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}