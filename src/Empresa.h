#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include <string>
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Data.h"
#include "Endereco.h"
#include "FuncionarioJaCadastradoExcept.h"
#include "FuncionarioNaoEstaCadastradoExcept.h"

class Empresa {
    public:
        /* CONSTRUTOR*/
        Empresa();
        Empresa(std::string nome, std::string CNPJ, int *dataEmInt);

        /* SET */
        void setNome(std::string nome);
        void setCNPJ(std::string CNPJ);
        void setDataFundacao(int *dataEmInt);
        void setFolhaSalarial(int mes, double valor);
        
        /* GET */
        std::string getNome();
        std::string getCNPJ();
        Data getDataFundacao();
        int getQtdFuncionarios(int tipoFuncionario);
        double getFolhaSalarial(int mes);
        
        /* ESPECIFICAÇÕES */
        void addFuncionario(Funcionario *funcionario, int tipoFuncionario);
        template<typename atributo> void modificarFuncionario(int codigo, int opcao, atributo valor);
        void excluirFuncionario(int codigo);
        void exibirFuncionario(int codigo);
        void exibirTodosFuncionarios();
        void exibirFuncionariosPorTipo(int tipoFuncionario);
        void concederAumentoSalarial();
        void calcularFolhaSalarial(int mes);
        template<typename info> void imprimirFolhaSalarialFuncionario(const info informacao, int tipoInformacao);
        void imprimirFolhaSalarialEmpresa(int opcao);
        template<typename info> Funcionario* buscarFuncionario(const info informacao, int opcao);

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
        const int QTD_DE_TIPOS = 4;
};

#endif