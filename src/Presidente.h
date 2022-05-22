#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <string>

class Presidente : public Funcionario {
    public:
        Presidente();
        Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax);
        
        std::string getAreaFormacao();
        std::string getFormacaoMax();

        void setAreaFormacao(std::string areaFormacao);
        void setFormacaoMax(std::string formacaoMax);

        double calcularSalarioMensal();
    private:
        std::string areaFormacao;
        std::string formacaoMax;
};

#endif
