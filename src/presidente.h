#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "funcionario.h"
#include <string>

class Presidente : public Funcionario{
    public:
        Presidente();
        double CalcularSalarioMensal();
    private:
        std::string areaFormacao;
        std::string formacaoMax;
};

#endif