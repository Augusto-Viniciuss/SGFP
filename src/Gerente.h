#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <string>

class Gerente : public Funcionario{
    public:
        Gerente();
        double calcularSalarioMensal();
    private:
        std::string areaSupervisao;
};

#endif
