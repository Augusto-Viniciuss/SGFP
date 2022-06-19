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

        /* Set public */
        void setSalarioLiquido(double salario);

        /* Get public */
        double getSalarioBase();
        double getSalarioLiquido();
        double getDescontoImpostoRenda();
        double getDescontoPrevidencia();

        /* Método para dar o aumento */
        void aumentarSalarioBase();
    
    private:
        /* Set private */
        void setTaxaAumento(int designacao);
        void setSalarioBase(int designacao);
        void setDescontoImpostoRenda(double desconto);
        void setDescontoPrevidencia(double desconto);

        /* Get private */
        double getTaxaAumento();

    private:
        double taxaAumento;
        double salarioBase;
        double salarioLiquido;
        double descontoImpostoRenda;
        double descontoPrevidencia;
};

#endif