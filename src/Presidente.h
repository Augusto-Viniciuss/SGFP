#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <string>

class Presidente : public Funcionario {
    public:
        /* Construtor padrão sem argumentos */
        Presidente();
        /* Construtor que recebe os atributos do Presidente */
        Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax);
        
        /* Get */
        virtual std::string getAreaFormacao();
        virtual std::string getFormacaoMax();

        /* Set */
        void setAreaFormacao(std::string areaFormacao);
        void setFormacaoMax(std::string formacaoMax);

        /* Método sobrescrito para calcular o salario mensal */
        void calcularSalarioMensal(int mes);
    private:
        char areaFormacao[100];
        char formacaoMax[100];
        const double HORA_EXTRA = 97.24; 
};

#endif
