#ifndef OPERADOR_H
#define OPERADOR_H

#include "funcionario.h"

class Operador : public Funcionario{
    public:
        Operador();
        double calcularSalarioMensal();
};

#endif
