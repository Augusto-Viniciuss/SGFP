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
        int menu();
        void menuTexto();
        Funcionario* lerAtributosFuncionario();
        int lerCodigoParaModificarFuncionario();
        int lerOpcaoParaModificarFuncionario();
        void opcaoParaModificarFuncionarioTexto();
        std::string lerNovoAtributoStrParaModificarFuncionario(int opcao);
        int lerNovoAtributoIntParaModificarFuncionario(int opcao);
        void lerNovaDataParaModificarFuncionario(int *data);
        int lerCodigoParaExcluirFuncionario();
        int lerCodigoParaExibirFuncionario();
        int lerTipoParaExibirFuncionarios();
        int lerMesParaCalcularFolhaSalarialEmpresa();
        std::string lerNomeParaImprimirFolhaSalarialFuncionario();
        int lerCodigoParaImprimirFolhaSalarialFuncionario();
        int lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
        int lerOpcaoParaImprimirFolhaSalarialEmpresa();
        int lerOpcaoParaBuscarFuncionario();
        int lerTipoInformacaoStrParaBuscarFuncionario();
        std::string lerInformacaoStrParaBuscarFuncionario(int tipoInformacao);
        void lerDataParaBuscarFuncionario(int *dataInicial, int *dataFinal);
        int validaMes(std::string mes);
        int validaInteiro(std::string texto);
};

#endif
