#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "endereco.h"
#include <string>
#include "Data.h"

class Funcionario{
    public:
        /* CONSTRUTOR */
        Funcionario(std::string designacao, double taxa);
        
        /* ESPECIFICAÇÕES */
        virtual double calcularSalarioMensal() = 0;

        /* Get */
        int getHorasTrabalhadas();
        int getCodigo();
        int getIdade();
        double getSalario();
        double getTaxaAumento();
        Endereco getEndereco();
        std::string getNomeFuncionario();
        std::string getTelefone();
        std::string getDesignacao();
        Data getDataIngresso();

        /* Set */
        void setHorasTrabalhadas(int horas);
        void setSalario(double salario);
        void setDesignacao(std::string designacao);
        void setEndereco(Endereco endereco);
        void setTelefone(std::string telefone);
        void setNomeFuncionario(std::string nome);
        void setDataIngresso(Data data);
        void setCodigoFuncionario(int codigo);

    private:
        int horasTrabalhadas;
        int codigoFuncionario;
        int idade;
        double salario;
        double taxaAumento;
        std::string nomeFuncionario;
        std::string CPF;
        Endereco endereco;
        std::string telefone;
        std::string designacao;
        Data dataIngresso;

    protected:
        int gerarAleatorio(int intervaloMax);
        const double HORA_EXTRA = 5.51;
};

#endif
