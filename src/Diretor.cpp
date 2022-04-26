#include "diretor.h"

Diretor::Diretor():Funcionario("Diretor", 0.20){
    /* ... */
}

double Diretor::calcularSalarioMensal(){
    //editar para cada função ter sua hora mínima
    setHorasTrabalhadas(gerarAleatorio(260));
    setDiasTrabalhados(gerarAleatorio(20));

    return getSalario() * getHorasTrabalhadas();
}
