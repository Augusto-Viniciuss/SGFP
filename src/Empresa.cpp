#include "Empresa.h"

Empresa::Empresa(){}

Empresa::Empresa(std::string nome, std::string CNPJ, int *dataEmInt) {
    setNome(nome);
    setCNPJ(CNPJ);
    setDataFundacao(dataEmInt);
    this->qtdFuncionarios[4] = {0};
}

void Empresa::setNome(std::string nome) {
    this->nome = nome;
}

void Empresa::setCNPJ(std::string CNPJ) {
    this->CNPJ = CNPJ;
}

void Empresa::setDataFundacao(int *data) {
    this->dataFundacao =  Data(data[0], data[1], data[2]);
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

void Empresa::addFuncionario(Funcionario *funcionario, int tipoFuncionario) {
    Funcionario *func = buscarFuncionario(funcionario->getNome(), BUSCAR_POR_NOME);

    if(!(func != nullptr)) {
        throw FuncionarioJaCadastradoExcept();
    }

    switch (tipoFuncionario) {
    case 0:
        operadores.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
        break;
    case 1:
        gerentes.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
        break; 
    case 2:
        diretores.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
        break;
    case 3:
        presidente = funcionario;
        qtdFuncionarios[tipoFuncionario] += 1;
        break;
    }
    dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getCodigo()); // Adiciona ele aos arquivos

}

