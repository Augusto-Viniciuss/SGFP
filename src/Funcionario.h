#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Endereco.h"
#include "Pessoa.h"
#include "FolhaSalarial.h"
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
        int getCodigoFuncionario();
        std::string getDesignacaoStr();
        int getDesignacaoInt();
        FolhaSalarial getFolhaSalarial(int mes);
        
        Data getDataIngresso();

        /* Set */
        void setHorasTrabalhadas(int horas);
        void setDesignacao(int designacao);
        void setDataIngresso(int *data);
        void setDataIngresso(std::string data);
        void setCodigoFuncionario(int codigo);
        
    protected:
        int gerarAleatorio(int intervaloMax);

    private:
        int horasTrabalhadas;
        int codigoFuncionario;
        int designacao; /*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
        FolhaSalarial folhaSalarial[12];
        Data dataIngresso;
       
};

#endif
