#include <iostream>
#include "Empresa.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Interface.h"
#include "FuncionarioJaCadastradoExcept.h"
#include "FuncionarioNaoEstaCadastradoExcept.h"

#define INT 1
#define STR 2

using namespace std;

template<typename atributo>
int main() {
    Empresa empresa;
    Funcionario *funcionario;
    Interface interface;
    int opcaoMenu;

    while(true) {
        try {
            opcaoMenu = interface.menu();

            if (opcaoMenu == 0) {
                break;
            }

            if(opcaoMenu == 1) {
                funcionario = interface.cadastraFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacao(INT));
            } else if (opcaoMenu == 2) {
                atributo atributoFuncionario;
                int opcao, codigo;

                codigo = interface.lerCodigoParaModificarFuncionario();
                opcao = interface.lerOpcaoParaModificarFuncionario();
                atributoFuncionario = interface.novoAtributoParaModificarFuncionario();

                empresa.modificarFuncionario(codigo, opcao, atributo);
            } else if(opcao == 3) {
                int codigo;

                codigo = interface.lerCodigoParaExcluirFuncionario();

                empresa.excluirFuncionario(codigo);
            } else if(opcao == 4) {
                int codigo;

                codigo = interface.lerCodigoParaExibirFuncionario();

                empresa.exibirFuncionario(codigo);
            } else if(opcao == 5) {
                empresa.exibirTodosFuncionarios();
            } else if(opcao == 6) {
                int tipo;

                tipo = interface.lerTipoParaExibirFuncionarios();

                empresa.exibirFuncionariosPorTipo(tipo);
            } else if(opcao == 7) {
                empresa.concederAumentoSalarial();
            } else if(opcao == 8) {
                int mes;

                mes = interface.lerMesParaCalcularFolhaSalarialEmpresa();

                empresa.calcularFolhaSalarial(mes)
            } else if(opcao == 9) {
                atributo atributoFuncionario;
                int tipoAtributo;

                tipoAtributo = interface.lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
                atributoFuncionario = interface.lerAtributoParaImprimirFolhaSalarialFuncionario();


                empresa.imprimirFolhaSalarialFuncionario(atributoFuncionario, tipoAtributo);
            } else if(opcao == 10) {
                int opcaoParaImprimir;

                opcaoParaImprimir = interface.lerOpcaoParaImprimirFolhaSalarialEmpresa();

                empresa.imprimirFolhaSalarialEmpresa(opcaoParaImprimir);
            }
        } catch(FuncionarioJaCadastradoExcept &funcionarioJaCadastrado) {
            int opcao;
            
            std::cout << "Funcionario ja esta cadastrado, digite 1 se deseja atualiza-lo ou 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if (opcao) {
                funcionario = interface.cadastraFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacao(INT));
            }
        } catch(FuncionarioNaoEstaCadastradoExcept &funcionarioNaoEstaCadastrado) {
            int opcao;

            std::cout << "Funcionario nao esta cadastrado, digite 1 se deseja cadastra-lo e 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if(opcao) {
                funcionario = interface.cadastraFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacao(INT));
            }
        }
    }

    return 0;
}