#include "presidente.h"

Presidente::Presidente():Funcionario("Presidente", 0.30){
    /* ... */
}

double Presidente::CalcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    SetHorasTrabalhadas(GerarAleatorio(260));
    SetDiasTrabalhados(GerarAleatorio(20));

    return GetSalario() * GetHorasTrabalhadas();
}