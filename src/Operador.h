#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        Operador();
        double calcularSalarioMensal();
};

#endif
