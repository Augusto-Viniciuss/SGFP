#include "gerente.h"

Gerente::Gerente():Funcionario("Gerente", 0.10){
    /* ... */
}

double Gerente::CalcularSalarioMensal(){
   //editar para cada função ter sua hora mínima
    SetHorasTrabalhadas(GerarAleatorio(260));
    SetDiasTrabalhados(GerarAleatorio(20));

    return GetSalario() * GetHorasTrabalhadas(); 
}