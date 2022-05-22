#ifndef DIRETOR_H
#define DIRETOR_H

#include "Funcionario.h"
#include <string>

class Diretor : public Funcionario{
    public:
        Diretor();
        Diretor(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaSupervisao, std::string areaFormacao);
        
        std::string getAreaSupervisao();
        std::string getAreaFormacao();
        
        void setAreaSupervisao(std::string areaSupervisao);
        void setAreaFormacao(std::string areaFormacao);

        double calcularSalarioMensal();
    private:
        std::string areaSupervisao;
        std::string areaFormacao;
};

#endif
