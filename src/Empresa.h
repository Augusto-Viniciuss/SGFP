#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include "Funcionario.h"
#include "Data.h"
#include "FuncionarioJaCadastradoExcept.h"

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
        int getQtdFuncionarios(int tipo);
        double getFolhaSalarial(int mes);
        
        /* ESPECIFICAÇÕES */
        void addFuncionario(Funcionario *funcionario, int tipo);
        template<typename atributo>void modificarFuncionario(int codigo, int opcao, atributo valor);
        void excluirFuncionario(int codigo, int tipo);
        void exibirFuncionario(int codigo, int tipo);
        void exibirFuncionariosPorTipo(int tipo);
        void concederAumentoSalarial();
        void calcularFolhaSalarial(int mes);
        template<typename info> void imprimirFolhaSalarialFuncionario(const info informacao, int tipoInformacao, int tipoFuncionario);
        void imprimirFolhaSalarialEmpresa(int opcao);
        template<typename info> Funcionario* buscarFuncionario(const info informacao, int opcao, int tipo);

    private:
        std::string nome;
        std::string CNPJ;
        Data dataFundacao;
        int qtdFuncionarios[4];
        std::vector<Funcionario*> operadores;
        std::vector<Funcionario*> gerentes;
        std::vector<Funcionario*> diretores;
        Funcionario *presidente;
        double folhaSalarial[12];
        const int OPERADOR = 0;
        const int GERENTE = 1;
        const int DIRETOR = 2;
        const int PRESIDENTE = 3;
        const int BUSCAR_POR_NOME = 5;
        const int BUSCAR_POR_ENDERECO = 6;
        const int BUSCAR_POR_DATA = 7;
        const int BUSCAR_POR_CODIGO = 8;
};

#endif