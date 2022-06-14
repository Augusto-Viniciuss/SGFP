#include "Interface.h"

int Interface::menu() {
    std::cout << "       MENU        " << std::endl << std::endl;
    std::cout << "Digite 1 para cadastrar um novo funcionario na empresa." << std::endl;
    std::cout << "Digite 2 para modificar o registro de um funcionario ja cadastrado." << std::endl;
    std::cout << "Digite 3 para excluir o registro de um funcionario." << std::endl;
    std::cout << "Digite 4 para exibir o registro de um funcionario." << std::endl;
    std::cout << "Digite 5 para exibir o registro de todos os funcionarios." << std::endl;
    std::cout << "Digite 6 para exibir o registro de todos os funcionarios de um tipo." << std::endl;
    std::cout << "Digite 7 para Conceder um aumento de salario para os funcionarios." << std::endl;
    std::cout << "Digite 8 para calcular a folha salarial da empresa para um determinado mes." << std::endl;
    std::cout << "Digite 9 para imprimir a folha de salario de um funcionario." << std::endl;
    std::cout << "Digite 10 para imprimir a folha salarial da empresa." << std::endl;
    std::cout << "Digite 11 para buscar um funcionario." << std::endl;
    std::cout << "Digite 0 para sair do programa." << std::endl;

    int opcao;

    std::cin >> opcao;

    while (opcao > 11 or opcao < 0) {
        std::cout << std::endl << "Opcao invalida, por favor escolha uma opcao valida." << std::endl << std::endl;
        menu();
        std::cin >> opcao;
    }

    return opcao;
}

Funcionario* Interface::lerAtributosFuncionario() {
    Funcionario *funcionario;
    int codigo, idade, designacao;
    std::string nome, CPF, telefone, CEP;
    int data[3];

    std::cout << "Digite o codigo do funcionario:" << std::endl;
    std::cin >> codigo;
    std::cout << "Digite o nome do funcionario:" << std::endl;
    std::cin.ignore();
    getline(std::cin, nome);
    std::cout << "Digite o CPF do funcionario:" << std::endl;
    getline(std::cin, CPF);
    std::cout << "Digite a idade do funcionario:" << std::endl;
    std::cin >> idade;
    std::cin.ignore();
    std::cout << "Digite o CEP do funcionario:" << std::endl;
    getline(std::cin, CEP);
    std::cout << "Digite o telefone para contato do funcionario:" << std::endl;
    getline(std::cin, telefone);
    std::cout << "Digite a data de ingresso na empresa, na ordem dia, mes e ano separados por espacos:" << std::endl;
    std::cin >> data[0] >> data[1] >> data[2];
    std::cout << "Qual a designacao do funcionario:" << std::endl;
    std::cout << "Digite 0 para operador" << std::endl << "Digite 1 para gerente" << std::endl << "Digite 2 para diretor" << std::endl << "Digite 3 para presidente" << std::endl;
    std::cin >> designacao;
    std::cin.ignore();

    switch (designacao) {
    case 0:
        funcionario = new Operador(codigo, nome, CPF, idade, CEP, telefone, data, designacao);
        break;
    case 1:
        {
            std::string areaSupervisao;

            std::cout << "Digite a area de supervisao:" << std::endl;
            getline(std::cin, areaSupervisao);
            funcionario = new Gerente(codigo, nome, CPF, idade, CEP, telefone, data, designacao, areaSupervisao);
            break;
        }
    case 2:
        {
            std::string areaSupervisao, areaFormacao;

            std::cout << "Digite a area de supervisao:" << std::endl;
            getline(std::cin, areaSupervisao);
            std::cout << "Digite a area de formacao:" << std::endl;
            getline(std::cin, areaFormacao);
            funcionario = new Diretor(codigo, nome, CPF, idade, CEP, telefone, data, designacao, areaSupervisao, areaFormacao);
            break;
        }
    case 3:
        {
            std::string areaFormacao, formacaoMax;

            std::cout << "Digite a area de formacao:" << std::endl;
            getline(std::cin, areaFormacao);
            std::cout << "Digite a formacao maxima:" << std::endl;
            getline(std::cin, formacaoMax);
            funcionario = new Presidente(codigo, nome, CPF, idade, CEP, telefone, data, designacao, areaFormacao, formacaoMax);
            break;
        }
    }

    return funcionario;
}

int Interface::lerCodigoParaModificarFuncionario() {
    int codigo;

    std::cout << "Digite o codigo do funcionario que deseja modificar:" <<  std::endl;
    std::cin >>codigo;

    return codigo;
}

