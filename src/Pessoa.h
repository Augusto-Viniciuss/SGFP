#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include "CadastrarFuncionarioException.h"

class Pessoa{
    public:
        /* Construtor padrão sem argumento */
        Pessoa();
        /* Construtor que recebe os atributos de Pessoa */
        Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string CEP, int numeroResidencia);
        /* Destrutor */
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
        void setEndereco(std::string endereco);

        void validaNome(std::string nome);
        int validaIdade(std::string idadeStr);
    private:
        char nome[100], telefone[15], CPF[15];
        int idade;
        Endereco endereco;
};

#endif