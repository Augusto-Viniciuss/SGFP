#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"

class Pessoa{
    public:
        Pessoa();
        Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string CEP);
        virtual ~Pessoa();
        
        /* Get */
        std::string getNome();
        std::string getTelefone();
        std::string getCPF();
        int getIdade();
        Endereco* getEndereco();

        /* Set */
        void setNome(std::string nome);
        void setTelefone(std::string telefone);
        void setCPF(std::string CPF);
        void setIdade(int idade);

    private:
        char nome[100], telefone[15], CPF[15];
        int idade;
        Endereco endereco;
};

#endif