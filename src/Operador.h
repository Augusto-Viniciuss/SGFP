#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        Operador();
        Operador(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao);
        double calcularSalarioMensal();
};

#endif
