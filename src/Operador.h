#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        Operador();
        Operador(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao);
        
        void calcularSalarioMensal(int mes);
    
    private:
        const double HORA_EXTRA = 14.10;
};

#endif
