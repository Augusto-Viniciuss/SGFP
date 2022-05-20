#include <iostream>
#include "Empresa.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Endereco.h"
#include "Data.h"

using namespace std;

void exibeMenu() {
    cout << "       MENU        " << endl << endl;
    cout << "Digite 1 para cadastrar um novo funcionario na empresa." << endl;
    cout << "Digite 2 para modificar o registro de um funcionario ja cadastrado." << endl;
    cout << "Digite 3 para excluir o registro de um funcionario." << endl;
    cout << "Digite 4 para exibir o registro de um funcionario." << endl;
    cout << "Digite 5 para exibir o registro de todos os funcionarios." << endl;
    cout << "Digite 6 para exibir o registro de todos os funcionarios de um tipo." << endl;
    cout << "Digite 7 para Conceder um aumento de salario para os funcionarios." << endl;
    cout << "Digite 8 para calcular a folha salarial da empresa para um determinado mes." << endl;
    cout << "Digite 9 para imprimir a folha de salario de um funcionario." << endl;
    cout << "Digite 10 para imprimir a folha salarial da empresa." << endl;
    cout << "Digite 0 para sair do programa." << endl;
}

int main () {
    Empresa empresa;
    Funcionario *funcionario;
    int opcaoMenu;

    while (true) {
        exibeMenu();
        cin >> opcaoMenu;

        if (opcaoMenu == 0) {
            break;
        } else if (opcaoMenu < 10 or opcaoMenu > 0) {
            cout << endl << "Opcao invalida, por favor escolha uma opcao valida." << endl << endl;
            exibeMenu();
            cin >> opcaoMenu;
        }

        if (opcaoMenu == 1) {
            int codigo, idade;
            string nome, CPF, telefone, designacao;
            double salario, taxaAumento;
            Endereco endereco;
            Data data;
            int dia, mes, ano;

            cout << "Digite o codigo do funcionario:" << endl;
            cin >> codigo;
            cout << "Digite o nome do funcionario:" << endl;
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o CPF do funcionario:" << endl;
            getline(cin, CPF);
            cout << "Digite a idade do funcionario:" << endl;
            cin >> idade;
            endereco.setEndereco();
            cout << "Digite o telefone para contato do funcionario:" << endl;
            getline(cin, telefone);
            cout << "Digite a data de ingresso na empresa, na ordem dia, mes e ano separados por espacos:" << endl;
            cin >> dia >> mes >> ano;
            cout << "Digite a designacao do funcionario:" << endl;
            cin.ignore();
            getline(cin, designacao);
            
            if (designacao.find("Presidente") != string::npos) {
                funcionario = new Presidente();
            } else if (designacao.find("Gerente") != string::npos) {
                funcionario = new Gerente();
            } else if (designacao.find("Diretor") != string::npos) {
                funcionario = new Diretor();
            } else if (designacao.find("Operador") != string::npos) {
                funcionario = new Operador();
            }

            empresa.addFuncionario(funcionario);
        }
    }

    return 0;
}