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
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            } else if (opcaoMenu == 2) {
                std::string atributoFuncionarioStr;
                int atributoFuncionarioInt;
                int *atributoFuncionarioData;
                int opcao, codigo;

                codigo = interface.lerCodigoParaModificarFuncionario();
                opcao = interface.lerOpcaoParaModificarFuncionario();

                if((opcao >= 1) and (opcao <= 3)) {
                    atributoFuncionarioInt = interface.lerNovoAtributoIntParaModificarFuncionario(opcao);
                    empresa.modificarFuncionario(codigo, opcao, atributoFuncionarioInt);
                } else if((opcao >= 4) and (opcao <= 8)) {
                    atributoFuncionarioStr = interface.lerNovoAtributoStrParaModificarFuncionario(opcao);
                    empresa.modificarFuncionario(codigo, opcao, atributoFuncionarioStr);
                } else {
                    atributoFuncionarioData = interface.lerNovaDataParaModificarFuncionario();
                    empresa.modificarFuncionario(codigo, opcao, atributoFuncionarioData);
                }  
            } else if(opcaoMenu == 3) {
                int codigo;

                codigo = interface.lerCodigoParaExcluirFuncionario();

                empresa.excluirFuncionario(codigo);
            } else if(opcaoMenu == 4) {
                int codigo;

                codigo = interface.lerCodigoParaExibirFuncionario();

                empresa.exibirFuncionario(codigo);
            } else if(opcaoMenu == 5) {
                empresa.exibirTodosFuncionarios();
            } else if(opcaoMenu == 6) {
                int tipo;

                tipo = interface.lerTipoParaExibirFuncionarios();

                empresa.exibirFuncionariosPorTipo(tipo);
            } else if(opcaoMenu == 7) {
                empresa.concederAumentoSalarial();
            } else if(opcaoMenu == 8) {
                int mes;

                mes = interface.lerMesParaCalcularFolhaSalarialEmpresa();

                empresa.calcularFolhaSalarial(mes);
            } else if(opcaoMenu == 9) {
                std::string nome;
                int codigo;
                int tipoAtributo;

                tipoAtributo = interface.lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
                
                if(tipoAtributo == 1) {
                    nome = interface.lerNomeParaImprimirFolhaSalarialFuncionario();
                    empresa.imprimirFolhaSalarialFuncionario(nome);
                } else {
                    codigo = interface.lerCodigoParaImprimirFolhaSalarialFuncionario();
                    empresa.imprimirFolhaSalarialFuncionario(codigo);
                }
            } else if(opcaoMenu == 10) {
                int opcaoParaImprimir;

                opcaoParaImprimir = interface.lerOpcaoParaImprimirFolhaSalarialEmpresa();

                empresa.imprimirFolhaSalarialEmpresa(opcaoParaImprimir);
            }
        } catch(FuncionarioJaCadastradoExcept &funcionarioJaCadastrado) {
            int opcao;
            
            std::cout << "Funcionario ja esta cadastrado, digite 1 se deseja atualiza-lo ou 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if (opcao) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        } catch(FuncionarioNaoEstaCadastradoExcept &funcionarioNaoEstaCadastrado) {
            int opcao;

            std::cout << "Funcionario nao esta cadastrado, digite 1 se deseja cadastra-lo e 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if(opcao) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        }
    }

    return 0;
}