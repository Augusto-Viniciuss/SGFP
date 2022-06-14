#include "Empresa.h"

Empresa::Empresa() {}

int Empresa::getQtdFuncionarios(int tipo) {
    return this->qtdFuncionarios[tipo];
}

void Empresa::addFuncionario(Funcionario *funcionario, int tipoFuncionario) {
    Funcionario *func = buscarFuncionario(funcionario->getCodigoFuncionario());

    if(func != nullptr) {
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

    dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::modificarFuncionario(int codigo, int opcao, std::string valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 4:
            funcionario->setNome(valor);
            break;
        case 5:
            funcionario->getEndereco()->setEndereco(valor);
            break;
        case 6:
            funcionario->setTelefone(valor);
            break;
        case 7:
            funcionario->setCPF(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
    //dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::modificarFuncionario(int codigo, int *valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        funcionario->setDataIngresso(valor);
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }

    //dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::modificarFuncionario(int codigo, int opcao, int valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 2:
            funcionario->setDesignacao(valor);
            break;
        case 1:
            funcionario->setIdade(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
    //dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::excluirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    // Colocado antes por conta do throw
    //dadosArquivos.excluiDados(funcionario->getDesignacaoInt(), funcionario->getCodigoFuncionario());

    if (funcionario == nullptr) {
        throw FuncionarioNaoEstaCadastradoExcept();
    } else {
        delete funcionario;
        funcionario = nullptr;
        std::cout << "Funcionario excluido dos registros." << std::endl;
    }
}

void Empresa::exibirFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "Registro do funcionario de codigo: " << funcionario->getCodigoFuncionario() << std::endl;
        std::cout << "Nome: " << funcionario->getNome() << std::endl;
        std::cout << "CPF: " << funcionario->getCPF() << std::endl;
        std::cout << "Idade: " << funcionario->getIdade() << std::endl;
        std::cout << "Data de ingressao: " << funcionario->getDataIngresso().retornaStringData() << std::endl; 
        std::cout << "Endereco: " << funcionario->getEndereco()->getInformacao() << std::endl;
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
        std::cout << std::endl << "*******************************************************************" << std::endl;
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::exibirTodosFuncionarios() {
    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
    
    if((this->qtdFuncionarios[0] == 0) and (this->qtdFuncionarios[1] == 0) and (this->qtdFuncionarios[2] == 0) and (this->qtdFuncionarios[3] == 0)) {
        std::cout << "Nao existem funcionarios cadastrados" << std::endl;
    } else {
        for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
            for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
                if(tipoFuncionario == OPERADOR) {
                    std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
                    std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
                    std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << operadores[i]->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
                    std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                } else if(tipoFuncionario == GERENTE) {
                    std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
                    std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
                    std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << gerentes[i]->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
                    std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
                    std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;             
                } else if (tipoFuncionario == DIRETOR) {
                    std::cout << "Registro do funcionario de codigo: " << diretores[i]->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << diretores[i]->getNome() << std::endl;
                    std::cout << "CPF: " << diretores[i]->getCPF() << std::endl;
                    std::cout << "Idade: " << diretores[i]->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << diretores[i]->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << diretores[i]->getTelefone() << std::endl;
                    std::cout << "Designacao: " << diretores[i]->getDesignacaoStr() << std::endl;
                    std::cout << "Area de supervisao: " << ((Diretor*)diretores[i])->getAreaSupervisao() << std::endl;
                    std::cout << "Area de formacao: " << ((Diretor*)diretores[i])->getAreaFormacao() << std::endl;
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;             
                } else if(tipoFuncionario == PRESIDENTE) {
                    std::cout << "Registro do funcionario de codigo: " << presidente->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << presidente->getNome() << std::endl;
                    std::cout << "CPF: " << presidente->getCPF() << std::endl;
                    std::cout << "Idade: " << presidente->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << presidente->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << presidente->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << presidente->getTelefone() << std::endl;
                    std::cout << "Designacao: " << presidente->getDesignacaoStr() << std::endl;
                    std::cout << "Area de formacao: " << ((Presidente*)presidente)->getAreaFormacao() << std::endl;
                    std::cout << "Formacao maxima: " << ((Presidente*)presidente)->getFormacaoMax() << std::endl;
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;             
                }
            }
        }
    }
}

void Empresa::exibirFuncionariosPorTipo(int tipoFuncionario) {
    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
    
    if(this->qtdFuncionarios[tipoFuncionario] == 0) {
        std::cout << "Nao existe nenhum funcionario desse tipo cadastrado." << std::endl;
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
    } else {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
                std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
                std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << operadores[i]->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            } else if(tipoFuncionario == GERENTE) {
                std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
                std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
                std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << gerentes[i]->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
                std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            } else if (tipoFuncionario == DIRETOR) {
                std::cout << "Registro do funcionario de codigo: " << diretores[i]->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << diretores[i]->getNome() << std::endl;
                std::cout << "CPF: " << diretores[i]->getCPF() << std::endl;
                std::cout << "Idade: " << diretores[i]->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << diretores[i]->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << diretores[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << diretores[i]->getDesignacaoStr() << std::endl;
                std::cout << "Area de supervisao: " << ((Diretor*)diretores[i])->getAreaSupervisao() << std::endl;
                std::cout << "Area de formacao: " << ((Diretor*)diretores[i])->getAreaFormacao() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            } else if(tipoFuncionario == PRESIDENTE) {
                std::cout << "Registro do funcionario de codigo: " << presidente->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << presidente->getNome() << std::endl;
                std::cout << "CPF: " << presidente->getCPF() << std::endl;
                std::cout << "Idade: " << presidente->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << presidente->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << presidente->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << presidente->getTelefone() << std::endl;
                std::cout << "Designacao: " << presidente->getDesignacaoStr() << std::endl;
                std::cout << "Area de formacao: " << ((Presidente*)presidente)->getAreaFormacao() << std::endl;
                std::cout << "Formacao maxima: " << ((Presidente*)presidente)->getFormacaoMax() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            }
        }
    }
    
}

