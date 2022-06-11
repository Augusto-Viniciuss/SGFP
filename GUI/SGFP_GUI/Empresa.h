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
        
        /* GET */
        std::string getNome();
        std::string getCNPJ();
        Data getDataFundacao();
        int getQtdFuncionarios(int tipoFuncionario);
        
        /* ESPECIFICAÇÕES */
        void addFuncionario(Funcionario *funcionario, int tipoFuncionario);
        void modificarFuncionario(int codigo, int opcao, std::string valor);
        void modificarFuncionario(int codigo, int opcao, int valor);
        void modificarFuncionario(int codigo, int opcao, int *valor);
        void excluirFuncionario(int codigo);
        void exibirFuncionario(int codigo);
        void exibirTodosFuncionarios();
        void exibirFuncionariosPorTipo(int tipoFuncionario);
        void concederAumentoSalarial();
        void calcularFolhaSalarial(int mes);
        void imprimirFolhaSalarialFuncionario(int codigo);
        void imprimirFolhaSalarialFuncionario(std::string nome);
        void imprimirFolhaSalarialEmpresa(int opcao);
        Funcionario* buscarFuncionario(int codigo);
        Funcionario* buscarFuncionario(int *data);
        Funcionario* buscarFuncionario(std::string informacao, int opcao);

    private:
        std::string nome;
        std::string CNPJ;
        Data dataFundacao;
        int qtdFuncionarios[4];
        std::vector<Funcionario*> operadores;
        std::vector<Funcionario*> gerentes;
        std::vector<Funcionario*> diretores;
        Funcionario *presidente;
        const int OPERADOR = 0;
        const int GERENTE = 1;
        const int DIRETOR = 2;
        const int PRESIDENTE = 3;
        const int BUSCAR_POR_NOME = 5;
        const int BUSCAR_POR_ENDERECO = 6;
        const int QTD_DE_TIPOS = 4;
};

#endif