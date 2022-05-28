#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Endereco.h"
#include "Pessoa.h"
#include <string>
#include "Data.h"

class Funcionario: public Pessoa {
    public:
        /* CONSTRUTOR */
        Funcionario();
        Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao);

        /* DESTRUTOR */
        virtual ~Funcionario();
        
        /* ESPECIFICAÇÕES */
        virtual void calcularSalarioMensal(int mes) = 0;

        /* Get */
        int getHorasTrabalhadas();
        int getCodigo();
        //int getIdade();
        double getSalarioBase();
        double getDescontosSalario();
        double getSalarioLiquido();
        double getTaxaAumento();
        //Endereco getEndereco();
        //std::string getNomeFuncionario();
        //std::string getTelefone();
        std::string getDesignacaoStr();
        int getDesignacaoInt();
        double getSalarioMensal(int mes);
        

        Data getDataIngresso();

        /* Set */
        void setHorasTrabalhadas(int horas);
        void setSalarioBase(double salario);
        void setTaxaAumento();
        void setSalarioLiquido();
        void setDesignacao(int designacao);
        //void setEndereco(Endereco endereco);
        //void setEndereco(std::string endereco); //numero,complemento,rua,bairro,cidade,estado,CEP
        //void setTelefone(std::string telefone);
        //void setNomeFuncionario(std::string nome);
        void setDataIngresso(Data data);
        void setDataIngresso(std::string data);
        void setCodigoFuncionario(int codigo);
        

    protected:
        void setDescontosSalario(double desconto);
        int gerarAleatorio(int intervaloMax);

    private:
        int horasTrabalhadas;
        int codigoFuncionario;
        //int idade;
        int designacao; /*1 = Presidente; 2 = Diretor; 3 = Gerente; 4 = Operador*/
        double salarioBase, salarioLiquido;
        double descontosSalario;
        double taxaAumento;
        //char nomeFuncionario[100];
        //char CPF[15]; /*Enviar como XXXXXXXXXXX e será armazenado como XXX.XXX.XXX-XX */
        //Endereco endereco;
        //char telefone[15]; /*Enviar como XXXXXXXXXXX e será armazenado como (XX)XXXXX-XXXX */
        Data dataIngresso;

    protected:
        double folhaSalarial[12];
        
};

#endif
