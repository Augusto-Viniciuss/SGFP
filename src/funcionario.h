#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "endereco.h"
#include <string>
//#include "Empresa.h"
//#include "Data.h"

class Funcionario /*: public Empresa */{
    public:
        Funcionario(std::string designacao, double taxa);
        virtual double CalcularSalarioMensal()=0;

        /* Get */
        int GetHorasTrabalhadas();
        int GetDiasTrabalhados();
        int GetCodigo();
        int GetIdade();
        double GetSalario();
        double GetTaxaAumento();
        Endereco GetEndereco();
        std::string GetTelefone();
        std::string GetDesignacao();

        /* Set */
        void SetHorasTrabalhadas(int horas);
        void SetDiasTrabalhados(int dias);

    private:
        int horasTrabalhadas;
        int diasTrabalhados;
        int codigoFuncionario;
        int idade;
        double salario;
        double taxaAumento;
        std::string nome;
        std::string CPF;
        Endereco endereco;
        std::string telefone;
        std::string designacao;
        //Data dataIngresso;

    protected:
        int GerarAleatorio(int intervaloMax);
};

#endif