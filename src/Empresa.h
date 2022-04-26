#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include "Funcionario.h"
#include "Data.h"

class Empresa {
    public:
        /* CONSTRUTOR*/
        Empresa();
        Empresa(std::string nome, std::string CNPJ, Data dataFundacao);

        /* SET */
        void setNome(std::string nome);
        void setCNPJ(std::string CNPJ);
        void setDataFundacao(Data data);
        void setFolhaSalarial(int mes, double valor);
        
        /* GET */
        std::string getNome();
        std::string getCNPJ();
        Data getDataFundacao();
        int getQtdFuncionarios();
        double getFolhaSalarial(int mes);
        
        /* ESPECIFICAÇÕES */
        void addFuncionario(Funcionario *funcionario);
        void modificarFuncionario(int codigo, int opcao);
        void excluirFuncionario(int codigo);
        void exibirFuncionario(int codigo);
        void exibirFuncionariosPorTipo(std::string tipo);
        void concederAumentoSalarial();
        void calcularFolhaSalarial(int mes);
        template<typename info> void imprimirFolhaSalarialFuncionario(const info informacao);
        void imprimirFolhaSalarialEmpresa(int opcao);
        template<typename info> Funcionario* buscarFuncionario(const info informacao, int opcao);

    private:
        std::string nome;
        std::string CNPJ;
        Data dataFundacao;
        int qtdFuncionarios;
        std::vector<Funcionario*> funcionarios;
        double folhaSalarial[12];
        const int BUSCAR_POR_CODIGO = 4;
};

#endif