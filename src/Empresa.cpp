#include "Empresa.h"

Empresa::Empresa() {
    dadosArquivos.carregaDados(operadores, OPERADOR);
    qtdFuncionarios[OPERADOR] = operadores.size();
    dadosArquivos.carregaDados(gerentes, GERENTE);
    qtdFuncionarios[GERENTE] = gerentes.size();
    dadosArquivos.carregaDados(diretores, DIRETOR);
    qtdFuncionarios[DIRETOR] = diretores.size();
    
    
    presidente = dadosArquivos.carregaPresidente();
    
    if(presidente != nullptr) {
        qtdFuncionarios[PRESIDENTE] = 1;
    }
}

Empresa::~Empresa() {


    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        
        for(int i = 0; i < qtdFuncionarios[tipoFuncionario]; i++) {

            if(tipoFuncionario == OPERADOR) {
                dadosArquivos.salvarDadosFuncionario(operadores[i], operadores[i]->getDesignacaoInt());
            }
            if(tipoFuncionario == GERENTE) {
                dadosArquivos.salvarDadosFuncionario(gerentes[i], gerentes[i]->getDesignacaoInt());
            }
            if(tipoFuncionario == DIRETOR) {
                dadosArquivos.salvarDadosFuncionario(diretores[i], diretores[i]->getDesignacaoInt());
            }
            if(tipoFuncionario == PRESIDENTE) {
                dadosArquivos.salvarDadosFuncionario(presidente, presidente->getDesignacaoInt());
            }
        }
        
        
    } 
    dadosArquivos.criaArquivoCsv(operadores);
    dadosArquivos.criaArquivoCsv(diretores);
    dadosArquivos.criaArquivoCsv(gerentes);

    if(qtdFuncionarios[PRESIDENTE] != 0) {
        dadosArquivos.adicionaArquivoCsv(presidente);
    } 
}

int Empresa::getQtdFuncionarios(int tipo) {
    return this->qtdFuncionarios[tipo];
}

void Empresa::addFuncionario(Funcionario *funcionario, int tipoFuncionario) {
    Funcionario *func = buscarFuncionario(funcionario->getCodigoFuncionario());

    if(func != nullptr) {
        throw FuncionarioJaCadastradoExcept("Funcionario já está cadastrado");
    } else if(tipoFuncionario == OPERADOR) {
        operadores.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
    } else if(tipoFuncionario == GERENTE) {
        gerentes.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
    } else if(tipoFuncionario == DIRETOR) {
        diretores.push_back(funcionario);
        qtdFuncionarios[tipoFuncionario] += 1;
    } else if(tipoFuncionario == PRESIDENTE) {
        if(qtdFuncionarios[tipoFuncionario] == 0) {
            presidente = funcionario;
            qtdFuncionarios[tipoFuncionario] += 1;
        } else{
            std::cout << "Presidente já foi cadastrado" << std::endl;
        }
    }
    std::cout << funcionario << std::endl;
    //dadosArquivos.salvarDadosFuncionario(funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos  
}

void Empresa::modificarFuncionario(int codigo, int opcao, std::string valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        switch (opcao) {
        case 4:
            funcionario->setNome(valor);
            break;
        case 5:
            funcionario->setEndereco(valor);
            break;
        case 6:
            funcionario->setTelefone(valor);
            break;
        case 7:
            funcionario->setCPF(valor);
            break;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
    }
    //dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::modificarFuncionario(int codigo, int *valor) {
    Funcionario *funcionario = buscarFuncionario(codigo);
    
    if (funcionario != nullptr) {
        funcionario->setDataIngresso(valor);
    } else {
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
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
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
    }
    //dadosArquivos.salvarDadosFuncionario(*funcionario, funcionario->getDesignacaoInt()); // Adiciona ele aos arquivos
}

