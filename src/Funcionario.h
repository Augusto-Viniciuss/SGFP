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
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Funcionario();

        /**
        * Construtor
        * 
        * Inicializa os atributos do funcionário
        * \param int-codigo código do funcionário
        * \param string-nome nome completo do funcionário
        * \param string-CPF CPF do funcionário
        * \param int-idade idade do funcionário
        * \param string-endereco CEP da residência do funcionário
        * \param int-numeroResidencia número da residência do funcionário
        * \param string-telefone telefone do funcionário
        * \param int*-data array de inteiros referentes a dia/mes/ano do ingresso do funcionário
        * \param int-designacao designacao do funcionário (de 0 a 3)
        */
        Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao);

        /**
        * Destrutor
        * 
        * Destrutor padrão
        */
        virtual ~Funcionario();
        
        /**
        * virtual calcularSalarioMensal(int) = 0
        * 
        * Método virtual puro para calcular o salário mensal do funcionário de acordo com sua designação
        * \param int-mes mês que seja calcular o salário
        */
        virtual void calcularSalarioMensal(int mes) = 0;

        /**
        * validaDesignacao(string)
        * 
        * Método que vê se a designação digitada pelo usuário é válida
        * \param string-DesignacaoStr designação digitada pelo usuário
        */
        int validaDesignacao(std::string designacaoStr);

        /**
        * validaDataIngresso(string, int*)
        * 
        * Método para validar e instanciar a data digitada pelo usuário
        * \param string-dataStr data digitada pelo usuário
        * \param int*-dataInt ponteiro para a data que deseja ser instanciada
        */
        void validaDataIngresso(std::string dataStr, int* dataInt);

        /**
        * validaCodigoFuncionario(string)
        * 
        * Método para validar o código digitado pelo usuário
        * \param string-codigoStr código digitado pelo usuário
        */
        int validaCodigoFuncionario(std::string codigoStr);
        
        /**
        * Métodos Get
        * \param getHorasTrabalhadas retorna as horas trabalhadas do mês
        * \param getCodigoFuncionario retorna o código do funcionário
        * \param getDesignacaoStr retorna a designação em forma de string
        * \param getDesignacaoInt retorna a designação em forma de int
        * \param getFolhaSalarial retorna um ponteiro para a folha salarial do mês desejado
        * \param getDataIngresso retorna um objeto data com a data de ingresso do funcionário
        */
        int getHorasTrabalhadas(int mes);
        int getCodigoFuncionario();
        std::string getDesignacaoStr();
        int getDesignacaoInt();
        FolhaSalarial *getFolhaSalarial(int mes);
        Data getDataIngresso();

        /**
        * Métodos Set
        * \param setHorasTrabalhadas instancia as horas trabalhadas do mês desejado
        * \param setDesignação instancia a designação do funcionário
        * \param setDataIngreso instancia a data de ingresso do funcionário
        * \param setCodigoFuncionario instancia o código do funcionário
        */
        void setHorasTrabalhadas(int mes, int valor);
        void setDesignacao(int designacao);
        void setDataIngresso(int *data);
        void setCodigoFuncionario(int codigo);
        
    protected:
        /**
        * gerarAleatorio(int)
        * 
        * Método para gerar um número aleatório dentro do intervalo digitado
        * \param int-intervaloMax intervalo máximo que deseja se gerar o número aleatório
        */
        int gerarAleatorio(int intervaloMax);

    private:

        int horasTrabalhadas[12];
        int codigoFuncionario;
        int designacao; /*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
        FolhaSalarial folhaSalarial[12];
        Data dataIngresso;
       
};

#endif
