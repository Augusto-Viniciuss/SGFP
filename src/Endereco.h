#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include "CadastrarFuncionarioException.h"

/**
* Classe criada para facilitar o amarzenamento de dados do endereço
*/
class Endereco{
    public:
        /**
        * Construtor
        * 
        * Construtor padrão sem argumentos 
        */
        Endereco();
        
        /**
        * Métodos Set
        * \param setNumero instancia o número da residência
        * \param setEndereco através do CEP, instancia os dados referentes ao endereço (rua, bairro, ...)
        */
        void setNumero(int numero);
        void setEndereco(std::string CEP);

        /**
        * Métodos Get
        * \param getRua retorna a rua do endereço em forma de string
        * \param getBairro retorna o bairro do endereço em forma de string
        * \param getCidade retorna a cidade do endereço em forma de string
        * \param getEstado retorna o estado do endereço em forma de string
        * \param getCEP retorna o CEP do endereço em forma de string
        * \param getNumero retorna o número da residência em forma de inteiro
        */
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        int getNumero();
        
        /**
        * validaCEP(string)
        * 
        * Método que recebe um CEP e verifica se ele é válido e já salva
        * \param string-CEP CEP digitado pelo usuário
        */
        void validaCEP(std::string CEP);

        /**
        * getInformacao()
        * 
        * Método que retorna o endereço completo em forma de string
        */
        std::string getInformacao();

        /**
        * comparaEndereco(string)
        * 
        * Método que verifica se o endereço do argumento é igual ao endereço do funcionário
        * \param string-endereco CEP que deseja ser comparado digitado pelo usuário
        */
        bool comparaEndereco(std::string endereco);
        
        /**
        * validaNumero(string)
        * 
        * Método que valida o número da residência do funcionário
        * \param string-numeroStr número digitado pelo usuário
        */
        /* Valida o número da residência do funcionário */
        int validaNumero(std::string numeroStr);
    private:
        char CEP[10], rua[100], bairro[50], cidade[50], estado[20];
        int numero;
};

#endif
