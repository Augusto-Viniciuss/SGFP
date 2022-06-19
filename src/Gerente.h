#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <string>

class Gerente : public Funcionario{
    public:
        /* Construtor padrão sem argumentos */
        Gerente();
        /* Construtor que recebe os atributos do Gerente */
        Gerente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao);
        
        /* Get */
        std::string getAreaSupervisao();
        
        /* Set */
        void setAreaSupervisao(std::string areaSupervisao);
        
        /* Método sobrescrito para calcular o salario mensal */
        void calcularSalarioMensal(int mes);

    private:
        char areaSupervisao[100];
        const double HORA_EXTRA = 40.16;
};

#endif
