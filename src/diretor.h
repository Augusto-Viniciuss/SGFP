#ifndef DIRETOR_H
#define DIRETOR_H

#include "funcionario.h"
#include <string>

class Diretor : public Funcionario{
    public:
        Diretor();
        double CalcularSalarioMensal();
    private:
        std::string areaSupervisao;
        std::string areaFormacao;
};

#endif