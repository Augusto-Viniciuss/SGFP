#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include "CadastrarFuncionarioException.h"

class Pessoa{
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Pessoa();

        /**
        * Construtor
        * 
        * Inicializa os atributos da pessoa
        * \param string-nome nome completo da pessoa
        * \param string-telefone telefone da pessoa
        * \param string-CPF CPF da pessoa
        * \param int-idade idade da pessoa
        * \param string-endereco CEP da residência da pessoa
        * \param int-numeroResidencia número da residência da pessoa
        */
        Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string CEP, int numeroResidencia);
        
        /**
        * Destrutor
        * 
        * Destrutor padrão
        */
        virtual ~Pessoa();
        
        /**
        * Métodos Get
        * \param getNome retorna o nome da pessoa em forma de string
        * \param getTelefone retorna o telefone da pessoa em forma de string
        * \param getCPF retorna o CPF da pessoa em forma de string
        * \param getIdade retorna a idade da pessoa em forma de int
        * \param getEndereco retorna um ponteiro para o endereço desejado
        */
        std::string getNome();
        std::string getTelefone();
        std::string getCPF();
        int getIdade();
        Endereco* getEndereco();

        /**
        * Métodos Set
        * \param setNome instancia o nome da pessoa
        * \param setTelefone instancia o telefone da pessoa
        * \param setCPF instancia o CPF da pessoa
        * \param setIdade instancia a idade da pessoa
        * \param setEndereco instancia o endereço da pessoa
        */
        void setNome(std::string nome);
        void setTelefone(std::string telefone);
        void setCPF(std::string CPF);
        void setIdade(int idade);
        void setEndereco(std::string endereco);

        /**
        * validaNome(string)
        * 
        * Método para validar o nome digitado pelo usuário
        * \param string-codigoStr código digitado pelo usuário
        */
        void validaNome(std::string nome);

        /**
        * validaIdade(string)
        * 
        * Método para validar a idade digitada pelo usuário
        * \param string-codigoStr código digitado pelo usuário
        */
        int validaIdade(std::string idadeStr);
    private:
        char nome[100], telefone[15], CPF[15];
        int idade;
        Endereco endereco;
};

#endif