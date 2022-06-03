#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

class Endereco{
    public:
        Endereco();
        void setEndereco(std::string CEP, std::string rua, std::string bairro, std::string cidade, std::string estado);
        
        /* Get */
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        
        void validaCEP(std::string CEP);
        void exibeEndereco();
        bool comparaEndereco(std::string endereco);
    private:
        char CEP[10], rua[100], bairro[50], cidade[50], estado[20];
};

#endif
