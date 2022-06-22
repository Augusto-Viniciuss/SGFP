#ifndef FOLHASALARIAL_H
#define FOLHASALARIAL_H

#include <vector>
#include <iostream>

class FolhaSalarial {
    public:
        /* Construtor padrão sem argumento */
        FolhaSalarial();
        /* Construtor que recebe e instancia a designação do funcionário */
        FolhaSalarial(int designacao);
        /* Destrutor */
        virtual ~FolhaSalarial();

        /**
		* Métodos Set publics
		* \param setSalarioLiquido seta o salario liquido.
		* \return Void.
		*/
        void setSalarioLiquido(double salario);

        /**
		* Métodos Get publics
		* \param getSalarioBase retorna o valor do salario base.
        * \param getSalarioLiquido retorna o valor do salario liquido.
        * \param getDescontoImpostoRenda retorna o valor do desconto do imposto de renda no salario liquido.
        * \param getDescontoPrevidencia retorna o valor do desconto da previdencia social no salario liquido. 
		* \return Retorna um double.
		*/
        double getSalarioBase();
        double getSalarioLiquido();
        double getDescontoImpostoRenda();
        double getDescontoPrevidencia();

        /**
		* aumentarSalarioBase()
		* 
        * Aumenta o salario base de acordo com a taxa de aumento.
		* \return void.
		*/
        void aumentarSalarioBase();
    
    private:
        /**
		* Métodos Set privates
		* \param setTaxaAumento seta a taxa de aumento do salario base.
        * \param setSalarioBase seta o salario base.
        * \param setDescontoImpostoRenda seta o desconto do imposto de renda no salario liquido.
        * \param setDescontoPrevidencia seta o desconto da previdencia social no salario liquido. 
		* \return Void.
		*/
        void setTaxaAumento(int designacao);
        void setSalarioBase(int designacao);
        void setDescontoImpostoRenda(double desconto);
        void setDescontoPrevidencia(double desconto);

        /**
		* Métodos Get privates
		* \param getTaxaAumento retorna a taxa de aumento para o salario base. 
		* \return Retorna um double.
		*/
        double getTaxaAumento();

    private:
        double taxaAumento; /*!< Valor da taxa de aumento para o salario base */
        double salarioBase; /*!< Valor do salario base */
        double salarioLiquido; /*!< Valor do salario liquido */
        double descontoImpostoRenda; /*!< Valor do desconto do imposto de renda no salario liquido */
        double descontoPrevidencia; /*!< Valor do desconto da previdencia social no salario liquido */
};

#endif