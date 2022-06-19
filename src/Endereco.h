#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include "CadastrarFuncionarioException.h"

class Endereco{
    public:
        Endereco();
        
        /* Set */
        void setNumero(int numero);
        int validaNumero(std::string numeroStr);
        void setEndereco(std::string CEP);

        /* Get */
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        int getNumero();
        
        void validaCEP(std::string CEP);
        std::string getInformacao();
        bool comparaEndereco(std::string endereco);
    private:
        char CEP[10], rua[100], bairro[50], cidade[50], estado[20];
        int numero;
};

#endif
