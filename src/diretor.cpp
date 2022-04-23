#include "diretor.h"

Diretor::Diretor():Funcionario("Diretor", 0.20){
    /* ... */
}

double Diretor::CalcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    SetHorasTrabalhadas(GerarAleatorio(260));
    SetDiasTrabalhados(GerarAleatorio(20));

    return GetSalario() * GetHorasTrabalhadas();
}