#include "Empresa.h"
#include "Endereco.h"
#include <string>

Empresa::Empresa(){}

Empresa::Empresa(std::string nome, std::string CNPJ, Data data) {
    setNome(nome);
    setCNPJ(CNPJ);
    setDataFundacao(data);
    this->qtdFuncionarios[4] = {0};
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

int Empresa::getQtdFuncionarios(int tipo) {
    return this->qtdFuncionarios[tipo];
}

double Empresa::getFolhaSalarial(int mes) {
    if (folhaSalarial[mes -1] == -1) {
        calcularFolhaSalarial(mes - 1);
    }

    return this->folhaSalarial[mes - 1];
}

void Empresa::addFuncionario(Funcionario *funcionario, int tipo) {
    Funcionario *func = buscarFuncionario(funcionario->getNomeFuncionario(), BUSCAR_POR_NOME, tipo);

    if(!(func != nullptr)) {
        throw FuncionarioJaCadastradoExcept();
    }

    switch (tipo) {
    case 0:
        operadores.push_back(funcionario);
        qtdFuncionarios[tipo] += 1;
        break;
    case 1:
        gerentes.push_back(funcionario);
        qtdFuncionarios[tipo] += 1;
        break; 
    case 2:
        diretores.push_back(funcionario);
        qtdFuncionarios[tipo] += 1;
        break;
    case 3:
        presidente = funcionario;
        qtdFuncionarios[tipo] += 1;
        break;
    }
}

template<typename atributo>
void Empresa::modificarFuncionario(int codigo, int opcao, atributo valor) {
    Funcionario *funcionario = buscarFuncionario(codigo, BUSCAR_POR_CODIGO);
    
    if (funcionario != nullptr) {
        if (opcao == 1) {
            funcionario->setCodigoFuncionario(valor);
        } else if (opcao == 2) {
            funcionario->setDataIngresso(valor);
        } else if (opcao == 3) {
            funcionario->setNomeFuncionario(valor);
        } else if (opcao == 4) {
            funcionario->setEndereco(valor);
        } else if (opcao == 5) {
            funcionario->setTelefone(valor);
        } else if (opcao == 6) {
            funcionario->setDesignacao(valor);
        } else if (opcao == 7) {
            funcionario->setSalario(valor);
        }
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::excluirFuncionario(int codigo, int tipo) {
    Funcionario *funcionario = buscarFuncionario(codigo, BUSCAR_POR_CODIGO, tipo);
    
    if (funcionario == nullptr) {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    } else {
        delete funcionario;
        std::cout << "Funcionario excluido dos registros." << std::endl;
    }
}

void Empresa::exibirFuncionario(int codigo, int tipo) {
    Funcionario *funcionario = buscarFuncionario(codigo, BUSCAR_POR_CODIGO, tipo);

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

void Empresa::exibirFuncionariosPorTipo(int tipo) {
    for (int i = 0; i < this->qtdFuncionarios[tipo]; i++) {
        if(tipo == OPERADOR) {
            std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << operadores[i]->getNomeFuncionario() << std::endl;
            std::cout << "Data de ingressao: "; 
            operadores[i]->getDataIngresso().exibeData(); 
            std::cout << std::endl;
            std::cout << "Endereco: ";
            operadores[i]->getEndereco().exibeEndereco(); 
            std::cout << std::endl;
            std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << operadores[i]->getDesignacao() << std::endl;
            std::cout << "Salario: " << operadores[i]->getSalario() << std::endl << std::endl;
        } else if(tipo == GERENTE) {
            std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << gerentes[i]->getNomeFuncionario() << std::endl;
            std::cout << "Data de ingressao: "; 
            gerentes[i]->getDataIngresso().exibeData(); 
            std::cout << std::endl;
            std::cout << "Endereco: ";
            gerentes[i]->getEndereco().exibeEndereco(); 
            std::cout << std::endl;
            std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << gerentes[i]->getDesignacao() << std::endl;
            std::cout << "Salario: " << gerentes[i]->getSalario() << std::endl << std::endl;
        } else if (tipo == DIRETOR) {
            std::cout << "Registro do funcionario de codigo: " << diretores[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << diretores[i]->getNomeFuncionario() << std::endl;
            std::cout << "Data de ingressao: "; 
            diretores[i]->getDataIngresso().exibeData(); 
            std::cout << std::endl;
            std::cout << "Endereco: ";
            diretores[i]->getEndereco().exibeEndereco(); 
            std::cout << std::endl;
            std::cout << "Telefone: " << diretores[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << diretores[i]->getDesignacao() << std::endl;
            std::cout << "Salario: " << diretores[i]->getSalario() << std::endl << std::endl;
        } else if(tipo == PRESIDENTE) {
            std::cout << "Registro do funcionario de codigo: " << presidente->getCodigo() << std::endl;
            std::cout << "Nome: " << presidente->getNomeFuncionario() << std::endl;
            std::cout << "Data de ingressao: "; 
            presidente->getDataIngresso().exibeData(); 
            std::cout << std::endl;
            std::cout << "Endereco: ";
            presidente->getEndereco().exibeEndereco(); 
            std::cout << std::endl;
            std::cout << "Telefone: " << presidente->getTelefone() << std::endl;
            std::cout << "Designacao: " << presidente->getDesignacao() << std::endl;
            std::cout << "Salario: " << presidente->getSalario() << std::endl << std::endl;
        }
    }
}

void Empresa::concederAumentoSalarial() {
    for(int i = 0; i < 4; i++) {
            for (int j = 0; j < this->qtdFuncionarios[i]; j++) {
                switch (i) {
                case 0:
                    operadores[i]->setSalario((operadores[i]->getTaxaAumento() * operadores[i]->getSalario()) + operadores[i]->getSalario());
                    break;
                case 1:
                    gerentes[i]->setSalario((gerentes[i]->getTaxaAumento() * gerentes[i]->getSalario()) + gerentes[i]->getSalario());
                    break;
                case 2:
                    diretores[i]->setSalario((diretores[i]->getTaxaAumento() * diretores[i]->getSalario()) + diretores[i]->getSalario());
                    break;
                case 3:
                    presidente->setSalario((presidente->getTaxaAumento() * presidente->getSalario()) + presidente->getSalario());
                    break;
                }
            }
        }

    std::cout << "Aumento concedido a todos os funcionarios." << std::endl;
}

void Empresa::calcularFolhaSalarial(int mes) {
    if (getFolhaSalarial(mes - 1) != -1) {
        std::cout << "A folha salarial desse mes ja foi calculada anteriormente" << std::endl;
    } else {
        double valorTotal = 0;

        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < this->qtdFuncionarios[i]; j++) {
                switch (i) {
                case 0:
                    valorTotal += this->operadores[j]->calcularSalarioMensal();
                    break;
                case 1:
                    valorTotal += this->gerentes[j]->calcularSalarioMensal();
                    break;
                case 2:
                    valorTotal += this->diretores[j]->calcularSalarioMensal();
                    break;
                case 3:
                    valorTotal += this->presidente->calcularSalarioMensal();
                    break;
                }
            }
        }

        setFolhaSalarial(mes, valorTotal);
        std::cout << "A folha salarial foi calculada com sucesso" << std::endl;
    }
}

template<typename info>
void Empresa::imprimirFolhaSalarialFuncionario(const info informacao, int tipoInformacao, int tipoFuncionario) {
    Funcionario *funcionario = buscarFuncionario(informacao, tipoInformacao, tipoFuncionario);

    std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " ///// Codigo: " << funcionario->getCodigo() << std::endl;
    std::cout << "Salario base: " << funcionario->getSalario();
    std::cout << "Descontos: " << funcionario->getDescontosSalario();
    std::cout << "Salario liquido: " << (funcionario->getSalario() - funcionario->getDescontosSalario()) << std::endl << std::endl;
}

void Empresa::imprimirFolhaSalarialEmpresa(int opcao) {
    if (opcao == 1) {
        double valorTotal = 0;

        for(int meses = 0; meses < 12; meses++) {
            double valorTotal = 0;

            for(int i = 0; i < 4; i++) {
                for (int j = 0; j < this->qtdFuncionarios[i]; j++) {
                    switch (i) {
                    case 0:
                        valorTotal += this->operadores[j]->calcularSalarioMensal();
                        break;
                    case 1:
                        valorTotal += this->gerentes[j]->calcularSalarioMensal();
                        break;
                    case 2:
                        valorTotal += this->diretores[j]->calcularSalarioMensal();
                        break;
                    case 3:
                        valorTotal += this->presidente->calcularSalarioMensal();
                        break;
                    }
                }
            }
        }

        std::cout << getNome() << " ///// " << getCNPJ() << std::endl;
        std::cout << "A folha salarial para o ano eh: " << valorTotal << std::endl;
    } else if(opcao == 2) {
        int mes;

        std::cout << "Para qual mes deseja imprimir a folha salarial (Digite o numero do mes):" << std::endl;
        std::cin >> mes;

        double valorTotal;

        valorTotal = getFolhaSalarial(mes);

        std::cout << getNome() << " ///// " << getCNPJ() << std::endl;
        std::cout << "A folha salarial para o mes solicitado eh: " << valorTotal << std::endl;
    }
}

template<typename info>
Funcionario* Empresa::buscarFuncionario(const info informacao, int opcao, int tipo) {
    for (int i = 0; i < this->qtdFuncionarios[tipo]; i++) {
        if(tipo == OPERADOR) {
            switch (opcao) {
            case 5:
                if (this->operadores->getNome().find(informacao) != std::string::npos) return operadores;
                break;
            case 6:
                if (this->operadores->getEndereco().comparaEndereco(informacao) != std::string::npos) return operadores;
                break;
            case 7:
                if (this->operadores->getDataDeInsercao().comparaDatas(informacao)) return operadores;
                break;
            case 8:
                if (this->operadores->getCodigo() == informacao) return operadores;
                break;
            }
        } else if(tipo == GERENTE) {
            switch (opcao) {
            case 5:
                if (this->gerentes->getNome().find(informacao) != std::string::npos) return gerentes;
                break;
            case 6:
                if (this->gerentes->getEndereco().comparaEndereco(informacao) != std::string::npos) return gerentes;
                break;
            case 7:
                if (this->gerentes->getDataDeInsercao().comparaDatas(informacao)) return gerentes;
                break;
            case 8:
                if (this->gerentes->getCodigo() == informacao) return gerentes;
                break;
            }
        } else if(tipo == DIRETOR) {
            switch (opcao) {
            case 5:
                if (this->diretores->getNome().find(informacao) != std::string::npos) return diretores;
                break;
            case 6:
                if (this->diretores->getEndereco().comparaEndereco(informacao) != std::string::npos) return diretores;
                break;
            case 7:
                if (this->diretores->getDataDeInsercao().comparaDatas(informacao)) return diretores;
                break;
            case 8:
                if (this->diretores->getCodigo() == informacao) return diretores;
                break;
            }
        } else if(tipo == PRESIDENTE) {
            switch (opcao) {
            case 5:
                if (this->presidente->getNome().find(informacao) != std::string::npos) return presidente;
                break;
            case 6:
                if (this->presidente->getEndereco().comparaEndereco(informacao) != std::string::npos) return presidente;
                break;
            case 7:
                if (this->presidente->getDataDeInsercao().comparaDatas(informacao)) return presidente;
                break;
            case 8:
                if (this->presidente->getCodigo() == informacao) return presidente;
                break;
            }
        }
    }

    return nullptr;
}
