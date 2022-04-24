#ifndef GERENTE_H
#define GERENTE_H

#include "funcionario.h"
#include <string>

class Gerente : public Funcionario{
    public:
        Gerente();
        double CalcularSalarioMensal();
    private:
        std::string areaSupervisao;
};

#endif