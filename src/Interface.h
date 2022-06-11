#ifndef INTERFACE
#define INTERFACE

#include <iostream>
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"

class Interface {
    public:
        int menu();
        Funcionario* lerAtributosFuncionario();
        int lerCodigoParaModificarFuncionario();
        int lerOpcaoParaModificarFuncionario();
        std::string lerNovoAtributoStrParaModificarFuncionario(int opcao);
        int lerNovoAtributoIntParaModificarFuncionario(int opcao);
        int* lerNovaDataParaModificarFuncionario();
        int lerCodigoParaExcluirFuncionario();
        int lerCodigoParaExibirFuncionario();
        int lerTipoParaExibirFuncionarios();
        int lerMesParaCalcularFolhaSalarialEmpresa();
        std::string lerNomeParaImprimirFolhaSalarialFuncionario();
        int lerCodigoParaImprimirFolhaSalarialFuncionario();
        int lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
        int lerOpcaoParaImprimirFolhaSalarialEmpresa();
        int buscarFuncionario();
};

#endif
