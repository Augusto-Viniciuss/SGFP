#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "TelefoneException.h"
#include "CPFException.h"
#include "CEPException.h"
#include "CadastrarFuncionarioException.h"
#include "OpcaoInvalidaException.h"

class Interface {
    public:
        /**
		* menu()
		* 
		* Exibe o menu do programa.
		* \return Retorna um inteiro sendo opção escolhida do menu.
		*/ 
        int menu();

        /**
		* menuTexto()
		* 
		* Texto exibido no metodo menu().
		* \return void.
		*/ 
        void menuTexto();

        /**
		* lerAtributosFuncionario()
		* 
		* Lê os atributos necessários e instancia um funcionario.
		* \return Retorna um ponteiro para o funcionário instanciado.
		*/ 
        Funcionario* lerAtributosFuncionario();

        /**
		* lerCodigoParaModificarFuncionario()
		* 
		* Lê codigo do funcionário que vai ser solicitado uma modificação nos atributos.
		* \return Retorna um inteiro sendo ele o código do funcionário lido.
		*/ 
        int lerCodigoParaModificarFuncionario();

        /**
		* lerOpcaoParaModificarFuncionario()
		* 
		* Lê a opção de modificação de atributo do funcionário a ser modificado.
		* \return Retorna um inteiro sendo ele a opção de modificação.
		*/ 
        int lerOpcaoParaModificarFuncionario();

        /**
		* opcaoParaModificarFuncionarioTexto()
		* 
		* Texto exibido no metodo lerOpcaoParaModificarFuncionario().
		* \return void.
		*/ 
        void opcaoParaModificarFuncionarioTexto();

        /**
		* lerNovoAtributoStrParaModificarFuncionario()
		* 
		* Lê um atributo string de acordo com a opção recebida para modificar um atributo string de um funcionário.
		* \param int Opção de atributo string a ser lido.
		* \return Retorna o atributo string lido para modificação no funcionário.
		*/ 
        std::string lerNovoAtributoStrParaModificarFuncionario(int opcao);

        /**
		* lerNovoAtributoIntParaModificarFuncionario()
		* 
		* Lê um atributo int de acordo com a opção recebida para modificar um atributo int de um funcionário.
		* \param int Opção de atributo int a ser lido.
		* \return Retorna o atributo int lido para modificação no funcionário.
		*/ 
        int lerNovoAtributoIntParaModificarFuncionario(int opcao);

        /**
		* lerNovaDataParaModificarFuncionario()
		* 
		* Lê uma data para modificar a data de ingresso de um funcionário e armazena em um array.
		* \param Ponteiro Aponta para a data que vai ser lida no metodo.
		* \return void.
		*/ 
        void lerNovaDataParaModificarFuncionario(int *data);

        /**
		* lerCodigoParaExcluirFuncionario()
		* 
		* Lê o código de um funcionário para exclui-lo.
		* \return Retorna um inteiro sendo ele o código lido.
		*/ 
        int lerCodigoParaExcluirFuncionario();

        /**
		* lerCodigoParaExibirFuncionario()
		* 
		* Lê o código de um funcionário para exibi-lo.
		* \return Retorna um inteiro sendo ele o código lido.
		*/ 
        int lerCodigoParaExibirFuncionario();

        /**
		* lerTipoParaExibirFuncionarios()
		* 
		* Lê o tipo de designação para exibir os funcionários do tipo.
		* \return Retorna um inteiro sendo ele o tipo lido.
		*/ 
        int lerTipoParaExibirFuncionarios();

        /**
		* lerMesParaCalcularFolhaSalarialEmpresa()
		* 
		* Lê um mês para calcular a folha salarial dos funcionários da empresa.
		* \return Retorna um inteiro sendo ele o mês lido.
		*/ 
        int lerMesParaCalcularFolhaSalarialEmpresa();

        /**
		* lerNomeParaImprimirFolhaSalarialFuncionario()
		* 
		* Lê um nome de um funcionário para imprimir a folha salarial dele.
		* \return Retorna uma string sendo ela o nome lido.
		*/ 
        std::string lerNomeParaImprimirFolhaSalarialFuncionario();

        /**
		* lerCodigoParaImprimirFolhaSalarialFuncionario()
		* 
		* Lê um código de um funcionário para imprimir a folha salarial dele.
		* \return Retorna um inteiro sendo ele o código lido.
		*/ 
        int lerCodigoParaImprimirFolhaSalarialFuncionario();

        /**
		* lerTipoAtributoParaImprimirFolhaSalarialFuncionario()
		* 
		* Lê o tipo do atributo que vai ser usado para imprimir folha salarial de um funcionário, os atributos podem ser código ou nome.
		* \return Retorna um inteiro sendo ele o tipo lido.
		*/ 
        int lerTipoAtributoParaImprimirFolhaSalarialFuncionario();

        /**
		* lerOpcaoParaImprimirFolhaSalarialEmpresa()
		* 
		* Lê a opção de impressão da folha salarial da empresa.
		* \return Retorna um inteiro sendo ele a opção lida.
		*/ 
        int lerOpcaoParaImprimirFolhaSalarialEmpresa();

        /**
		* lerOpcaoParaBuscarFuncionario()
		* 
		* Lê a opção de buscar funcionário.
		* \return Retorna um inteiro sendo ele a opção lida.
		*/ 
        int lerOpcaoParaBuscarFuncionario();

        /**
		* lerTipoInformacaoStrParaBuscarFuncionario()
		* 
		* Lê o tipo da informação string que vai ser usado para buscar um funcionário.
		* \return Retorna um inteiro sendo ele o tipo lido.
		*/ 
        int lerTipoInformacaoStrParaBuscarFuncionario();

        /**
		* lerInformacaoStrParaBuscarFuncionario()
		* 
		* Lê a informação string que vai ser usado para buscar um funcionário.
        * \param int Tipo de informação string que vai ser lida
		* \return Retorna uma string sendo ela a informação lida.
		*/ 
        std::string lerInformacaoStrParaBuscarFuncionario(int tipoInformacao);

        /**
		* lerDataParaBuscarFuncionario()
		* 
		* Lê a data inicial e final de um intervalo que vai ser usado para buscar funcionários nele.
		* \param ponteiro Aponta para o array que armazena a data inicial.
        * \param ponteiro Aponta para o array que armazena a data final.
        * \return void.
		*/ 
        void lerDataParaBuscarFuncionario(int *dataInicial, int *dataFinal);

        /**
		* validaMes()
		* 
		* Valida se o mês recebido é valido.
		* \param string Contem o mês a ser validado.
        * \return Retorna um inteiro sendo ele o mês que foi validado.
		*/ 
        int validaMes(std::string mes);

        /**
		* validaInteiro()
		* 
		* Valida uma string para verificar se ela armazena um inteiro.
		* \param string Contem o texto a ser verificado.
        * \return Retorna um inteiro sendo ele o texto que foi validado na string.
		*/ 
        int validaInteiro(std::string texto);
};

#endif
