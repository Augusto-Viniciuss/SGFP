#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#include "Funcionario.h"
#include <string>

/**
* Presidente é uma classe filha de Funcionário
*/
class Presidente : public Funcionario {
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Presidente();

        /**
        * Construtor
        * 
        * Inicializa os atributos do presidente
        * \param int-codigo código do presidente
        * \param string-nome nome completo do presidente
        * \param string-CPF CPF do presidente
        * \param int-idade idade do presidente
        * \param string-endereco CEP da residência do presidente
        * \param int-numeroResidencia número da residência do presidente
        * \param string-telefone telefone do presidente
        * \param int*-data array de inteiros referentes a dia/mes/ano do ingresso do presidente
        * \param int-designacao designacao do presidente (3) 
        * \param string-areaFormacao área de formação do presidente
        * \param string-formacaoMax formação máxima do presidente
        */
        Presidente(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaFormacao, std::string formacaoMax);
        
        /**
        * Métodos Get
        * \param getAreaFormacao retorna a área de formação como uma string
        * \param getFormacaoMax retorna a formação máxima como uma string
        */
        virtual std::string getAreaFormacao();
        virtual std::string getFormacaoMax();

        /**
        * Métodos Set
        * \param setAreaFormacao instancia a área de formação
        * \param setFormacaoMax instancia a formação máxima
        */
        void setAreaFormacao(std::string areaFormacao);
        void setFormacaoMax(std::string formacaoMax);

        /**
        * calcularSalarioMensal(int)
        * 
        * Calcula o salário mensal do presidente de acordo com o mês que recebe como parâmetro
        * \param int-mes mês que se deseja calcular o salário
        */
        void calcularSalarioMensal(int mes);
    private:
        char areaFormacao[100];
        char formacaoMax[100];
        const double HORA_EXTRA = 97.24; 
};

#endif
