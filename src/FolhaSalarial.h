#ifndef FOLHASALARIAL_H
#define FOLHASALARIAL_H

#include <vector>

class FolhaSalarial {
    public:
        FolhaSalarial();
        FolhaSalarial(int designacao);
        virtual ~FolhaSalarial();
        void setSalarioLiquido(double salario);
        double getSalarioBase();
        double getSalarioLiquido();
        double getDescontoImpostoRenda();
        double getDescontoPrevidencia();
        void aumentarSalarioBase();
    
    private:
        void setTaxaAumento(int designacao);
        void setSalarioBase(int designacao);
        void setDescontoImpostoRenda(double desconto);
        void setDescontoPrevidencia(double desconto);
        double getTaxaAumento();

    private:
        double taxaAumento;
        double salarioBase;
        double salarioLiquido;
        double descontoImpostoRenda;
        double descontoPrevidencia;
};

#endif