void Empresa::excluirFuncionario(int codigo) {
    int indice, tipoFuncionario;
    int *p = &indice;
    int *t = &tipoFuncionario;
    Funcionario *funcionario = buscarFuncionario(codigo, p, t);
   
    p = t = nullptr;
   
    
    if (funcionario == nullptr) {
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
    } 
    std::cout << "estou aqui" << std::endl;
   
    dadosArquivos.excluiDados(funcionario);

   
    if(tipoFuncionario == 0) {
        this->operadores.erase(operadores.begin() + indice);
        qtdFuncionarios[tipoFuncionario] -= 1;
    } else if(tipoFuncionario == 1) {
        this->gerentes.erase(gerentes.begin() + indice);
        qtdFuncionarios[tipoFuncionario] -= 1;
    } else if(tipoFuncionario == 2) {
        this->diretores.erase(diretores.begin() + indice);
        qtdFuncionarios[tipoFuncionario] -= 1;
    } else if(tipoFuncionario == 3) {
        qtdFuncionarios[tipoFuncionario] -= 1;
    }
    delete funcionario;
   
    std::cout << "Funcionario excluido dos registros." << std::endl;
    
    
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
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
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
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                    std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
                    std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
                    std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << operadores[i]->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
                    std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
                } else if(tipoFuncionario == GERENTE) {
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                    std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigoFuncionario() << std::endl;
                    std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
                    std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
                    std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
                    std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << gerentes[i]->getEndereco()->getInformacao() << std::endl;
                    std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
                    std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
                    std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;            
                } else if (tipoFuncionario == DIRETOR) {
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
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
                } else if(tipoFuncionario == PRESIDENTE) {
                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
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
                }
            }
        }
    }
}

void Empresa::exibirFuncionariosPorTipo(int tipoFuncionario) {
    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
    
    if(this->qtdFuncionarios[tipoFuncionario] == 0) {
        std::cout << "Nao existe nenhum funcionario desse tipo cadastrado." << std::endl;
    } else {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                std::cout << "Registro do funcionario de codigo: " << this->operadores[i]->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << operadores[i]->getNome() << std::endl;
                std::cout << "CPF: " << operadores[i]->getCPF() << std::endl;
                std::cout << "Idade: " << operadores[i]->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << operadores[i]->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << operadores[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << operadores[i]->getDesignacaoStr() << std::endl;
            } else if(tipoFuncionario == GERENTE) {
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                std::cout << "Registro do funcionario de codigo: " << gerentes[i]->getCodigoFuncionario() << std::endl;
                std::cout << "Nome: " << gerentes[i]->getNome() << std::endl;
                std::cout << "CPF: " << gerentes[i]->getCPF() << std::endl;
                std::cout << "Idade: " << gerentes[i]->getIdade() << std::endl;
                std::cout << "Data de ingressao: " << gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                std::cout << "Endereco: " << gerentes[i]->getEndereco()->getInformacao() << std::endl;
                std::cout << "Telefone: " << gerentes[i]->getTelefone() << std::endl;
                std::cout << "Designacao: " << gerentes[i]->getDesignacaoStr() << std::endl;
                std::cout << "Area de supervisao: " << ((Gerente*)gerentes[i])->getAreaSupervisao() << std::endl;
            } else if (tipoFuncionario == DIRETOR) {
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
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
            } else if(tipoFuncionario == PRESIDENTE) {
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
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
            }
        }
    }
    
}

void Empresa::concederAumentoSalarial() {
    for(int meses = 1; meses < 13; meses++) {
        for(int tipoFuncionario = 0; tipoFuncionario < 4; tipoFuncionario++) {
            for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
                if(tipoFuncionario == OPERADOR) {
                    if(this->operadores[i]->getFolhaSalarial(meses)->getSalarioLiquido() == 0) {
                        this->operadores[i]->getFolhaSalarial(meses)->aumentarSalarioBase();
                    }
                } else if(tipoFuncionario == GERENTE) {
                    if(this->gerentes[i]->getFolhaSalarial(meses)->getSalarioLiquido() == 0) {
                        this->gerentes[i]->getFolhaSalarial(meses)->aumentarSalarioBase();
                    }
                } else if(tipoFuncionario == DIRETOR) {
                    if(this->diretores[i]->getFolhaSalarial(meses)->getSalarioLiquido() == 0) {
                        this->diretores[i]->getFolhaSalarial(meses)->aumentarSalarioBase();
                    }
                } else if(tipoFuncionario == PRESIDENTE) {
                    if(this->presidente->getFolhaSalarial(meses)->getSalarioLiquido() == 0) {
                        this->presidente->getFolhaSalarial(meses)->aumentarSalarioBase();
                    }
                }
            }
        }
    }
    std::cout << "Aumento concedido a todos os funcionarios." << std::endl;
}