void Empresa::modificarFuncionario(int codigo, int opcao, std::string valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 3:
            funcionario->setNome(valor);
            break;
        case 4:
            funcionario->setEndereco(valor);
            break;
        case 5:
            funcionario->setTelefone(valor);
            break;
        case 8:
            funcionario->setCPF(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::modificarFuncionario(int codigo, int opcao, int *valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 2:
            funcionario->setDataIngresso(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::modificarFuncionario(int codigo, int opcao, int valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 1:
            funcionario->setCodigoFuncionario(valor);
            break;
        case 6:
            funcionario->setDesignacao(valor);
            break;
        case 7:
            funcionario->setIdade(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::excluirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario == nullptr) {
        throw FuncionarioNaoEstaCadastradoExcept();
    } else {
        delete funcionario;
        std::cout << "Funcionario excluido dos registros." << std::endl;
    }
}

void Empresa::exibirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {
        std::cout << "Registro do funcionario de codigo: " << funcionario->getCodigo() << std::endl;
        std::cout << "Nome: " << funcionario->getNome() << std::endl;
        std::cout << "CPF: " << funcionario->getCPF() << std::endl;
        std::cout << "Idade: " << funcionario->getIdade() << std::endl;
       // std::cout << "Data de ingressao: " << funcionario->getDataIngresso() << std::endl; 
        std::cout << "Endereco: " << funcionario->getEndereco_toString() << std::endl;
        std::cout << "Telefone: " << funcionario->getTelefone() << std::endl;
        std::cout << "Designacao: " << funcionario->getDesignacaoStr() << std::endl;
        
        switch (funcionario->getDesignacaoInt()) {
        case 1:
            std::cout << "Area de supervisao: " << ((Gerente*)funcionario)->getAreaSupervisao() << std::endl;
            break;
        case 2:
            {
                std::cout << "Area de supervisao: " << ((Diretor*)funcionario)->getAreaSupervisao() << std::endl;
                std::cout << "Area de formacao: " << ((Diretor*)funcionario)->getAreaFormacao() << std::endl;
            }
            break;
        case 3:
            {
                std::cout << "Area de formacao: " << ((Presidente*)funcionario)->getAreaFormacao() << std::endl;
                std::cout << "Formacao maxima: " << ((Presidente*)funcionario)->getFormacaoMax() << std::endl;
            }
            break;
        }

        std::cout << "Salario: " << funcionario->getSalarioBase() << std::endl;
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::exibirTodosFuncionarios() {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigo() << std::endl;
                std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
                std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
                std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
                //std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso() << std::endl;
                std::cout << "Endereco: " << operadores[i]->getEndereco_toString() << std::endl;
                std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
                std::cout << "Salario: " << operadores[i]->getSalarioBase() << std::endl << std::endl;
            } else if(tipoFuncionario == GERENTE) {
                std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigo() << std::endl;
                std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
                std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
                std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
                //std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso() << std::endl;
                std::cout << "Endereco: " << gerentes[i]->getEndereco_toString() << std::endl;
                std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
                std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;
                std::cout << "Salario: " << gerentes[i]->getSalarioBase() << std::endl << std::endl;
            } else if (tipoFuncionario == DIRETOR) {
                std::cout << "Registro do funcionario de codigo: " << diretores[i]->getCodigo() << std::endl;
                std::cout << "Nome: " << diretores[i]->getNome() << std::endl;
                std::cout << "CPF: " << diretores[i]->getCPF() << std::endl;
                std::cout << "Idade: " << diretores[i]->getIdade() << std::endl;
                //std::cout << "Data de ingressao: " << diretores[i]->getDataIngresso() << std::endl;
                std::cout << "Endereco: " << diretores[i]->getEndereco_toString() << std::endl;
                std::cout << "Telefone: " << diretores[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << diretores[i]->getDesignacaoStr() << std::endl;
                std::cout << "Area de supervisao: " << ((Diretor*)diretores[i])->getAreaSupervisao() << std::endl;
                std::cout << "Area de formacao: " << ((Diretor*)diretores[i])->getAreaFormacao() << std::endl;
                std::cout << "Salario: " << diretores[i]->getSalarioBase() << std::endl << std::endl;
            } else if(tipoFuncionario == PRESIDENTE) {
                std::cout << "Registro do funcionario de codigo: " << presidente->getCodigo() << std::endl;
                std::cout << "Nome: " << presidente->getNome() << std::endl;
                std::cout << "CPF: " << presidente->getCPF() << std::endl;
                std::cout << "Idade: " << presidente->getIdade() << std::endl;
                //std::cout << "Data de ingressao: " << presidente->getDataIngresso() << std::endl;
                std::cout << "Endereco: " << presidente->getEndereco_toString() << std::endl;
                std::cout << "Telefone: " << presidente->getTelefone() << std::endl;
                std::cout << "Designacao: " << presidente->getDesignacaoStr() << std::endl;
                std::cout << "Area de formacao: " << ((Presidente*)presidente)->getAreaFormacao() << std::endl;
                std::cout << "Formacao maxima: " << ((Presidente*)presidente)->getFormacaoMax() << std::endl;
                std::cout << "Salario: " << presidente->getSalarioBase() << std::endl << std::endl;
            }
        }
    }
}

void Empresa::exibirFuncionariosPorTipo(int tipoFuncionario) {
    for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
        if(tipoFuncionario == OPERADOR) {
            std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
            std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
            std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
            //std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso() << std::endl;
            std::cout << "Endereco: " << operadores[i]->getEndereco_toString() << std::endl;
            std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
            std::cout << "Salario: " << operadores[i]->getSalarioBase() << std::endl << std::endl;
        } else if(tipoFuncionario == GERENTE) {
            std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
            std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
            std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
            //std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso() << std::endl;
            std::cout << "Endereco: " << gerentes[i]->getEndereco_toString() << std::endl;
            std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
            std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;
            std::cout << "Salario: " << gerentes[i]->getSalarioBase() << std::endl << std::endl;
        } else if (tipoFuncionario == DIRETOR) {
            std::cout << "Registro do funcionario de codigo: " << diretores[i]->getCodigo() << std::endl;
            std::cout << "Nome: " << diretores[i]->getNome() << std::endl;
            std::cout << "CPF: " << diretores[i]->getCPF() << std::endl;
            std::cout << "Idade: " << diretores[i]->getIdade() << std::endl;
            //std::cout << "Data de ingressao: " << diretores[i]->getDataIngresso() << std::endl;
            std::cout << "Endereco: " << diretores[i]->getEndereco_toString() << std::endl;
            std::cout << "Telefone: " << diretores[i]->getTelefone() << std::endl;
            std::cout << "Designacao: " << diretores[i]->getDesignacaoStr() << std::endl;
            std::cout << "Area de supervisao: " << ((Diretor*)diretores[i])->getAreaSupervisao() << std::endl;
            std::cout << "Area de formacao: " << ((Diretor*)diretores[i])->getAreaFormacao() << std::endl;
            std::cout << "Salario: " << diretores[i]->getSalarioBase() << std::endl << std::endl;
        } else if(tipoFuncionario == PRESIDENTE) {
            std::cout << "Registro do funcionario de codigo: " << presidente->getCodigo() << std::endl;
            std::cout << "Nome: " << presidente->getNome() << std::endl;
            std::cout << "CPF: " << presidente->getCPF() << std::endl;
            std::cout << "Idade: " << presidente->getIdade() << std::endl;
            //std::cout << "Data de ingressao: " << presidente->getDataIngresso() << std::endl;
            std::cout << "Endereco: " << presidente->getEndereco_toString() << std::endl;
            std::cout << "Telefone: " << presidente->getTelefone() << std::endl;
            std::cout << "Designacao: " << presidente->getDesignacaoStr() << std::endl;
            std::cout << "Area de formacao: " << ((Presidente*)presidente)->getAreaFormacao() << std::endl;
            std::cout << "Formacao maxima: " << ((Presidente*)presidente)->getFormacaoMax() << std::endl;
            std::cout << "Salario: " << presidente->getSalarioBase() << std::endl << std::endl;
        }
    }
}

void Empresa::concederAumentoSalarial() {
    for(int i = 0; i < 4; i++) {
            for (int j = 0; j < this->qtdFuncionarios[i]; j++) {
                switch (i) {
                case 0:
                    operadores[i]->setSalarioBase((operadores[i]->getTaxaAumento() * operadores[i]->getSalarioBase()) + operadores[i]->getSalarioBase());
                    break;
                case 1:
                    gerentes[i]->setSalarioBase((gerentes[i]->getTaxaAumento() * gerentes[i]->getSalarioBase()) + gerentes[i]->getSalarioBase());
                    break;
                case 2:
                    diretores[i]->setSalarioBase((diretores[i]->getTaxaAumento() * diretores[i]->getSalarioBase()) + diretores[i]->getSalarioBase());
                    break;
                case 3:
                    presidente->setSalarioBase((presidente->getTaxaAumento() * presidente->getSalarioBase()) + presidente->getSalarioBase());
                    break;
                }
            }
        }

    std::cout << "Aumento concedido a todos os funcionarios." << std::endl;
}

void Empresa::calcularFolhaSalarial(int mes) {
    if (this->presidente->getSalarioMensal(mes - 1) != -1) {
        std::cout << "A folha salarial desse mes ja foi calculada anteriormente." << std::endl;
    } else {
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < this->qtdFuncionarios[i]; j++) {
                switch (i) {
                case 0:
                    this->operadores[j]->calcularSalarioMensal(mes);
                    break;
                case 1:
                    this->gerentes[j]->calcularSalarioMensal(mes);
                    break;
                case 2:
                    this->diretores[j]->calcularSalarioMensal(mes);
                    break;
                case 3:
                    this->presidente->calcularSalarioMensal(mes);
                    break;
                }
            }
        }

        std::cout << "A folha salarial foi para o mes solicitado foi calculada com sucesso." << std::endl;
    }
}


void Empresa::imprimirFolhaSalarialFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {
        std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " ///// Codigo: " << funcionario->getCodigo() << std::endl;
        std::cout << "Salario base: " << funcionario->getSalarioBase() << std::endl;
        std::cout << "Salario liquido: " << (funcionario->getSalarioLiquido()) << std::endl;
        std::cout << "Descontos: " << funcionario->getDescontosSalario() << std::endl << std::endl;
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    } 
}

void Empresa::imprimirFolhaSalarialFuncionario(std::string nome) {
    Funcionario *funcionario = buscarFuncionario(nome, BUSCAR_POR_NOME);

    if (funcionario != nullptr) {
        std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " ///// Codigo: " << funcionario->getCodigo() << std::endl;
        std::cout << "Salario base: " << funcionario->getSalarioBase() << std::endl;
        std::cout << "Salario liquido: " << (funcionario->getSalarioLiquido()) << std::endl;
        std::cout << "Descontos: " << funcionario->getDescontosSalario() << std::endl << std::endl;    
    } else {
        std::cout << "Funcionario nao esta cadastrado." << std::endl;
    }
}

void Empresa::imprimirFolhaSalarialEmpresa(int opcao) {
    if (opcao == 1) {
        double valorTotal = 0;

        for(int meses = 0; meses < 12; meses++) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < this->qtdFuncionarios[i]; j++) {
                    if(this->presidente->getSalarioMensal(meses) == -1) {
                        if(i == OPERADOR) {
                            this->operadores[j]->calcularSalarioMensal(meses);

                            valorTotal += operadores[j]->getSalarioMensal(meses);
                        } else if(i == GERENTE) {
                            this->gerentes[j]->calcularSalarioMensal(meses);

                            valorTotal += gerentes[j]->getSalarioMensal(meses);
                        } else if(i == DIRETOR) {
                            this->diretores[j]->calcularSalarioMensal(meses);

                            valorTotal += diretores[j]->getSalarioMensal(meses);
                        } else if(i == PRESIDENTE) {
                            this->presidente->calcularSalarioMensal(meses);

                            valorTotal += presidente->getSalarioMensal(meses);
                        }
                    } else {
                        if(i == OPERADOR) {
                            valorTotal += operadores[j]->getSalarioMensal(meses);
                        } else if(i == GERENTE) {
                            valorTotal += gerentes[j]->getSalarioMensal(meses);
                        } else if(i == DIRETOR) {
                            valorTotal += diretores[j]->getSalarioMensal(meses);
                        } else if(i == PRESIDENTE) {
                            valorTotal += presidente->getSalarioMensal(meses);
                        }
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

        double valorTotal = 0;

        for(int i = 0; i < 4; i++) {
                for(int j = 0; j < this->qtdFuncionarios[i]; j++) {
                    if(i == OPERADOR) {
                        if(operadores[j]->getSalarioMensal(mes) == -1) {
                            this->operadores[j]->calcularSalarioMensal(mes);
                        } 

                        valorTotal += operadores[j]->getSalarioMensal(mes);
                    } else if(i == GERENTE) {
                        if(gerentes[j]->getSalarioMensal(mes) == -1) {
                            this->gerentes[j]->calcularSalarioMensal(mes);
                        } 

                        valorTotal += gerentes[j]->getSalarioMensal(mes);
                    } else if(i == DIRETOR) {
                        if(diretores[j]->getSalarioMensal(mes) == -1) {
                            this->diretores[j]->calcularSalarioMensal(mes);
                        } 

                        valorTotal += diretores[j]->getSalarioMensal(mes);
                    } else if(i == PRESIDENTE) {
                        if(presidente->getSalarioMensal(mes) == -1) {
                            this->presidente->calcularSalarioMensal(mes);
                        } 

                        valorTotal += presidente->getSalarioMensal(mes);
                    }
                }
            }

        std::cout << getNome() << " ///// " << getCNPJ() << std::endl;
        std::cout << "A folha salarial para o mes solicitado eh: " << valorTotal << std::endl;
    }
}

Funcionario* Empresa::buscarFuncionario(int codigo) {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getCodigo() == codigo) return operadores[i];
            } else if(tipoFuncionario == GERENTE) {
                if (this->diretores[i]->getCodigo() == codigo) return diretores[i];
            } else if(tipoFuncionario == DIRETOR) {
                if (this->gerentes[i]->getCodigo() == codigo) return gerentes[i];
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getCodigo() == codigo) return presidente;
            }
        }
    }

    return nullptr;
}

