#ifndef DIRETOR_H
#define DIRETOR_H

#include "funcionario.h"
#include <string>

class Diretor : public Funcionario{
    public:
        Diretor();
        double calcularSalarioMensal();
    private:
        std::string areaSupervisao;
        std::string areaFormacao;
};

#endif
