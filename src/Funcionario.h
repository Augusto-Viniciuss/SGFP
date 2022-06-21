#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Endereco.h"
#include "Pessoa.h"
#include "FolhaSalarial.h"
#include <string>
#include "Data.h"
#include "CadastrarFuncionarioException.h"

class Funcionario: public Pessoa {
    public:
        /* CONSTRUTOR */
        Funcionario();
        Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao);

        /* DESTRUTOR */
        virtual ~Funcionario();
        
        /* ESPECIFICAÇÕES */
        virtual void calcularSalarioMensal(int mes) = 0;
        int validaDesignacao(std::string designacaoStr);
        void validaDataIngresso(std::string dataStr, int* dataInt);
        int validaCodigoFuncionario(std::string codigoStr);
        
        /* Get */
        int getHorasTrabalhadas(int mes);
        int getCodigoFuncionario();
        std::string getDesignacaoStr();
        int getDesignacaoInt();
        FolhaSalarial *getFolhaSalarial(int mes);
        Data getDataIngresso();

        /* Set */
        void setHorasTrabalhadas(int mes, int valor);
        void setDesignacao(int designacao);
        void setDataIngresso(int *data);
        void setCodigoFuncionario(int codigo);
        
    protected:
        /* Protected para apenas ser acessado por um funcionário */
        int gerarAleatorio(int intervaloMax);

    private:

        int horasTrabalhadas[12];
        int codigoFuncionario;
        int designacao; /*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
        FolhaSalarial folhaSalarial[12];
        Data dataIngresso;
       
};

#endif
