#include "Operador.h"

Operador::Operador() {
    Funcionario::setCodigoFuncionario(0);
    /*
        Para facilitar na leitura dos arquivos
        os códigos são inicializados como 0
    */
}

/*
    Operador não tem nenhuma variável própria,
    então passa tudo direto pro construtor de funcionario
*/
Operador::Operador(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao) : Funcionario(codigo, nome, CPF, idade, CEP, numeroResidencia, telefone, data, designacao) {}

void Operador::calcularSalarioMensal(int mes){
    
    if(getHorasTrabalhadas(mes) == 0) {
        
        /* As horas trabalhadas são geradas aleatóriamente até o máximo de 260 horas */
        setHorasTrabalhadas(mes ,gerarAleatorio(260));
    }
    
    
    double salarioLiquido;

    /* A partir de 172 horas trabalhadas no mês, é considerado hora extra */
    if (getHorasTrabalhadas(mes) > 172) {
        /* Se trabalhar mais do que 172, o diretor recebe por suas horas extras */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase() + ((getHorasTrabalhadas(mes) - 172) * HORA_EXTRA);
    } else {
        /* Se trabalhar menos do que 172 recebe apenas seu salário base */
        salarioLiquido = getFolhaSalarial(mes)->getSalarioBase();
    }
   
    getFolhaSalarial(mes)->setSalarioLiquido(salarioLiquido);
}