void Empresa::calcularFolhaSalarial(int mes) {
    for(int tipoFuncionario = 0; tipoFuncionario < 4; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if(this->operadores[i]->getFolhaSalarial(mes)->getSalarioLiquido() == 0) {
                    this->operadores[i]->calcularSalarioMensal(mes);
                    
                }
            } else if(tipoFuncionario == GERENTE) {
                if(this->gerentes[i]->getFolhaSalarial(mes)->getSalarioLiquido() == 0) {
                    this->gerentes[i]->calcularSalarioMensal(mes);
                    
                }
            } else if(tipoFuncionario == DIRETOR) {
                if(this->diretores[i]->getFolhaSalarial(mes)->getSalarioLiquido() == 0) {
                    this->diretores[i]->calcularSalarioMensal(mes);
                
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                if(this->presidente->getFolhaSalarial(mes)->getSalarioLiquido() == 0) {
                    this->presidente->calcularSalarioMensal(mes);
                }
                
            }
        }
    }
    std::cout << "A folha salarial para o mes solicitado foi calculada com sucesso." << std::endl;
}


void Empresa::imprimirFolhaSalarialFuncionario(int codigo) {
    bool algumMesCalculado = false;
    Funcionario *funcionario = buscarFuncionario(codigo);

    if (funcionario != nullptr) {

        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "Folha salarial do funcionario: " << funcionario->getNome() << " // Codigo: " << funcionario->getCodigoFuncionario() << std::endl;

        for(int meses = 1; meses < 13; meses++) {
            if(funcionario->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                algumMesCalculado = true;

                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                std::cout << "Mes: " << (meses) << std::endl;
                std::cout << "Salario base: R$ " << funcionario->getFolhaSalarial(meses)->getSalarioBase() << std::endl;
                std::cout << "Salario liquido: R$ " << (funcionario->getFolhaSalarial(meses)->getSalarioLiquido()) << std::endl;
                std::cout << "Descontos imposto de renda: R$ " << funcionario->getFolhaSalarial(meses)->getDescontoImpostoRenda() << std::endl;
                std::cout << "Descontos previdencia social: R$ " << funcionario->getFolhaSalarial(meses)->getDescontoPrevidencia() << std::endl;
            }
        }   
        
        if(!algumMesCalculado) {
            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            std::cout << "Nao foi calculada a folha salarial de nenhum mes para esse funcionario." << std::endl;
        }
    } else {
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
    }
}

void Empresa::imprimirFolhaSalarialFuncionario(std::string nome) {
    Funcionario *funcionario = nullptr;
    
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getNome().find(nome) != std::string::npos) {
                    funcionario = operadores[i];
                    tipoFuncionario = 4;
                }
            } else if(tipoFuncionario == GERENTE) {
                if (this->gerentes[i]->getNome().find(nome) != std::string::npos) {
                    funcionario = gerentes[i];
                    tipoFuncionario = 4;
                }
            } else if(tipoFuncionario == DIRETOR) {
                if (this->diretores[i]->getNome().find(nome) != std::string::npos) {
                    funcionario = diretores[i];
                    tipoFuncionario = 4;
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getNome().find(nome) != std::string::npos) {
                    funcionario = presidente;
                    tipoFuncionario = 4;
                }
            }
        }
    }

    if (funcionario != nullptr) {
        bool algumMesCalculado = false;

        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "Folha salarial do funcionario: " << funcionario->getNome() << " // Codigo: " << funcionario->getCodigoFuncionario() << std::endl;

        for(int meses = 1; meses < 13; meses++) {
            if(funcionario->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                algumMesCalculado = true;

                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                std::cout << "Mes: " << (meses) << std::endl;
                std::cout << "Salario base: R$ " << funcionario->getFolhaSalarial(meses)->getSalarioBase() << std::endl;
                std::cout << "Salario liquido: R$ " << (funcionario->getFolhaSalarial(meses)->getSalarioLiquido()) << std::endl;
                std::cout << "Descontos imposto de renda: R$ " << funcionario->getFolhaSalarial(meses)->getDescontoImpostoRenda() << std::endl;
                std::cout << "Descontos previdencia social: R$ " << funcionario->getFolhaSalarial(meses)->getDescontoPrevidencia() << std::endl;  
            }
        }   
        
        if(!algumMesCalculado) {
            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            std::cout << "Nao foi calculada a folha salarial de nenhum mes para esse funcionario." << std::endl;
        }

    } else {
        throw FuncionarioNaoEstaCadastradoExcept("Funcionário não está cadastrado");
    }
}

