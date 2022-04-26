#include "Empresa.h"
#include "Endereco.h"
#include <string>

Empresa::Empresa(){}

Empresa::Empresa(std::string nome, std::string CNPJ, Data data) {
    setNome(nome);
    setCNPJ(CNPJ);
    setDataFundacao(data);
    this->qtdFuncionarios = 0;
    this->folhaSalarial[12] = {-1};
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
    if (folhaSalarial[mes -1] == -1) {
        calcularFolhaSalarial(mes - 1);
    }

    return this->folhaSalarial[mes - 1];
}

void Empresa::addFuncionario(Funcionario *funcionario) {
    this->funcionarios.push_back(funcionario);
    this->qtdFuncionarios += 1;
}

void Empresa::modificarFuncionario(int codigo, int opcao) {
    Funcionario *funcionario = buscarFuncionario(codigo, BUSCAR_POR_CODIGO);
    
    if (funcionario != nullptr) {
        if (opcao == 1) {
            int codigo;

            std::cout << "Digite o numero de codigo de funcionario novo: ";
            std::cin >> codigo;
            funcionario->setCodigoFuncionario(codigo);
        } else if (opcao == 2) {
            int dia, mes, ano;

            std::cout << "Digite a data de ingressao nova: " << std::endl;
            std::cout << "Dia: ";
            std::cin >> dia;
            std::cout << "Mes: ";
            std::cin >> mes;
            std::cout << "Ano: ";
            std::cin >> ano;

            Data data = Data(dia, mes, ano);

            funcionario->setDataIngresso(data);
        } else if (opcao == 3) {
            std::string nome;

            std::cout << "Digite o nome novo: ";
            std::cin >> nome;
            funcionario->setNomeFuncionario(nome);
        } else if (opcao == 4) {
            std::string numeroEComplemento, rua, bairro, cidade, estado, CEP;

            std::cout << "Digite a rua nova: ";
            getline(std::cin, rua);
            std::cout << "Digite numero e complemento (OPCIONAL) novo: ";
            getline(std::cin, numeroEComplemento);
            std::cout << "Digite o bairro novo: ";
            getline(std::cin, bairro);
            std::cout << "Digite a cidade nova: ";
            getline(std::cin, cidade);
            std::cout << "Digite o estado novo: ";
            getline(std::cin, estado);
            std::cout << "Digite o CEP novo: ";
            getline(std::cin, CEP);

            Endereco endereco;
            endereco.setEndereco(numeroEComplemento, rua, bairro, cidade, estado, CEP);

            funcionario->setEndereco(endereco);
        } else if (opcao == 5) {
            std::string telefone;

            std::cout << "Digite o telefone novo: ";
            std::cin >> telefone;

            funcionario->setTelefone(telefone);
        } else if (opcao == 6) {
            std::string designacao;

            std::cout << "Digite a nova designacao novo: ";
            std::cin >> designacao;

            funcionario->setDesignacao(designacao);
        } else if (opcao == 7) {
            double salario;
            
            std::cout << "Digite o novo salario: ";
            std::cin >> salario;
            
            funcionario->setSalario(salario);
        }
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::excluirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo, 4);
    
    if (funcionario == nullptr) {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    } else {
        delete funcionario;
        std::cout << "Funcionario excluido dos registros." << std::endl;
    }
}

void Empresa::exibirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo, BUSCAR_POR_CODIGO);

    if (funcionario != nullptr) {
        std::cout << "Registro do funcionario de codigo: " << funcionario->getCodigo() << std::endl;
        std::cout << "Nome: " << funcionario->getNomeFuncionario() << std::endl;
        std::cout << "Data de ingressao: "; 
        funcionario->getDataIngresso().exibeData(); 
        std::cout << std::endl;
        std::cout << "Endereco: ";
        funcionario->getEndereco().exibeEndereco(); 
        std::cout << std::endl;std::cout << "Telefone: " << funcionario->getTelefone() << std::endl;
        std::cout << "Designacao: " << funcionario->getDesignacao() << std::endl;
        std::cout << "Salario: " << funcionario->getSalario() << std::endl;
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::exibirFuncionariosPorTipo(std::string tipo) {
    for (int i = 0; i < this->qtdFuncionarios; i++) {
        if (funcionarios[i]->getDesignacao().find(tipo) != std::string::npos) {
            std::cout << "Registro do funcionario de codigo: " << funcionarios[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << funcionarios[i]->getNomeFuncionario() << std::endl;
            std::cout << "Data de ingressao: "; 
            funcionarios[i]->getDataIngresso().exibeData(); 
            std::cout << std::endl;
            std::cout << "Endereco: ";
            funcionarios[i]->getEndereco().exibeEndereco(); 
            std::cout << std::endl;
            std::cout << "Telefone: " << funcionarios[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << funcionarios[i]->getDesignacao() << std::endl;
            std::cout << "Salario: " << funcionarios[i]->getSalario() << std::endl << std::endl;
        }
    }
}

void Empresa::concederAumentoSalarial() {
    for (int i = 0; i < this->qtdFuncionarios; i++) {
        funcionarios[i]->setSalario((funcionarios[i]->getTaxaAumento() * funcionarios[i]->getSalario()) + funcionarios[i]->getSalario());
    }
}

void Empresa::calcularFolhaSalarial(int mes) {
    if (getFolhaSalarial(mes - 1) != -1) {
        std::cout << "A folha salarial desse mes ja foi calculada anteriormente" << std::endl;
    } else {
        double valorTotal = 0;

        for (int i = 0; i < this->qtdFuncionarios; i++) {
            valorTotal += this->funcionarios[i]->calcularSalarioMensal();
        }

        setFolhaSalarial(mes, valorTotal);
        std::cout << "A folha salarial foi calculada com sucesso" << std::endl;
    }
}

template<typename info>
void Empresa::imprimirFolhaSalarialFuncionario(const info informacao) {
    Funcionario *funcionario;
    funcionario = buscarFuncionario(informacao);

    std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " ///// Codigo: " << funcionario->getCodigo() << std::endl;
    std::cout << "Salario base: " << funcionario->getSalario();
    std::cout << "Descontos: " << funcionario->getDescontosSalario();
    std::cout << "Salario liquido: " << (funcionario->getSalario() - funcionario->getDescontosSalario()) << std::endl << std::endl;
}

void Empresa::imprimirFolhaSalarialEmpresa(int opcao) {
    if (opcao == 1) {
        double valorTotal = 0;

        for (int i = 0; i < this->qtdFuncionarios; i++) {
            
        }

        std::cout << getNome() << " ///// " << getCNPJ() << std::endl;
        std::cout << "A folha salarial para o mes solicitado eh: " << valorTotal << std::endl;
    }
}

template<typename info>
Funcionario* Empresa::buscarFuncionario(const info informacao, int opcao) {
    for (int i = 0; i < this->qtdFuncionarios; i++) {
        switch (opcao) {
        case 1:
            if (this->funcionarios[i]->getNome().find(informacao) != std::string::npos) return funcionarios[i];
            break;
        case 2:
            if (this->funcionarios[i]->getEndereco().comparaEndereco(informacao) != std::string::npos) return funcionarios[i];
            break;
        case 3:
            if (this->funcionarios[i]->getDataDeInsercao().comparaDatas(informacao)) return funcionarios[i];
            break;
        case 4:
            if (this->funcionarios[i]->getCodigo() == informacao) return funcionarios[i];
            break;
        }
    }
}
