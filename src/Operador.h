#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        /* Construtor padrão sem argumentos */
        Operador();
        /* Construtor que recebe os atributos do Operador */
        Operador(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao);
        
        /* Método sobrescrito para calcular o salario mensal */
        void calcularSalarioMensal(int mes);
    
    private:
        const double HORA_EXTRA = 14.10;
};

#endif