void Empresa::concederAumentoSalarial() {
    for(int meses = 1; meses < 13; meses++) {
        for(int tipoFuncionarios = 0; tipoFuncionarios < 4; tipoFuncionarios++) {
            for (int i = 0; i < this->qtdFuncionarios[tipoFuncionarios]; i++) {
                if(presidente->getFolhaSalarial(meses).getSalarioLiquido() == 0) {
                    if(tipoFuncionarios == OPERADOR) {
                        operadores[i]->getFolhaSalarial(meses).aumentarSalarioBase();
                    } else if(tipoFuncionarios == GERENTE) {
                        gerentes[i]->getFolhaSalarial(meses).aumentarSalarioBase();
                    } else if(tipoFuncionarios == DIRETOR) {
                        diretores[i]->getFolhaSalarial(meses).aumentarSalarioBase();
                    } else if(tipoFuncionarios == PRESIDENTE) {
                        presidente->getFolhaSalarial(meses).aumentarSalarioBase();
                    }
                } 
            }
        }
    }
    
    std::cout << "Aumento concedido a todos os funcionarios." << std::endl;
    
}

void Empresa::calcularFolhaSalarial(int mes) {
    if (this->presidente->getFolhaSalarial(mes - 1).getSalarioLiquido() != 0) {
        std::cout << "A folha salarial desse mes ja foi calculada anteriormente." << std::endl;
    } else {
        for(int tipoFuncionario = 0; tipoFuncionario < 4; tipoFuncionario++) {
            for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
                switch (tipoFuncionario) {
                case 0:
                    this->operadores[i]->calcularSalarioMensal(mes - 1);
                    break;
                case 1:
                    this->gerentes[i]->calcularSalarioMensal(mes - 1);
                    break;
                case 2:
                    this->diretores[i]->calcularSalarioMensal(mes - 1);
                    break;
                case 3:
                    this->presidente->calcularSalarioMensal(mes - 1);
                    break;
                }
            }
        }

        std::cout << "A folha salarial para o mes solicitado foi calculada com sucesso." << std::endl;
    }
}


