#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "endereco.h"
#include <string>
//#include "Empresa.h"
//#include "Data.h"

class Funcionario /*: public Empresa */{
    public:
        Funcionario(std::string designacao, double taxa);
        virtual double calcularSalarioMensal()=0;

        /* Get */
        int getHorasTrabalhadas();
        int getDiasTrabalhados();
        int getCodigo();
        int getIdade();
        double getSalario();
        double getTaxaAumento();
        Endereco getEndereco();
        std::string getTelefone();
        std::string getDesignacao();

        /* Set */
        void setHorasTrabalhadas(int horas);
        void setDiasTrabalhados(int dias);

    private:
        int horasTrabalhadas;
        ///int diasTrabalhados;
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
        int gerarAleatorio(int intervaloMax);
        const double HORA_EXTRA = 5.51;
};

#endif