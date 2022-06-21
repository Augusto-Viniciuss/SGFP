#ifndef DIRETOR_H
#define DIRETOR_H

#include "Funcionario.h"
#include <string>

/**
* Diretor é uma classe filha de Funcionário
*/
class Diretor : public Funcionario{
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Diretor();

        /**
        * Construtor
        * 
        * Inicializa os atributos do diretor
        * \param int-codigo código do diretor
        * \param string-nome nome completo do diretor
        * \param string-CPF CPF do diretor
        * \param int-idade idade do diretor
        * \param string-endereco CEP da residência do diretor
        * \param int-numeroResidencia número da residência do diretor
        * \param string-telefone telefone do diretor
        * \param int*-data array de inteiros referentes a dia/mes/ano do ingresso do diretor
        * \param int-designacao designacao do diretor (2)
        * \param string-areaSupervisao área de supervisão do diretor 
        * \param string-areaFormacao área de formação do diretor
        */
        Diretor(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, int numeroResidencia, std::string telefone, int *data, int designacao, std::string areaSupervisao, std::string areaFormacao);
        
        /**
        * Métodos Get
        * \param getAreaSupervisao retorna a área de supervisão como uma string
        * \param getAreaFormacao retorna a área de formação como uma string
        */
        std::string getAreaSupervisao();
        std::string getAreaFormacao();
        
        /**
        * Métodos Set
        * \param setAreaSupervisao instancia a área de supervisão
        * \param setAreaFormacao instancia a área de formação
        */
        void setAreaSupervisao(std::string areaSupervisao);
        void setAreaFormacao(std::string areaFormacao);
        
        /**
        * calcularSalarioMensal(int)
        * 
        * Calcula o salário mensal do diretor de acordo com o mês que recebe como parâmetro
        * \param int-mes mês que se deseja calcular o salário
        */
        void calcularSalarioMensal(int mes);
    
    private:
        char areaSupervisao[100];
        char areaFormacao[100];
        const double HORA_EXTRA = 74.48;
};

#endif
