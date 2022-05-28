#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <string>

class Gerente : public Funcionario{
    public:
        Gerente();
        Gerente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaSupervisao);
        
        std::string getAreaSupervisao();
        
        void setAreaSupervisao(std::string areaSupervisao);
        
        void calcularSalarioMensal(int mes);

    private:
        std::string areaSupervisao;
        const double HORA_EXTRA = 40.16;
};

#endif
