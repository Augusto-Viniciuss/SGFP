#include "operador.h"

Operador::Operador():Funcionario("Operador", 0.05){
    /* ... */
}

double Operador::CalcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    SetHorasTrabalhadas(GerarAleatorio(260));
    SetDiasTrabalhados(GerarAleatorio(20));

    return GetSalario() * GetHorasTrabalhadas();
}