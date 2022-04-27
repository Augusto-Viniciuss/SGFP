#include "Gerente.h"

Gerente::Gerente():Funcionario("Gerente", 0.10){
    /* ... */
}

double Gerente::calcularSalarioMensal(){
   //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    ///setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() + (HORA_EXTRA * getHorasTrabalhadas()); 
}
