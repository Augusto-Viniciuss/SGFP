#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <string>

class Presidente : public Funcionario{
    public:
        Presidente();
        double calcularSalarioMensal();
    private:
        std::string areaFormacao;
        std::string formacaoMax;
};

#endif
