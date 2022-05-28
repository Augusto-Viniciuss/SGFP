#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <string>

class Presidente : public Funcionario {
    public:
        Presidente();
        Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax);
        
        virtual std::string getAreaFormacao();
        virtual std::string getFormacaoMax();

        void setAreaFormacao(std::string areaFormacao);
        void setFormacaoMax(std::string formacaoMax);

        void calcularSalarioMensal(int mes);
    private:
        std::string areaFormacao;
        std::string formacaoMax;
        const double HORA_EXTRA = 97.24;
};

#endif
