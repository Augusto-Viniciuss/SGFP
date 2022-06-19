#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include "CadastrarFuncionarioException.h"

class Endereco{
    public:
        /* Construtor */
        Endereco();
        
        /* Set */
        void setNumero(int numero);
        void setEndereco(std::string CEP);

        /* Get */
        std::string getRua();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();
        int getNumero();
        
        /* Recebe um CEP e verifica se ele é válido e já salva */
        void validaCEP(std::string CEP);
        /* Retorna o endereço completo em forma de string */
        std::string getInformacao();
        /* Verifica se o endereço do argumento é igual ao endereço do funcionário */
        bool comparaEndereco(std::string endereco);
        /* Valida o número da residência do funcionário */
        int validaNumero(std::string numeroStr);
    private:
        char CEP[10], rua[100], bairro[50], cidade[50], estado[20];
        int numero;
};

#endif
