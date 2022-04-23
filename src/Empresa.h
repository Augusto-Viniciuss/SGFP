#pragma once

#include <iostream>
#include <vector>
#include "Funcionario.h"
#include "Data.h"

class Empresa {
    private:
        std::string nome;
        std::string CNPJ;
        Data dataFundacao;
        int qtdFuncionario;
        std::vector<Funcionario> *funcionarios;
        double folhaSalarial[12] = {-1};
    
    public:
        Empresa(std::string nome, std::string CNPJ, Data dataFundacao);
        void setNome(std::string nome);
        void setCNPJ(std::string CNPJ);
        void setDataFundacao(Data data);
        void setFolhaSalarial(int mes, double valor);
        std::string getNome();
        std::string getCNPJ();
        Data getDataFundacao();
        int getQtdFuncionarios();
        double getFolhaSalarial(int mes);
        void addFuncionario(Funcionario funcionario);
        void modificarFuncionario(int codigo);
        void excluirFuncionario(int codigo);
        void exibirFuncionario(int codigo);
        void exibirFuncionariosPorTipo(std::string tipo);
        void concederAumentoSalarial();
        void calcularFolhaSalarial();
        ///void imprimirFolhaSalarialFuncionario() Provavelmente será implementada com template
        void imprimirFolhaSalarialEmpresa();
        ///Funcionario buscarFuncionario(); Provavelmente será implementada com template
}