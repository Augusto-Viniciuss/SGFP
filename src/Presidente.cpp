#include "Presidente.h"

Presidente::Presidente():Funcionario(1, 0.30){
    /* ... */
}

double Presidente::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    //setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}
