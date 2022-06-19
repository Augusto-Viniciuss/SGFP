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
#include "Arquivo.h"
#include "HistoricoArquivo.h"

#define OPERADOR 0
#define GERENTE 1
#define DIRETOR 2
#define PRESIDENTE 3
#define BUSCAR_POR_NOME 5
#define BUSCAR_POR_ENDERECO 6
#define QTD_DE_TIPOS 4

class Empresa {
    public:
        /* CONSTRUTOR*/
        Empresa();

        /* SET */

        
        /* GET */
        int getQtdFuncionarios(int tipoFuncionario);
        
        /* ESPECIFICAÇÕES */
        void addFuncionario(Funcionario *funcionario, int tipoFuncionario);
        void modificarFuncionario(int codigo, int opcao, std::string valor);
        void modificarFuncionario(int codigo, int opcao, int valor);
        void modificarFuncionario(int codigo, int *valor);
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
        Funcionario* buscarFuncionario(int codigo, int *indice, int *designacao);
        void buscarFuncionariosIntervaloTempo(int *dataInicial, int *dataFinal);
        void buscarFuncionariosParcial(std::string informacao, int opcao);

        /* DESTRUTOR */
        virtual ~Empresa();

    private:
        int qtdFuncionarios[4] = {0};
        std::vector<Funcionario*> operadores;
        std::vector<Funcionario*> gerentes;
        std::vector<Funcionario*> diretores;
        Funcionario *presidente = nullptr;
        
        Arquivo dadosArquivos; // Banco de dados
};

#endif