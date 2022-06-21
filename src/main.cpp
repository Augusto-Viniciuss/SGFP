#include <iostream>
#include "Empresa.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Interface.h"
#include "FuncionarioJaCadastradoExcept.h"
#include "FuncionarioNaoEstaCadastradoExcept.h"
#include "OpcaoInvalidaException.h"
#include <locale.h>



#define INT 1
#define STR 2

using namespace std;

int main() {
    Empresa empresa;
    Funcionario *funcionario;
    Interface interface;
    int opcaoMenu;

    setlocale(LC_ALL, NULL);

    while(true) {

        /* Bloco de try catch para caso seja acessado algum throw   */ 
        try {
            
            /* Armazena a opção inserida pelo usuário   */
            opcaoMenu = interface.menu();
            /* Entra em algum dos if dependendo do tipo de escolha do usuário*/
            /*  [1] para cadastrar um novo funcionario na empresa.
                [2] para modificar o registro de um funcionario ja cadastrado.
                [3] para excluir o registro de um funcionario.
                [4] para exibir o registro de um funcionario.
                [5] para exibir o registro de todos os funcionarios.
                [6] para exibir o registro de todos os funcionarios de um tipo.
                [7] para Conceder um aumento de salario para os funcionarios.
                [8] para calcular a folha salarial da empresa para um determinado mes.
                [9] para imprimir a folha de salario de um funcionario.
                [10] para imprimir a folha salarial da empresa.
                [11] para buscar um funcionario.
                [0] para sair do programa.
            */

            if (opcaoMenu == 0) {
                return 0;
            } else if(opcaoMenu == 1) {
                funcionario = interface.lerAtributosFuncionario(); // Chamada de função para leitura dos atributos

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt()); // Adiciona a empresa
               
            } else if (opcaoMenu == 2) {
                /* Variáveis que podem ser modificadas do funcionario   */
                std::string atributoFuncionarioStr;
                int atributoFuncionarioInt;
                int atributoFuncionarioData[3];
                int opcao, codigo;
                
                /* Realiza a leitura de informações para modificações   */
                codigo = interface.lerCodigoParaModificarFuncionario();
                opcao = interface.lerOpcaoParaModificarFuncionario();

                /* Dependendo da opção, leia-se o dado para modificação */
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
                /* Leitura do codigo e chamada de função para excluir funcionario   */
                int codigo;

                codigo = interface.lerCodigoParaExcluirFuncionario();

                empresa.excluirFuncionario(codigo);
            } else if(opcaoMenu == 4) {
                /* Declaração do codigo e leitura do codigo para exibir o funcionario   */
                int codigo;

                codigo = interface.lerCodigoParaExibirFuncionario();

                empresa.exibirFuncionario(codigo);
            } else if(opcaoMenu == 5) {
                /* Chamada da função para exiber todos os funcionários  */
                empresa.exibirTodosFuncionarios();
            } else if(opcaoMenu == 6) {
                /* Declaração do tipo , ler o tipo de funcionario para exibir e depois chama o método de empresa    */
                int tipo;

                tipo = interface.lerTipoParaExibirFuncionarios();

                empresa.exibirFuncionariosPorTipo(tipo);
            } else if(opcaoMenu == 7) {
                empresa.concederAumentoSalarial(); // Concede o aumento salarial
            } else if(opcaoMenu == 8) {
                int mes;

                mes = interface.lerMesParaCalcularFolhaSalarialEmpresa(); // Leitura do mẽs para calcular a folha salarial

                empresa.calcularFolhaSalarial(mes); // Chamada do método para calcular a folha
            } else if(opcaoMenu == 9) {
                /* Atributos para leitura */
                std::string nome;
                int codigo;
                int tipoAtributo;
                
                /* Recebe o tipo de atributo    */
                tipoAtributo = interface.lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
                
                /* Dependendo do tipo printa a informação   */
                if(tipoAtributo == 1) {
                    nome = interface.lerNomeParaImprimirFolhaSalarialFuncionario();
                    empresa.imprimirFolhaSalarialFuncionario(nome);
                } else if(tipoAtributo == 2){
                    codigo = interface.lerCodigoParaImprimirFolhaSalarialFuncionario();
                    empresa.imprimirFolhaSalarialFuncionario(codigo);
                }
            } else if(opcaoMenu == 10) {
                /* Opção para imprimir folha salarial   */
                int opcaoParaImprimir;
                /* Leia-se a opção e printa chamando o método de empresa    */
                opcaoParaImprimir = interface.lerOpcaoParaImprimirFolhaSalarialEmpresa();

                empresa.imprimirFolhaSalarialEmpresa(opcaoParaImprimir);
            } else if(opcaoMenu == 11) {
                /* Atributos para buscar funcionário    */
                int tipoBusca;
                Funcionario *funcionario;
                std::string informacao;
                int dataInicial[3], dataFinal[3];
                int tipoInformacao;

                /* Armazena o tipo de busca que o usuario deseja    */
                tipoBusca = interface.lerOpcaoParaBuscarFuncionario();

                // Dependendo do tipo de busca, utiliza o método correspondente de empresa
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
            /* Catch responsáveis por cada erro do programa */ 
        } catch(FuncionarioJaCadastradoExcept &funcionarioJaCadastrado) {
            int opcao;
            std::string opcaoStr;
            
            std::cout << "Funcionario ja esta cadastrado, digite 1 se deseja atualiza-lo ou 2 se nao desejar:" << std::endl;
            try{
                getline(std::cin, opcaoStr);

                opcao = interface.validaInteiro(opcaoStr);
            }
            catch(OpcaoInvalidaException &opcaoInvalida){
                std::cerr << opcaoInvalida.what() << '\n';
            }

            if (opcao == 1) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        } catch(FuncionarioNaoEstaCadastradoExcept &funcionarioNaoEstaCadastrado) {
            int opcao;
            std::string opcaoStr;

            std::cout << "Funcionario nao esta cadastrado, digite 1 se deseja cadastra-lo e 2 se nao desejar:" << std::endl;
            try{
                getline(std::cin, opcaoStr);

                opcao = interface.validaInteiro(opcaoStr);
            }
            catch(OpcaoInvalidaException &opcaoInvalida){
                std::cerr << opcaoInvalida.what() << '\n';
            }

            if(opcao == 1) {
                funcionario = interface.lerAtributosFuncionario();

                empresa.addFuncionario(funcionario, funcionario->getDesignacaoInt());
            }
        } catch(TentativaAbrirArquivo &ProblemaArquivo) {
            ProblemaArquivo.what();
               
        } catch(InvalidoArgumentoArquivoExcept &TentativaExcluirPresidente) {
            std::cout << "Voce fez uma operação inválida, tentar excluir o presidente." << std::endl;
            int codigo;
            
            codigo = interface.lerCodigoParaExcluirFuncionario();
            empresa.excluirFuncionario(codigo);
        } 


    }
}