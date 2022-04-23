#include "Empresa.h"
#include <string>

Empresa::Empresa(std::string nome, std::string CNPJ, Data data) {
    setNome(nome);
    setCNPJ(CNPJ);
    setDataFundacao(data);
    this->qtdFuncionarios = 0;
    this->folhaSalarial = {-1, -1};
}

void Empresa::setNome(std::string nome) {
    this->nome = nome;
}

void Empresa::setCNPJ(std::string CNPJ) {
    this->CNPJ = CNPJ;
}

void Empresa::setDataFundacao(Data data) {
    this->dataFundacao = data;
}

void Empresa::setFolhaSalarial(int mes, double valor) {
    this->folhaSalarial[mes] = valor;
}

std::string Empresa::getNome() {
    return this->nome;
}

std::string Empresa::getCNPJ() {
    return this->CNPJ;
}

Data Empresa::getDataFundacao() {
    return this->dataFundacao;
}

int Empresa::getQtdFuncionarios() {
    return this->qtdFuncionarios;
}

double Empresa::getFolhaSalarial(int mes) {
    return this->folhaSalarial[mes];
}

void Empresa::addFuncionario(Funcionario funcionario) {
    this->funcionarios.push_back(funcionario);
    this->qtdFuncionario += 1;
}

void Empresa::modificarFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        std::cin << "O que deseja modificar: " << std::endl <<
                1 - "Numero de codigo\n" << std::endl <<
                2 - "Data de ingresso\n" << std::endl <<
                3 - "Nome" << std::endl <<
                4 - "Endereco" << std::endl <<
                5 - "Telefone" << std::endl <<
                6 - "Designacao" << std::endl <<
                7 - "Salario" << std::endl;

        int tipoModificacao;
        std::cin >> tipoModificacao;

        switch (tipoModificacao) {
            case 1:
                funcionario.setNumeroCodigo();
                break;
            case 2:
                funcionario.setDataIngresso();
                break;
            case 3:
                funcionario.setNome();
                break;
            case 4:
                funcionario.setEndereco();
                break;
            case 5:
                funcionario.setTelefone()
                break;
            case 6:
                funcionario.setDesignacao();
                break;
            case 7:
                funcionario.setSalario();
                break;
            }
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::excluirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionarioExiste == nullptr) {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    } else {
        delete funcionario;
        std::cout << "Funcionario excluido dos registros." 
    }
}

void Empresa::exibirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {
        std::cout << "Registro do funcionario de codigo: " << funcionario->getNumeroCodigo() << std::endl <<
                    "Nome: " << funcionario->getNome() << std::endl <<
                    "Data de ingressao: " << funcionario->getDataIngressao() << std::endl <<
                    "Endereco: " << funcionario->getEndereco() << std::endl <<
                    "Telefone: " << funcionario->getTelefone() << std::endl <<
                    "Designacao: " << funcionario->getDesignacao() << std::endl <<
                    "Salario: " << funcionario->getSalario() << std::endl;
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::exibirFuncionariosPorTipo(std::string tipo) {
    for (int i = 0; i < this->qtdFuncionario; i++) {
        if (funcionarios[i]->getDesignacao().find(tipo) != std::string::npos) {
            std::cout << "Registro do funcionario de codigo: " << funcionarios[i]->getNumeroCodigo() << std::endl <<
                    "Nome: " << funcionarios[i]->getNome() << std::endl <<
                    "Data de ingressao: " << funcionarios[i]->getDataIngressao() << std::endl <<
                    "Endereco: " << funcionarios[i]->getEndereco() << std::endl <<
                    "Telefone: " << funcionarios[i]->getTelefone() << std::endl <<
                    "Designacao: " << funcionarios[i]->getDesignacao() << std::endl <<
                    "Salario: " << funcionarios[i]->getSalario() << std::endl << std::endl;
        }
    }
}

void Empresa::concederAumentoSalarial() {
    for (int i = 0; i < this->qtdFuncionario; i++) {
        funcionarios[i]->setSalario((funcionarios->getTaxaAumento() * funcionarios->getSalario()) + funcionarios[i]->getSalario());
    }
}

void Empresa::calcularFolhaSalarial() {
    int mes;

    std::cout << "Para qual mes deseja calcular a folha salarial da empresa:" << std::endl
                "1 - Janeiro" << std::endl
                "2 - Fevereiro" << std::endl
                "3 - Marco" << std::endl
                "4 - Abril" << std::endl
                "5 - Maio" << std::endl
                "6 - Junho" << std::endl
                "7 - Julho" << std::endl
                "8 - Agosto" << std::endl
                "9 - Setembro" << std::endl
                "10 - Outubro" << std::endl
                "11 -Novembro" << std::endl
                "12 - Dezembro" << std::endl << std::endl;

    std::cin >> mes;

    if (getFolhaSalarial() != -1) {
        std::cout << "A folha salarial desse mes ja foi calculada anteriormente" << std::endl;
    } else {
        double valorTotal = 0;

        for (int i = 0; i < this->qtdFuncionario; i++) {
            valorTotal += this->funcionarios[i]->calcularSalarioMensal();;
        }

        setFolhaSalarial(mes, valorTotal);
        std::cout << "A folha salarial foi calculada com sucesso" << std::endl;
    }
}

void Empresa::imprimirFolhaSalarialFuncionario() {

}

void Empresa::imprimirFolhaSalarialEmpresa() {
    std::cout << "Deseja calcular"
}