void Empresa::imprimirFolhaSalarialEmpresa(int opcao) {
    if (opcao == 1) {
        bool algumMesCalculado = false;

        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
        std::cout << "A folha salarial da empresa para os meses do ano eh: " << std::endl;

        for(int meses = 1; meses < 13; meses++) {

            double salarioTotalLiquido, salarioTotalBase, descontoPrevidencia, descontoImpostoRenda;
            salarioTotalBase = salarioTotalLiquido = descontoImpostoRenda = descontoPrevidencia = 0;

            for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
                for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
                    if(tipoFuncionario == OPERADOR) {
                        if(this->operadores[i]->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                            algumMesCalculado = true;

                            salarioTotalBase += operadores[i]->getFolhaSalarial(meses)->getSalarioBase();
                            salarioTotalLiquido += operadores[i]->getFolhaSalarial(meses)->getSalarioLiquido();
                            descontoPrevidencia += operadores[i]->getFolhaSalarial(meses)->getDescontoPrevidencia();
                            descontoImpostoRenda += operadores[i]->getFolhaSalarial(meses)->getDescontoImpostoRenda();
                        }
                    } else if(tipoFuncionario == GERENTE) {
                        if(this->gerentes[i]->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                            algumMesCalculado = true;

                            salarioTotalBase += gerentes[i]->getFolhaSalarial(meses)->getSalarioBase();
                            salarioTotalLiquido += gerentes[i]->getFolhaSalarial(meses)->getSalarioLiquido();
                            descontoPrevidencia += gerentes[i]->getFolhaSalarial(meses)->getDescontoPrevidencia();
                            descontoImpostoRenda += gerentes[i]->getFolhaSalarial(meses)->getDescontoImpostoRenda();
                        }
                    } else if(tipoFuncionario == DIRETOR) {
                        if(this->diretores[i]->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                            algumMesCalculado = true;

                            salarioTotalBase += diretores[i]->getFolhaSalarial(meses)->getSalarioBase();
                            salarioTotalLiquido += diretores[i]->getFolhaSalarial(meses)->getSalarioLiquido();
                            descontoPrevidencia += diretores[i]->getFolhaSalarial(meses)->getDescontoPrevidencia();
                            descontoImpostoRenda += diretores[i]->getFolhaSalarial(meses)->getDescontoImpostoRenda();
                        }
                    } else if(tipoFuncionario == PRESIDENTE) {
                        if(this->presidente->getFolhaSalarial(meses)->getSalarioLiquido() != 0) {
                            algumMesCalculado = true;

                            salarioTotalBase += presidente->getFolhaSalarial(meses)->getSalarioBase();
                            salarioTotalLiquido += presidente->getFolhaSalarial(meses)->getSalarioLiquido();
                            descontoPrevidencia += presidente->getFolhaSalarial(meses)->getDescontoPrevidencia();
                            descontoImpostoRenda += presidente->getFolhaSalarial(meses)->getDescontoImpostoRenda();
                        }
                    }
                }
            }

            if(salarioTotalBase != 0) {
                std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
                std::cout << "Mes: " << (meses) << std::endl; 
                std::cout << "Salario base:" << salarioTotalBase << std::endl;
                std::cout << "Salario Liquido:" << salarioTotalLiquido << std::endl;
                std::cout << "Descontos do imposto de renda:" << descontoImpostoRenda << std::endl;
                std::cout << "Descontos da previdencia social:" << descontoPrevidencia << std::endl;  
            }
        }

        if(!algumMesCalculado) {
            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
            std::cout << "Nao foi calculada a folha salarial para nenhum mes." << std::endl;
        }

    } else if(opcao == 2) {
        int mes;
        bool mesCalculado = false;

        std::cout << "Para qual mes deseja imprimir a folha salarial (Digite o numero do mes):" << std::endl;
        std::cin >> mes;

        double salarioTotalLiquido, salarioTotalBase, descontoPrevidencia, descontoImpostoRenda;
        salarioTotalBase = salarioTotalLiquido = descontoImpostoRenda = descontoPrevidencia = 0;
 
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;

        for(int tipoFuncionario = 0; tipoFuncionario < 4; tipoFuncionario++) {
            for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
                if(tipoFuncionario == OPERADOR) {
                    if(this->operadores[i]->getFolhaSalarial(mes)->getSalarioLiquido() != 0) {
                        mesCalculado = true;

                        salarioTotalBase += operadores[i]->getFolhaSalarial(mes)->getSalarioBase();
                        salarioTotalLiquido += operadores[i]->getFolhaSalarial(mes)->getSalarioLiquido();
                        descontoPrevidencia += operadores[i]->getFolhaSalarial(mes)->getDescontoPrevidencia();
                        descontoImpostoRenda += operadores[i]->getFolhaSalarial(mes)->getDescontoImpostoRenda();
                    }
                } else if(tipoFuncionario == GERENTE) {
                    if(this->gerentes[i]->getFolhaSalarial(mes)->getSalarioLiquido() != 0) {
                        mesCalculado = true;

                        salarioTotalBase += gerentes[i]->getFolhaSalarial(mes)->getSalarioBase();
                        salarioTotalLiquido += gerentes[i]->getFolhaSalarial(mes)->getSalarioLiquido();
                        descontoPrevidencia += gerentes[i]->getFolhaSalarial(mes)->getDescontoPrevidencia();
                        descontoImpostoRenda += gerentes[i]->getFolhaSalarial(mes)->getDescontoImpostoRenda();
                    }
                } else if(tipoFuncionario == DIRETOR) {
                    if(this->diretores[i]->getFolhaSalarial(mes)->getSalarioLiquido() != 0) {
                        mesCalculado = true;

                        salarioTotalBase += diretores[i]->getFolhaSalarial(mes)->getSalarioBase();
                        salarioTotalLiquido += diretores[i]->getFolhaSalarial(mes)->getSalarioLiquido();
                        descontoPrevidencia += diretores[i]->getFolhaSalarial(mes)->getDescontoPrevidencia();
                        descontoImpostoRenda += diretores[i]->getFolhaSalarial(mes)->getDescontoImpostoRenda();
                    }
                } else if(tipoFuncionario == PRESIDENTE) {
                    if(this->presidente->getFolhaSalarial(mes)->getSalarioLiquido() != 0) {
                        mesCalculado = true;

                        salarioTotalBase += presidente->getFolhaSalarial(mes)->getSalarioBase();
                        salarioTotalLiquido += presidente->getFolhaSalarial(mes)->getSalarioLiquido();
                        descontoPrevidencia += presidente->getFolhaSalarial(mes)->getDescontoPrevidencia();
                        descontoImpostoRenda += presidente->getFolhaSalarial(mes)->getDescontoImpostoRenda();
                    }
                }
            }
        }

        if(mesCalculado) {
            std::cout << "A folha salarial da empresa para o mes digitado eh: " << std::endl;
            std::cout << "Salario base:" << salarioTotalBase << std::endl;
            std::cout << "Salario Liquido:" << salarioTotalLiquido << std::endl;
            std::cout << "Descontos do imposto de renda:" << descontoImpostoRenda << std::endl;
            std::cout << "Descontos da previdencia social:" << descontoPrevidencia << std::endl;  
        } else {
            std::cout << "A folha salarial desse mes nao foi calculada." << std::endl;
        }
        
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