Funcionario* Empresa::buscarFuncionario(int *data) {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getDataIngresso().comparaDatas(data)) return operadores[i];
            } else if(tipoFuncionario == GERENTE) {
                if (this->diretores[i]->getDataIngresso().comparaDatas(data)) return diretores[i];
            } else if(tipoFuncionario == DIRETOR) {
                if (this->gerentes[i]->getDataIngresso().comparaDatas(data)) return gerentes[i];
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getDataIngresso().comparaDatas(data)) return presidente;
            }
        }
    }

    return nullptr;
}

Funcionario* Empresa::buscarFuncionario(std::string informacao, int opcao) {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                switch (opcao) {
                case 5:
                    if (this->operadores[i]->getNome().find(informacao) != std::string::npos) return operadores[i];
                    break;
                case 6:
                    if (this->operadores[i]->getEndereco().comparaEndereco(informacao) != std::string::npos) return operadores[i];
                    break;
                }
            } else if(tipoFuncionario == GERENTE) {
                switch (opcao) {
                case 5:
                    if (this->gerentes[i]->getNome().find(informacao) != std::string::npos) return gerentes[i];
                    break;
                case 6:
                    if (this->gerentes[i]->getEndereco().comparaEndereco(informacao) != std::string::npos) return gerentes[i];
                    break;
                }
            } else if(tipoFuncionario == DIRETOR) {
                switch (opcao) {
                case 5:
                    if (this->diretores[i]->getNome().find(informacao) != std::string::npos) return diretores[i];
                    break;
                case 6:
                    if (this->diretores[i]->getEndereco().comparaEndereco(informacao) != std::string::npos) return diretores[i];
                    break;
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                switch (opcao) {
                case 5:
                    if (this->presidente->getNome().find(informacao) != std::string::npos) return presidente;
                    break;
                case 6:
                    if (this->presidente->getEndereco().comparaEndereco(informacao) != std::string::npos) return presidente;
                    break;
                }
            }
        }
    }

    return nullptr;
}