int Interface::lerOpcaoParaModificarFuncionario() {
    int opcao;

    std::cout << "Digite 1 para modificar a idade" << std::endl;
    std::cout << "Digite 2 para modificar o designacao" << std::endl;
    std::cout << "Digite 3 para modificar a data de ingresso na empresa" << std::endl;
    std::cout << "Digite 4 para modificar o nome" << std::endl;
    std::cout << "Digite 5 para modificar o endereco" << std::endl;
    std::cout << "Digite 6 para modificar o telefone" << std::endl;
    std::cout << "Digite 7 para modificar o CPF" << std::endl;
    std::cin >> opcao;

    if((opcao < 1) or (opcao > 8)) {
        std::cout << "Opcao Invalida" << std::endl;
        opcao = lerOpcaoParaModificarFuncionario();
    }

    return opcao;
}


std::string Interface::lerNovoAtributoStrParaModificarFuncionario(int opcao) {
    std::string atributoFuncionario;

    if(opcao == 4) {
        std::cout << "Digite o novo nome para o funcionario:" << std::endl;
        std::cin.ignore();
        getline(std::cin, atributoFuncionario);
    } else if(opcao == 5) {
        std::cout << "Digite o novo CEP para o funcionario:" << std::endl;
        std::cin.ignore();
        getline(std::cin, atributoFuncionario);
        std::cout << atributoFuncionario << std::endl;
    } else if(opcao == 6) {
        std::cout << "Digite o telefone novo para o funcionario:" << std::endl;
        std::cin.ignore();
        getline(std::cin, atributoFuncionario);
    } else if(opcao == 7) {
        std::cout << "Digite o CPF novo para o funcionario:" << std::endl;
        std::cin.ignore();
        getline(std::cin, atributoFuncionario);
    }

    return atributoFuncionario;
}

int Interface::lerNovoAtributoIntParaModificarFuncionario(int opcao) {
    int atributoFuncionario;

    if(opcao == 2) {
        std::cout << "Qual a nova designacao do funcionario:" << std::endl;
        std::cout << "Digite 1 para operador" << std::endl << "Digite 2 para gerente" << std::endl << std::endl << "Digite 3 para diretor" << std::endl << "Digite 4 para presidente" << std::endl;
        std::cin >> atributoFuncionario;
    } else if(opcao == 1) {
        std::cout << "Digite a nova idade para o funcionario:" << std::endl;
        std::cin >> atributoFuncionario;
    }
    
    return atributoFuncionario;
}

void Interface::lerNovaDataParaModificarFuncionario(int *data) {
    std::cout << "Digite a data de ingresso nova, na ordem dia, mes e ano separados por espacos:" << std::endl;
    std::cin >> data[0] >> data[1] >> data[2];
}

int Interface::lerCodigoParaExcluirFuncionario() {
    int codigo;

    std::cout << "Digite o codigo do funcionario que deseja excluir:" << std::endl;
    std::cin >> codigo;

    return codigo;
}

int Interface::lerCodigoParaExibirFuncionario() {
    int codigo;

    std::cout << "Digite o codigo do funcionario que deseja ser exibido:" << std::endl;
    std::cin >> codigo;

    return codigo;
}

int Interface::lerTipoParaExibirFuncionarios() {
    int tipo;

    std::cout << "Digite o tipo dos funcionarios que voce deseja que seja exibido:" << std::endl;
    std::cout << "Digite 0 para operador" << std::endl << "Digite 1 para gerente" << std::endl << "Digite 2 para diretor" << std::endl << "Digite 3 para presidente" << std::endl;
    std::cin >> tipo;

    if(tipo < 0 or tipo > 3) {
        std::cout << "Opcao invalida." << std::endl;
        tipo = lerTipoParaExibirFuncionarios();
    }

    return tipo;
}

int Interface::lerMesParaCalcularFolhaSalarialEmpresa() {
    int mes;

    std::cout << "Digite o mes que deseja ser calculada a folha salarial:" << std::endl;
    std::cin >> mes;

    return mes;
}

std::string Interface::lerNomeParaImprimirFolhaSalarialFuncionario() {
    std::string nome;

    std::cout << "Digite o nome completo do funcionario que deseja calcular a folha salarial:" << std::endl;
    std::cin.ignore();
    getline(std::cin, nome);

    return nome;
}

int Interface::lerCodigoParaImprimirFolhaSalarialFuncionario() {
    int codigo;

    std::cout << "Digite o codigo do funcionario que deseja imprimir a folha salarial:" << std::endl;
    std::cin >> codigo;

    return codigo;
}

int Interface::lerTipoAtributoParaImprimirFolhaSalarialFuncionario() {
    int tipo;

    std::cout << "Digite 5 para imprimir a folha salarial do funcionario atraves do nome" << std::endl;
    std::cout << "Digite 8 para imprimir a folha salrial do funcionario atraves do codigo dele" << std::endl;
    std::cin >> tipo;

    return tipo;
}

int Interface::lerOpcaoParaImprimirFolhaSalarialEmpresa() {
    int opcao;

    std::cout << "Digite 1 para imprimir a folha salarial do ano todo" << std::endl << "Digite 2 para imprimir a folha salarial de um mes especifico" << std::endl;
    std::cout << "Digite 2 para imprimir a folha salrial para um mes especifico" <<  std::endl;
    std::cin >> opcao;

    return opcao;
}

