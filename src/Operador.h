#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

/**
* Operador é uma classe filha de Funcionário
*/
class Operador : public Funcionario{
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Operador();

        /**
        * Construtor
        * 
        * Inicializa os atributos do operador
        * \param int-codigo código do operador
        * \param string-nome nome completo do operador
        * \param string-CPF CPF do operador
        * \param int-idade idade do operador
        * \param string-endereco CEP da residência do operador
        * \param int-numeroResidencia número da residência do operador
        * \param string-telefone telefone do operador
        * \param int*-data array de inteiros referentes a dia/mes/ano do ingresso do operador
        * \param int-designacao designacao do operador (0)
        */
        Operador(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao);
        
        /**
        * calcularSalarioMensal(int)
        * 
        * Calcula o salário mensal do operador de acordo com o mês que recebe como parâmetro
        * \param int-mes mês que se deseja calcular o salário
        */
        void calcularSalarioMensal(int mes);
    
    private:
        const double HORA_EXTRA = 14.10;
};

#endif
