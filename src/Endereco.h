#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

class Endereco{
    public:
        Endereco();
        void setEndereco(std::string numero, std::string complemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP);
        
        /* Get */
        std::string getNumero();
        std::string getComplemento();
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        
        void validaCEP(std::string CEP);
        void exibeEndereco();
        bool comparaEndereco(std::string endereco);
    private:
        std::string numero, complemento, rua, bairro, cidade, estado, CEP;
};

#endif