void Empresa::imprimirFolhaSalarialFuncionario(int codigo) {
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {

        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " //////// Codigo: " << funcionario->getCodigoFuncionario() << std::endl;

        for(int meses = 1; meses < 13; meses++) {
            if(funcionario->getFolhaSalarial(meses).getSalarioLiquido() != 0) {
                std::cout << "Mes: " << (meses + 1) << std::endl;
                std::cout << "Salario base: R$ " << funcionario->getFolhaSalarial(meses).getSalarioBase() << std::endl;
                std::cout << "Salario liquido: R$ " << (funcionario->getFolhaSalarial(meses).getSalarioLiquido()) << std::endl;
                std::cout << "Descontos imposto de rensa: R$ " << funcionario->getFolhaSalarial(meses).getDescontoImpostoRenda() << std::endl;
                std::cout << "Descontos previdencia social: R$ " << funcionario->getFolhaSalarial(meses).getDescontoPrevidencia() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            }
        }   
        
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::imprimirFolhaSalarialFuncionario(std::string nome) {
    Funcionario *funcionario = buscarFuncionario(nome, BUSCAR_POR_NOME);

    if (funcionario != nullptr) {

        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "Folha Salarial do Funcionario: " << funcionario->getNome() << " //////// Codigo: " << funcionario->getCodigoFuncionario() << std::endl;

        for(int meses = 1; meses < 13; meses++) {
            if(funcionario->getFolhaSalarial(meses).getSalarioLiquido() != 0) {
                std::cout << "Mes: " << (meses + 1) << std::endl;
                std::cout << "Salario base: R$ " << funcionario->getFolhaSalarial(meses).getSalarioBase() << std::endl;
                std::cout << "Salario liquido: R$ " << (funcionario->getFolhaSalarial(meses).getSalarioLiquido()) << std::endl;
                std::cout << "Descontos imposto de rensa: R$ " << funcionario->getFolhaSalarial(meses).getDescontoImpostoRenda() << std::endl;
                std::cout << "Descontos previdencia social: R$ " << funcionario->getFolhaSalarial(meses).getDescontoPrevidencia() << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;   
            }
        }   
        
    } else {
        throw FuncionarioNaoEstaCadastradoExcept();
    }
}

void Empresa::imprimirFolhaSalarialEmpresa(int opcao) {
    if (opcao == 1) {
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "A folha salarial da empresa para os meses do ano calculados até agora eh: " << std::endl;

        for(int meses = 1; meses < 13; meses++) {

            double salarioTotalLiquido, salarioTotalBase, descontoPrevidencia, descontoImpostoRenda = 0;

            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < this->qtdFuncionarios[i]; j++) {
                    if(this->presidente->getFolhaSalarial(meses).getSalarioBase() != 0) {
                        if(i == OPERADOR) {
                            salarioTotalBase += operadores[j]->getFolhaSalarial(meses).getSalarioBase();
                            salarioTotalLiquido += operadores[j]->getFolhaSalarial(meses).getSalarioLiquido();
                            descontoPrevidencia += operadores[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                            descontoImpostoRenda += operadores[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                        } else if(i == GERENTE) {
                            salarioTotalBase += gerentes[j]->getFolhaSalarial(meses).getSalarioBase();
                            salarioTotalLiquido += gerentes[j]->getFolhaSalarial(meses).getSalarioLiquido();
                            descontoPrevidencia += gerentes[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                            descontoImpostoRenda += gerentes[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                        } else if(i == DIRETOR) {
                            this->diretores[j]->calcularSalarioMensal(meses);

                            salarioTotalBase += diretores[j]->getFolhaSalarial(meses).getSalarioBase();
                            salarioTotalLiquido += diretores[j]->getFolhaSalarial(meses).getSalarioLiquido();
                            descontoPrevidencia += diretores[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                            descontoImpostoRenda += diretores[j]->getFolhaSalarial(meses).getDescontoPrevidencia();
                        } else if(i == PRESIDENTE) {
                            salarioTotalBase += presidente->getFolhaSalarial(meses).getSalarioBase();
                            salarioTotalLiquido += presidente->getFolhaSalarial(meses).getSalarioLiquido();
                            descontoPrevidencia += presidente->getFolhaSalarial(meses).getDescontoPrevidencia();
                            descontoImpostoRenda += presidente->getFolhaSalarial(meses).getDescontoPrevidencia();
                        }
                    }
                }
            }

            if(salarioTotalBase == 0) {
                std::cout << "Mes: " << (meses + 1) << std::endl; 
                std::cout << "Salario base:" << salarioTotalBase << std::endl;
                std::cout << "Salario Liquido:" << salarioTotalLiquido << std::endl;
                std::cout << "Descontos do imposto de renda:" << descontoImpostoRenda << std::endl;
                std::cout << "Descontos da previdencia social:" << descontoPrevidencia << std::endl;
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;    
            }
        } 
    } else if(opcao == 2) {
        int mes;

        std::cout << "Para qual mes deseja imprimir a folha salarial (Digite o numero do mes):" << std::endl;
        std::cin >> mes;

        double salarioTotalLiquido, salarioTotalBase, descontoPrevidencia, descontoImpostoRenda = 0;

        if(this->presidente->getFolhaSalarial(mes - 1).getSalarioBase() != 0) {
            
            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;

            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < this->qtdFuncionarios[i]; j++) {
                    if(i == OPERADOR) {
                        salarioTotalBase += operadores[j]->getFolhaSalarial(mes - 1).getSalarioBase();
                        salarioTotalLiquido += operadores[j]->getFolhaSalarial(mes - 1).getSalarioLiquido();
                        descontoPrevidencia += operadores[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                        descontoImpostoRenda += operadores[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                    } else if(i == GERENTE) {
                        salarioTotalBase += gerentes[j]->getFolhaSalarial(mes - 1).getSalarioBase();
                        salarioTotalLiquido += gerentes[j]->getFolhaSalarial(mes - 1).getSalarioLiquido();
                        descontoPrevidencia += gerentes[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                        descontoImpostoRenda += gerentes[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                    } else if(i == DIRETOR) {
                        salarioTotalBase += diretores[j]->getFolhaSalarial(mes - 1).getSalarioBase();
                        salarioTotalLiquido += diretores[j]->getFolhaSalarial(mes - 1).getSalarioLiquido();
                        descontoPrevidencia += diretores[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                        descontoImpostoRenda += diretores[j]->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                    } else if(i == PRESIDENTE) {
                        salarioTotalBase += presidente->getFolhaSalarial(mes - 1).getSalarioBase();
                        salarioTotalLiquido += presidente->getFolhaSalarial(mes - 1).getSalarioLiquido();
                        descontoPrevidencia += presidente->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                        descontoImpostoRenda += presidente->getFolhaSalarial(mes - 1).getDescontoPrevidencia();
                    }      
                }
            }  
        } else {
            
        }

        std::cout << "A folha salarial da empresa para o mes digitado eh: " << std::endl;
        std::cout << "Salario base:" << salarioTotalBase << std::endl;
        std::cout << "Salario Liquido:" << salarioTotalLiquido << std::endl;
        std::cout << "Descontos do imposto de renda:" << descontoImpostoRenda << std::endl;
        std::cout << "Descontos da previdencia social:" << descontoPrevidencia << std::endl;
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;   
    }
}

Funcionario* Empresa::buscarFuncionario(int codigo) {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getCodigoFuncionario() == codigo) return operadores[i];
            } else if(tipoFuncionario == GERENTE) {
                if (this->gerentes[i]->getCodigoFuncionario() == codigo) return gerentes[i];
            } else if(tipoFuncionario == DIRETOR) {
                if (this->diretores[i]->getCodigoFuncionario() == codigo) return diretores[i];
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getCodigoFuncionario() == codigo) return presidente;
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
                if (this->gerentes[i]->getDataIngresso().comparaDatas(data)) return gerentes[i];
            } else if(tipoFuncionario == DIRETOR) {
                if (this->diretores[i]->getDataIngresso().comparaDatas(data)) return diretores[i];
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
                    if (this->operadores[i]->getEndereco()->comparaEndereco(informacao)) return operadores[i];
                    break;
                }
            } else if(tipoFuncionario == GERENTE) {
                switch (opcao) {
                case 5:
                    if (this->gerentes[i]->getNome().find(informacao) != std::string::npos) return gerentes[i];
                    break;
                case 6:
                    if (this->gerentes[i]->getEndereco()->comparaEndereco(informacao)) return gerentes[i];
                    break;
                }
            } else if(tipoFuncionario == DIRETOR) {
                switch (opcao) {
                case 5:
                    if (this->diretores[i]->getNome().find(informacao) != std::string::npos) return diretores[i];
                    break;
                case 6:
                    if (this->diretores[i]->getEndereco()->comparaEndereco(informacao)) return diretores[i];
                    break;
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                switch (opcao) {
                case 5:
                    if (this->presidente->getNome().find(informacao) != std::string::npos) return presidente;
                    break;
                case 6:
                    if (this->presidente->getEndereco()->comparaEndereco(informacao)) return presidente;
                    break;
                }
            }
        }
    }

    return nullptr;
}


Empresa::~Empresa() {
    dadosArquivos.criaArquivoCsv(operadores);
    dadosArquivos.criaArquivoCsv(diretores);
    dadosArquivos.criaArquivoCsv(gerentes);
    dadosArquivos.adicionaArquivoCsv(presidente);
}
