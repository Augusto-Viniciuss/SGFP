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

void Empresa::addFuncionario(Funcionario funcionario) {
    this->funcionarios.push_back(funcionario);
    this->qtdFuncionario += 1;
}

void Empresa::modificarFuncionario(int codigo) {
    bool funcionarioExiste = false;
    int index;

    for (int i = 0; i < this->qtdFuncionario; i++) {
        if (funcionarios[i]->getNumeroCodigo() == codigo) {
            index = i;
            funcionarioExiste = true;
            break;
        }
    }

    if (funcionarioExiste) {
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
            funcionarios[index].setNumeroCodigo();
            break;
        case 2:
            funcionarios[index].setDataIngresso();
            break;
        case 3:
            funcionarios[index].setNome();
            break;
        case 4:
            funcionarios[index].setEndereco();
            break;
        case 5:
            funcionarios[index].setTelefone()
            break;
        case 6:
            funcionarios[index].setDesignacao();
            break;
        case 7:
            funcionarios[index].setSalario();
            break;
        }
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::excluirFuncionario(int codigo) {
    bool funcionarioExiste = false
    
    for (int i = 0; i < this->qtdFuncionario; i++) {
        if (this->funcionarios[i]->getNumeroCodigo() == codigo) {
            funcionarios.erase(i);
            funcionarioExiste = true;
            std::cout << "Funcionario excluido dos registros." << std::endl;
            break;
        }
    }

    if (!funcionarioExiste) {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::exibirFuncionario(int codigo) {
    bool funcionarioExiste = false;
    int index;

    for (int i = 0; i < this->qtdFuncionario; i++) {
        if (funcionarios[i]->getNumeroCodigo() == codigo) {
            index = i;
            funcionarioExiste = true;
            break;
        }
    }

    if (funcionarioExiste) {
        std::cout << "Registro do funcionario de codigo: " << funcionarios[index]->getNumeroCodigo() << std::endl <<
                    "Nome: " << funcionarios[index]->getNome() << std::endl <<
                    "Data de ingressao: " << funcionarios[index]->getDataIngressao() << std::endl <<
                    "Endereco: " << funcionarios[index]->getEndereco() << std::endl <<
                    "Telefone: " << funcionarios[index]->getTelefone() << std::endl <<
                    "Designacao: " << funcionarios[index]->getDesignacao() << std::endl <<
                    "Salario: " << funcionarios[index]->getSalario() << std::endl;
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