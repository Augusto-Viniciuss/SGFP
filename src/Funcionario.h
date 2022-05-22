#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Endereco.h"
#include <string>
#include "Data.h"

class Funcionario {
    public:
        /* CONSTRUTOR */
        Funcionario();
        Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao);

        /* DESTRUTOR */
        virtual ~Funcionario();
        
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
        std::string getDesignacaoStr();
        int getDesignacaoInt();
        Data getDataIngresso();

        /* Set */
        void setHorasTrabalhadas(int horas);
        void setSalario(double salario);
        void setDesignacao(int designacao);
        void setEndereco(Endereco endereco);
        void setEndereco(std::string endereco); //numero,complemento,rua,bairro,cidade,estado,CEP
        void setTelefone(std::string telefone);
        void setNomeFuncionario(std::string nome);
        void setDataIngresso(Data data);
        void setDataIngresso(std::string data);
        void setCodigoFuncionario(int codigo);
        void setTaxaAumento();

    private:
        int horasTrabalhadas;
        int codigoFuncionario;
        int idade;
        int designacao; /*1 = Presidente; 2 = Diretor; 3 = Gerente; 4 = Operador*/
        double salario;
        double taxaAumento;
        char nomeFuncionario[100];
        char CPF[15]; /*Enviar como XXXXXXXXXXX e será armazenado como XXX.XXX.XXX-XX */
        Endereco endereco;
        char telefone[15]; /*Enviar como XXXXXXXXXXX e será armazenado como (XX)XXXXX-XXXX */
        Data dataIngresso;

    protected:
        int gerarAleatorio(int intervaloMax);
        const double HORA_EXTRA = 5.51;
};

#endif
