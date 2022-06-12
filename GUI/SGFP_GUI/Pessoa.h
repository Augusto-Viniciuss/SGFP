#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"

class Pessoa{
    public:
        Pessoa();
        Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, Endereco endereco);
        Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string endereco);
        virtual ~Pessoa();
        
        /* Get */
        std::string getNome();
        std::string getTelefone();
        std::string getCPF();
        int getIdade();
        Endereco getEndereco_toObject();
        std::string getEndereco_toString();
        
        /* Set */
        void setNome(std::string nome);
        void setTelefone(std::string telefone);
        void setCPF(std::string CPF);
        void setIdade(int idade);
        void setEndereco(Endereco endereco);
        void setEndereco(std::string endereco);

    private:
        char nome[100], telefone[15], CPF[15];
        int idade;
        Endereco endereco;
};

#endif