#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco{
    public:
        Endereco();
        void setEndereco(std::string numeroEComplemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP);
        
        std::string getNumeroEComplemento();
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
    private:
        std::string numeroEComplemento, rua, bairro, cidade, estado, CEP;
};

#endif