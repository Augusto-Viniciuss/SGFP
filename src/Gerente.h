#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include <string>

/**
* Gerente é uma classe filha de Funcionário
*/
class Gerente : public Funcionario{
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Gerente();

        /**
        * Construtor
        * 
        * Inicializa os atributos do gerente
        * \param int-codigo código do gerente
        * \param string-nome nome completo do gerente
        * \param string-CPF CPF do gerente
        * \param int-idade idade do gerente
        * \param string-endereco CEP da residência do gerente
        * \param int-numeroResidencia número da residência do gerente
        * \param string-telefone telefone do gerente
        * \param int*-data array de inteiros referentes a dia/mes/ano do ingresso do gerente
        * \param int-designacao designacao do gerente (1)
        * \param string-areaSupervisao área de supervisão do gerente 
        */
        Gerente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao);
        
        /**
        * Métodos Get
        * \param getAreaSupervisao retorna a área de supervisão como uma string
        */
        std::string getAreaSupervisao();
        
        /**
        * Métodos Set
        * \param setAreaSupervisao instancia a área de supervisão
        */
        void setAreaSupervisao(std::string areaSupervisao);
        
        /**
        * calcularSalarioMensal(int)
        * 
        * Calcula o salário mensal do gerente de acordo com o mês que recebe como parâmetro
        * \param int-mes mês que se deseja calcular o salário
        */
        void calcularSalarioMensal(int mes);

    private:
        char areaSupervisao[100];
        const double HORA_EXTRA = 40.16;
};

#endif
