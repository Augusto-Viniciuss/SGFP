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
        template<typename atributo> atributo novoAtributoParaModificarFuncionario();
        int lerCodigoParaExcluirFuncionario();
        int lerCodigoParaExibirFuncionario();
        int lerTipoParaExibirFuncionarios();
        int lerMesParaCalcularFolhaSalarialEmpresa();
        template<typename atributo> atributo lerAtributoParaImprimirFolhaSalarialFuncionario();
        int lerTipoAtributoParaImprimirFolhaSalarialFuncionario();
        int lerOpcaoParaImprimirFolhaSalarialEmpresa();
};

#endif
