#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

class Endereco{
    public:
        Endereco();
        void setEndereco(std::string numeroEComplemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP);
        
        /* Get */
        std::string getNumeroEComplemento();
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        
        bool validaCEP(std::string CEP, std::string rua);
        void exibeEndereco();
    private:
        std::string numeroEComplemento, rua, bairro, cidade, estado, CEP;
};

#endif