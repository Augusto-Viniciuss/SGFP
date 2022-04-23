#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco{
    public:
        Endereco();
        void SetEndereco(std::string numeroEComplemento, std::string rua, std::string bairro, std::string cidade, std::string estado, std::string CEP);
        
        std::string GetNumeroEComplemento();
        std::string GetRua();
        std::string GetBairro();
        std::string GetCidade();
        std::string GetEstado();
        std::string GetCEP();
    private:
        std::string numeroEComplemento, rua, bairro, cidade, estado, CEP;
};

#endif