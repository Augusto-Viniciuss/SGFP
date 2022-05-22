#include "Operador.h"

Operador::Operador():Funcionario(4, 0.05){
    /* ... */
}

double Operador::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    //setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}
