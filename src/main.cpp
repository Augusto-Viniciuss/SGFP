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
                return 0;
            } else if(opcaoMenu == 1) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
               
            } else if (opcaoMenu == 2) {
                std::string atributoFuncionarioStr;
                int atributoFuncionarioInt;
                int atributoFuncionarioData[3];
                int opcao, codigo;

                codigo = interface.lerCodigoParaModificarFuncionario();
                opcao = interface.lerOpcaoParaModificarFuncionario();

                if(opcao >= 4 and opcao <= 7) {
                    atributoFuncionarioStr = interface.lerNovoAtributoStrParaModificarFuncionario(opcao);
                    empresa.modificarFuncionario(codigo, opcao, atributoFuncionarioStr);
                } else if(opcao >= 1 and opcao <= 2) {
                    atributoFuncionarioInt = interface.lerNovoAtributoIntParaModificarFuncionario(opcao);
                    empresa.modificarFuncionario(codigo, opcao, atributoFuncionarioInt);
                } else {
                    interface.lerNovaDataParaModificarFuncionario(atributoFuncionarioData);
                    empresa.modificarFuncionario(codigo, atributoFuncionarioData);
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
                } else if(tipoAtributo == 2){
                    codigo = interface.lerCodigoParaImprimirFolhaSalarialFuncionario();
                    empresa.imprimirFolhaSalarialFuncionario(codigo);
                }
            } else if(opcaoMenu == 10) {
                int opcaoParaImprimir;

                opcaoParaImprimir = interface.lerOpcaoParaImprimirFolhaSalarialEmpresa();

                empresa.imprimirFolhaSalarialEmpresa(opcaoParaImprimir);
            } else if(opcaoMenu == 11) {
                int tipoBusca;
                Funcionario *funcionario;
                std::string informacao;
                int dataInicial[3], dataFinal[3];
                int tipoInformacao;

                tipoBusca = interface.lerOpcaoParaBuscarFuncionario();

                if(tipoBusca == 1) {
                    tipoInformacao = interface.lerTipoInformacaoStrParaBuscarFuncionario();
                    informacao = interface.lerInformacaoStrParaBuscarFuncionario(tipoInformacao);
                    switch (tipoInformacao) {
                    case 1:
                        empresa.buscarFuncionariosParcial(informacao, 5);
                        break;
                    case 2:
                        empresa.buscarFuncionariosParcial(informacao, 6);
                        break;
                    }
                } else if(tipoBusca == 2) {
                    interface.lerDataParaBuscarFuncionario(dataInicial, dataFinal);
                    empresa.buscarFuncionariosIntervaloTempo(dataInicial, dataFinal);
                }
            } 
        } catch(FuncionarioJaCadastradoExcept &funcionarioJaCadastrado) {
            int opcao;
            
            std::cout << "Funcionario ja esta cadastrado, digite 1 se deseja atualiza-lo ou 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if (opcao == 1) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        } catch(FuncionarioNaoEstaCadastradoExcept &funcionarioNaoEstaCadastrado) {
            int opcao;

            std::cout << "Funcionario nao esta cadastrado, digite 1 se deseja cadastra-lo e 2 se nao desejar:" << std::endl;
            std::cin >> opcao;

            if(opcao == 1) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        } catch(TentativaAbrirArquivo &ProblemaArquivo) {
            
            std::cout << "Não foi possivel criar o arquivo, ou abri-lo, verifique se ele existe na pasta do programa" << std::endl;    
        } catch(InvalidoArgumentoArquivoExcept &TentativaExcluirPresidente) {
            std::cout << "Voce fez uma operação inválida, tentar excluir o presidente." << std::endl;
            int codigo;
            
            std::cout << "Digite um novo codigo: ";
            std::cin >> codigo;
            

            codigo = interface.lerCodigoParaExcluirFuncionario();
        }


    }
}