Funcionario* Empresa::buscarFuncionario(int codigo, int *indice, int *designacao) {
    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getCodigoFuncionario() == codigo) {
                    *indice = i;
                    *designacao = tipoFuncionario;
                    return operadores[i];
                }
            } else if(tipoFuncionario == GERENTE) {
                if (this->gerentes[i]->getCodigoFuncionario() == codigo) {
                    *indice = i;
                    *designacao = tipoFuncionario;
                    return gerentes[i];
                }
            } else if(tipoFuncionario == DIRETOR) {
                if (this->diretores[i]->getCodigoFuncionario() == codigo) {
                    *indice = i;
                    *designacao = tipoFuncionario;
                    return diretores[i];
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getCodigoFuncionario() == codigo) {
                    *indice = i;
                    *designacao = tipoFuncionario;
                    return presidente;
                }
            }
        }
    }

    return nullptr;
}

//primeiro ano
//depois o dia só não pode ser menor no mes inicial
//depois o dia só não pode ser maior no mes final
//nos anos X tem que olhar o mes
//nos meses Y tem que olhar o dia

void Empresa::buscarFuncionariosIntervaloTempo(int *dataInicial, int *dataFinal) {
    bool funcionarioEncontrado = false;

    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if (this->operadores[i]->getDataIngresso().getAno() > dataInicial[2] and this->operadores[i]->getDataIngresso().getAno() < dataFinal[2]) {
                    funcionarioEncontrado = true;

                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                    std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                    std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                } else if(this->operadores[i]->getDataIngresso().getAno() == dataInicial[2] or this->operadores[i]->getDataIngresso().getAno() == dataFinal[2]) {
                    if(this->operadores[i]->getDataIngresso().getMes() > dataInicial[1] and this->operadores[i]->getDataIngresso().getMes() < dataFinal[1]) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                    } else if(this->operadores[i]->getDataIngresso().getMes() == dataInicial[1] or this->operadores[i]->getDataIngresso().getMes() == dataFinal[1]) {
                        if(this->operadores[i]->getDataIngresso().getDia() >= dataInicial[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                        } else if(this->operadores[i]->getDataIngresso().getDia() <= dataFinal[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                        }
                    }
                }
            } else if(tipoFuncionario == GERENTE) {
                if (this->gerentes[i]->getDataIngresso().getAno() > dataInicial[2] and this->gerentes[i]->getDataIngresso().getAno() < dataFinal[2]) {
                    funcionarioEncontrado = true;

                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                    std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                    std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                } else if(this->gerentes[i]->getDataIngresso().getAno() == dataInicial[2] or this->gerentes[i]->getDataIngresso().getAno() == dataFinal[2]) {
                    if(this->gerentes[i]->getDataIngresso().getMes() > dataInicial[1] and this->gerentes[i]->getDataIngresso().getMes() < dataFinal[1]) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                    } else if(this->gerentes[i]->getDataIngresso().getMes() == dataInicial[1] or this->gerentes[i]->getDataIngresso().getMes() == dataFinal[1]) {
                        if(this->gerentes[i]->getDataIngresso().getDia() >= dataInicial[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                        } else if(this->gerentes[i]->getDataIngresso().getDia() <= dataFinal[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                        }
                    }
                }
            } else if(tipoFuncionario == DIRETOR) {
                if (this->diretores[i]->getDataIngresso().getAno() > dataInicial[2] and this->diretores[i]->getDataIngresso().getAno() < dataFinal[2]) {
                    funcionarioEncontrado = true;

                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                    std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                    std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                } else if(this->diretores[i]->getDataIngresso().getAno() == dataInicial[2] or this->diretores[i]->getDataIngresso().getAno() == dataFinal[2]) {
                    if(this->diretores[i]->getDataIngresso().getMes() > dataInicial[1] and this->diretores[i]->getDataIngresso().getMes() < dataFinal[1]) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                    } else if(this->diretores[i]->getDataIngresso().getMes() == dataInicial[1] or this->diretores[i]->getDataIngresso().getMes() == dataFinal[1]) {
                        if(this->diretores[i]->getDataIngresso().getDia() >= dataInicial[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                        } else if(this->diretores[i]->getDataIngresso().getDia() <= dataFinal[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                        }
                    }
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                if (this->presidente->getDataIngresso().getAno() > dataInicial[2] and this->presidente->getDataIngresso().getAno() < dataFinal[2]) {
                    funcionarioEncontrado = true;

                    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                    std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                    std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                    std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                } else if(this->presidente->getDataIngresso().getAno() == dataInicial[2] or this->presidente->getDataIngresso().getAno() == dataFinal[2]) {
                    if(this->presidente->getDataIngresso().getMes() > dataInicial[1] and this->presidente->getDataIngresso().getMes() < dataFinal[1]) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                    } else if(this->presidente->getDataIngresso().getMes() == dataInicial[1] or this->presidente->getDataIngresso().getMes() == dataFinal[1]) {
                        if(this->presidente->getDataIngresso().getDia() >= dataInicial[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                        } else if(this->presidente->getDataIngresso().getDia() <= dataFinal[0]) {
                            funcionarioEncontrado = true;

                            std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                            std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                            std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                            std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                        }
                    }
                }
            }
        }
    }

    if(!funcionarioEncontrado) {
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
        std::cout << "Nenhum funcionario foi encontrado para os parametros de busca" << std::endl;
    }
}

void Empresa::buscarFuncionariosParcial(std::string informacao, int opcao) {
    bool funcionarioEncontrado = false;

    for(int tipoFuncionario = 0; tipoFuncionario < QTD_DE_TIPOS; tipoFuncionario++) {
        for (int i = 0; i < this->qtdFuncionarios[tipoFuncionario]; i++) {
            if(tipoFuncionario == OPERADOR) {
                if(opcao == BUSCAR_POR_NOME) {
                    if (this->operadores[i]->getNome().find(informacao) != std::string::npos) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                    }
                } else if(opcao == BUSCAR_POR_ENDERECO) {
                    if (this->operadores[i]->getEndereco()->comparaEndereco(informacao)) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->operadores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->operadores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->operadores[i]->getEndereco()->getInformacao() << std::endl;
                    }
                }
            } else if(tipoFuncionario == GERENTE) {
                if(opcao == BUSCAR_POR_NOME) {
                    if (this->gerentes[i]->getNome().find(informacao) != std::string::npos) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                    }
                } else if(opcao == BUSCAR_POR_ENDERECO) {
                    if (this->gerentes[i]->getEndereco()->comparaEndereco(informacao)) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->gerentes[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->gerentes[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->gerentes[i]->getEndereco()->getInformacao() << std::endl;
                    }
                }
            } else if(tipoFuncionario == DIRETOR) {
                if(opcao == BUSCAR_POR_NOME) {
                    if (this->diretores[i]->getNome().find(informacao) != std::string::npos) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                    }
                } else if(opcao == BUSCAR_POR_ENDERECO) {
                    if (this->diretores[i]->getEndereco()->comparaEndereco(informacao)) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->diretores[i]->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->diretores[i]->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->diretores[i]->getEndereco()->getInformacao() << std::endl;
                    }
                }
            } else if(tipoFuncionario == PRESIDENTE) {
                if(opcao == BUSCAR_POR_NOME) {
                    if (this->presidente->getNome().find(informacao) != std::string::npos) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                    }
                } else if(opcao == BUSCAR_POR_ENDERECO) {
                    if (this->presidente->getEndereco()->comparaEndereco(informacao)) {
                        funcionarioEncontrado = true;

                        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
                        std::cout << "Nome: " << this->presidente->getNome() << std::endl;
                        std::cout << "Data de ingresso: " << this->presidente->getDataIngresso().retornaStringData() << std::endl;
                        std::cout << "Endereco: " << this->presidente->getEndereco()->getInformacao() << std::endl;
                    }
                }
            }
        }
    }

    if(!funcionarioEncontrado) {
        std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;  
        std::cout << "Nenhum funcionario foi encontrado para os parametros de busca" << std::endl;
    }
}

