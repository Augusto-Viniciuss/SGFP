#include "Interface.h"

int Interface::menu() {
    menuTexto();
    int opcao;
    std::string opcaoStr;

    while(true){
        try{
            getline(std::cin, opcaoStr);
            opcao = validaInteiro(opcaoStr);
            
            if(opcao > 11 or opcao < 0){
                    //std::cout << std::endl << "Opcao invalida, por favor escolha uma opcao valida." << std::endl << std::endl;
                    throw OpcaoInvalidaException("\nOpcao invalida, por favor escolha uma opcao valida.\n");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
            menuTexto();
        }
    }

    std::cout << std::endl;

    return opcao;
}

void Interface::menuTexto(){
    std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
    std::cout << "                        Menu       " << std::endl << std::endl;
    std::cout << "[1] para cadastrar um novo funcionario na empresa." << std::endl;
    std::cout << "[2] para modificar o registro de um funcionario ja cadastrado." << std::endl;
    std::cout << "[3] para excluir o registro de um funcionario." << std::endl;
    std::cout << "[4] para exibir o registro de um funcionario." << std::endl;
    std::cout << "[5] para exibir o registro de todos os funcionarios." << std::endl;
    std::cout << "[6] para exibir o registro de todos os funcionarios de um tipo." << std::endl;
    std::cout << "[7] para Conceder um aumento de salario para os funcionarios." << std::endl;
    std::cout << "[8] para calcular a folha salarial da empresa para um determinado mes." << std::endl;
    std::cout << "[9] para imprimir a folha de salario de um funcionario." << std::endl;
    std::cout << "[10] para imprimir a folha salarial da empresa." << std::endl;
    std::cout << "[11] para buscar um funcionario." << std::endl;
    std::cout << "[0] para sair do programa." << std::endl;
}

Funcionario* Interface::lerAtributosFuncionario() {
    Funcionario *funcionario = new Operador();
    int codigo, idade, designacao, numero;
    std::string nome, CPF, telefone, CEP, aux;
    int data[3];

    while(true){
        try{
            std::cout << "Digite o codigo do funcionario:" << std::endl;
            getline(std::cin, aux);
            codigo = funcionario->validaCodigoFuncionario(aux);
            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }

    while(true){
        try{
            std::cout << "Digite o nome do funcionario:" << std::endl;
            getline(std::cin, nome);

            funcionario->setNome(nome);
            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    while(true) {
        try {
            std::cout << "Digite o CPF do funcionario:" << std::endl;
            getline(std::cin, CPF);
            funcionario->setCPF(CPF);
            break;
        }
        catch(CPFException &cpfException) 
        {
            std::cerr << cpfException.what() << '\n';
        }
    }

    while(true){
        try{
            std::cout << "Digite a idade do funcionario:" << std::endl;
            getline(std::cin, aux);
            idade = funcionario->validaIdade(aux);

            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    while(true) {
        try {
            std::cout << "Digite o CEP do funcionario:" << std::endl;
            getline(std::cin, CEP);
            funcionario->setEndereco(CEP);
            break;
        }
        catch(CEPException &CepException) 
        {
            std::cerr << CepException.what() << '\n';
        }
    }

    while(true){
        try{
            std::cout << "Digite o número da residência do funcionário:" << std::endl;
            getline(std::cin, aux);
            numero = funcionario->getEndereco()->validaNumero(aux);

            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    while(true) {
        try {
            std::cout << "Digite o telefone para contato do funcionario:" << std::endl;
            getline(std::cin, telefone);
            funcionario->setTelefone(telefone);
            break;
        }
        catch(TelefoneException &telefoneException) 
        {
            std::cerr << telefoneException.what() << '\n';
        }
    }

    while(true){
        try{
            std::cout << "Digite a data de ingresso na empresa, na ordem dia, mes e ano separados por espacos:" << std::endl;
            getline(std::cin, aux);
            funcionario->validaDataIngresso(aux, data);

            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    while(true){
        try{
            std::cout << "Qual a designacao do funcionario:" << std::endl;
            std::cout << "Digite 0 para operador" << std::endl << "Digite 1 para gerente" << std::endl << "Digite 2 para diretor" << std::endl << "Digite 3 para presidente" << std::endl;
            getline(std::cin, aux);
            designacao = funcionario->validaDesignacao(aux);

            break;    
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
        
    }

    delete funcionario;

    switch (designacao) {
    case 0:
        funcionario = new Operador(codigo, nome, CPF, idade, CEP, numero, telefone, data, designacao);
        break;
    case 1:
        {
            std::string areaSupervisao;

            std::cout << "Digite a area de supervisao:" << std::endl;
            getline(std::cin, areaSupervisao);
            funcionario = new Gerente(codigo, nome, CPF, idade, CEP, numero, telefone, data, designacao, areaSupervisao);
            break;
        }
    case 2:
        {
            std::string areaSupervisao, areaFormacao;

            std::cout << "Digite a area de supervisao:" << std::endl;
            getline(std::cin, areaSupervisao);
            std::cout << "Digite a area de formacao:" << std::endl;
            getline(std::cin, areaFormacao);
            funcionario = new Diretor(codigo, nome, CPF, idade, CEP, numero, telefone, data, designacao, areaSupervisao, areaFormacao);
            break;
        }
    case 3:
        {
            std::string areaFormacao, formacaoMax;

            std::cout << "Digite a area de formacao:" << std::endl;
            getline(std::cin, areaFormacao);
            std::cout << "Digite a formacao maxima:" << std::endl;
            getline(std::cin, formacaoMax);
            funcionario = new Presidente(codigo, nome, CPF, idade, CEP, numero, telefone, data, designacao, areaFormacao, formacaoMax);
            break;
        }
    }

    return funcionario;
}

int Interface::lerCodigoParaModificarFuncionario() {
    std::string codigoStr;
    int codigo;

    while(true){
        try{
            std::cout << "Digite o codigo do funcionario que deseja modificar:" <<  std::endl;
            getline(std::cin, codigoStr);

            codigo = validaInteiro(codigoStr);
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return codigo;
}

int Interface::lerOpcaoParaModificarFuncionario() {
    int opcao;
    std::string opcaoStr;

    while(true){
        try{
            opcaoParaModificarFuncionarioTexto();
            getline(std::cin, opcaoStr);
            opcao = validaInteiro(opcaoStr);
            if((opcao < 1) or (opcao > 8)) {
                throw OpcaoInvalidaException("Opção Inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return opcao;
}

void Interface::opcaoParaModificarFuncionarioTexto(){
    std::cout << "Digite 1 para modificar a idade" << std::endl;
    std::cout << "Digite 2 para modificar o designacao" << std::endl;
    std::cout << "Digite 3 para modificar a data de ingresso na empresa" << std::endl;
    std::cout << "Digite 4 para modificar o nome" << std::endl;
    std::cout << "Digite 5 para modificar o endereco" << std::endl;
    std::cout << "Digite 6 para modificar o telefone" << std::endl;
    std::cout << "Digite 7 para modificar o CPF" << std::endl;
}

std::string Interface::lerNovoAtributoStrParaModificarFuncionario(int opcao) {
    Funcionario *funcionario = new Operador();
    std::string atributoFuncionario;

    if(opcao == 4) {
        while(true){
            try{
                std::cout << "Digite o novo nome para o funcionario:" << std::endl;
                getline(std::cin, atributoFuncionario);
                funcionario->setNome(atributoFuncionario);
                break;   
            }
            catch(CadastrarFuncionarioException &cadastrarException){
                std::cerr << cadastrarException.what() << '\n';
            }    
        }
        
    } else if(opcao == 5) {
        while(true){
            try{
                std::cout << "Digite o novo CEP para o funcionario:" << std::endl;
                getline(std::cin, atributoFuncionario);
                funcionario->setEndereco(atributoFuncionario);
                break;
            }
            catch(CEPException &CepException){
                std::cerr << CepException.what() << '\n';
            }
        }
        
        //std::cout << atributoFuncionario << std::endl;
    } else if(opcao == 6) {
        while(true){
            try{
                std::cout << "Digite o telefone novo para o funcionario:" << std::endl;
                getline(std::cin, atributoFuncionario);
                funcionario->setTelefone(atributoFuncionario);
                break;
            }
            catch(TelefoneException &telefoneException){
                std::cerr << telefoneException.what() << '\n';
            }    
        }
        
    } else if(opcao == 7) {
        while(true){
            try{
                std::cout << "Digite o CPF novo para o funcionario:" << std::endl;
                getline(std::cin, atributoFuncionario);
                funcionario->setCPF(atributoFuncionario);
                break;
            }
            catch(CPFException &cpfException){
                std::cerr << cpfException.what() << '\n';
            }    
        }
        
    }

    delete funcionario;

    return atributoFuncionario;
}

int Interface::lerNovoAtributoIntParaModificarFuncionario(int opcao) {
    Funcionario *funcionario = new Operador();
    std::string atributoStr;
    int atributoFuncionario;

    if(opcao == 2) {
        while(true){
            try{
                std::cout << "Qual a nova designacao do funcionario:" << std::endl;
                std::cout << "Digite 1 para operador" << std::endl << "Digite 2 para gerente" << std::endl << std::endl << "Digite 3 para diretor" << std::endl << "Digite 4 para presidente" << std::endl;
                getline(std::cin, atributoStr);
                atributoFuncionario = funcionario->validaDesignacao(atributoStr);
                break;
            }
            catch(CadastrarFuncionarioException &cadastrarException){
                std::cerr << cadastrarException.what() << '\n';
            }    
        }
        
    } else if(opcao == 1) {
        while(true){
            try{
                std::cout << "Digite a nova idade para o funcionario:" << std::endl;
                getline(std::cin, atributoStr);
                atributoFuncionario = funcionario->validaIdade(atributoStr);
                break;
            }
            catch(CadastrarFuncionarioException &cadastrarException){
                std::cerr << cadastrarException.what() << '\n';
            }    
        }
        
    }
    
    delete funcionario;

    return atributoFuncionario;
}

void Interface::lerNovaDataParaModificarFuncionario(int *data) {
    Funcionario *funcionario = new Operador();
    std::string atributoStr;

    while(true){
        try{
            std::cout << "Digite a data de ingresso nova, na ordem dia, mes e ano separados por espacos:" << std::endl;
            getline(std::cin, atributoStr);

            funcionario->validaDataIngresso(atributoStr, data);
            break;
        }catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }   
    }

    delete funcionario;
}

int Interface::lerCodigoParaExcluirFuncionario() {
    int codigo;
    std::string codigoStr;

    while(true){
        try{
            std::cout << "Digite o codigo do funcionario que deseja excluir:" << std::endl;
            getline(std::cin, codigoStr);

            codigo = validaInteiro(codigoStr);
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return codigo;
}

int Interface::lerCodigoParaExibirFuncionario() {
    int codigo;
    std::string codigoStr;

    while(true){
        try{
            std::cout << "Digite o codigo do funcionario que deseja ser exibido:" << std::endl;
            getline(std::cin, codigoStr);

            codigo = validaInteiro(codigoStr);
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return codigo;
}

int Interface::lerTipoParaExibirFuncionarios() {
    int tipo;
    std::string tipoStr;

    while(true){
        try{
            std::cout << "Digite o tipo dos funcionarios que voce deseja que seja exibido:" << std::endl;
            std::cout << "Digite 0 para operador" << std::endl << "Digite 1 para gerente" << std::endl << "Digite 2 para diretor" << std::endl << "Digite 3 para presidente" << std::endl;
            getline(std::cin, tipoStr);

            tipo = validaInteiro(tipoStr);

            if(tipo < 0 or tipo > 3) {
                throw OpcaoInvalidaException("Opção inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return tipo;
}

int Interface::lerMesParaCalcularFolhaSalarialEmpresa() {
    int mes;
    std::string mesStr;

    while(true){
        try{
            std::cout << "Digite o mes que deseja ser calculada a folha salarial:" << std::endl;
            getline(std::cin, mesStr);

            mes = validaMes(mesStr);
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }    
    }

    return mes;
}

std::string Interface::lerNomeParaImprimirFolhaSalarialFuncionario() {
    std::string nome;

    std::cout << "Digite o nome completo do funcionario que deseja calcular a folha salarial:" << std::endl;
    getline(std::cin, nome);

    return nome;
}

int Interface::lerCodigoParaImprimirFolhaSalarialFuncionario() {
    int codigo;
    std::string codigoStr;

    while(true){
        try{
            std::cout << "Digite o codigo do funcionario que deseja imprimir a folha salarial:" << std::endl;
            getline(std::cin, codigoStr);

            codigo = validaInteiro(codigoStr);
            break;    
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return codigo;
}

int Interface::lerTipoAtributoParaImprimirFolhaSalarialFuncionario() {
    int tipo;
    std::string tipoStr;

    while(true){
        try{
            std::cout << "Digite 1 para imprimir a folha salarial do funcionario atraves do nome" << std::endl;
            std::cout << "Digite 2 para imprimir a folha salrial do funcionario atraves do codigo dele" << std::endl;
            getline(std::cin, tipoStr);

            tipo = validaInteiro(tipoStr);

            if(tipo < 1 || tipo > 2){
                throw OpcaoInvalidaException("Opção inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return tipo;
}

int Interface::lerOpcaoParaImprimirFolhaSalarialEmpresa() {
    int opcao;
    std::string opcaoStr;

    while(true){
        try{
            std::cout << "Digite 1 para imprimir a folha salarial do ano todo" << std::endl;
            std::cout << "Digite 2 para imprimir a folha salrial para um mes especifico" <<  std::endl;
            getline(std::cin, opcaoStr);

            opcao = validaInteiro(opcaoStr);
            if(opcao < 1 || opcao > 2){
                throw OpcaoInvalidaException("Opção inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return opcao;
}

int Interface::lerOpcaoParaBuscarFuncionario() {
    int opcao;
    std::string opcaoStr;

    while(true){
        try{
            std::cout << "Digite o tipo de busca, 1 por busca parcial, 2 por intervalo tempo: " << std::endl;
            getline(std::cin, opcaoStr);

            opcao = validaInteiro(opcaoStr);

            if(opcao < 1 or opcao > 3) {
                throw OpcaoInvalidaException("Opção inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return opcao;
}

int Interface::lerTipoInformacaoStrParaBuscarFuncionario() {
    int tipoInformacao;
    std::string tipoStr;

    while(true){
        try{
            std::cout << "Digite 1 para buscar por nome e 2 para buscar por CEP:" << std::endl;
            getline(std::cin, tipoStr);

            tipoInformacao = validaInteiro (tipoStr);

            if(tipoInformacao < 1 or tipoInformacao > 2) {
                throw OpcaoInvalidaException("Opção inválida");
            }
            break;
        }
        catch(OpcaoInvalidaException &opcaoInvalida){
            std::cerr << opcaoInvalida.what() << '\n';
        }
    }

    return tipoInformacao;
}

std::string Interface::lerInformacaoStrParaBuscarFuncionario(int tipoInformacao) {
    Funcionario *funcionario = new Operador();
    std::string informacao;

    if(tipoInformacao == 1) {
        std::cout << "Digite o nome:" << std::endl;
        std::getline(std::cin, informacao);
    } else if(tipoInformacao == 2) {
        while(true){
            try{
                std::cout << "Digite o CEP:" << std::endl;
                std::getline(std::cin, informacao);

                funcionario->setEndereco(informacao);
                break;
            }
            catch(CEPException &CepException) {
                std::cerr << CepException.what() << '\n';
            }
        }  
    }

    delete funcionario;
    return informacao;
}

void Interface::lerDataParaBuscarFuncionario(int *dataInicial, int *dataFinal) {
    Funcionario *funcionario = new Operador();
    std::string texto;

    std::cout << "Para buscar Funcionarios por intervalo de tempo digite." << std::endl;

    while(true){
        try{
            std::cout << "Digite a data do inicio do intervalo, na ordem dia, mes e ano separados por espacos: " << std::endl;
            getline(std::cin, texto);

            funcionario->validaDataIngresso(texto, dataInicial);
            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    while(true){
        try{
            std::cout << "Digite a data do fim do intervalo, na ordem dia, mes e ano separados por espacos:" << std::endl;
            getline(std::cin, texto);

            funcionario->validaDataIngresso(texto, dataFinal);
            break;
        }
        catch(CadastrarFuncionarioException &cadastrarException){
            std::cerr << cadastrarException.what() << '\n';
        }
    }
    
    delete funcionario;
}

int Interface::validaMes(std::string mes){
    int mesInt;

    for(int i = 0; i < mes.size(); i++){
        if(mes[i] < '0' || mes[i] > '9'){
            throw OpcaoInvalidaException("Atributo inválido digitado");
        }
    }

    mesInt = std::stoi(mes);
    
    if(mesInt < 1 || mesInt > 12){
        throw OpcaoInvalidaException("Mês inválido digitado");
    }

    return mesInt;
}

int Interface::validaInteiro(std::string texto){
    for(int i = 0; i < texto.size(); i++){
        if(texto[i] < '0' || texto[i] > '9'){
            throw OpcaoInvalidaException("Caracter inválido digitado");
        }
    }

    return std::stoi(texto);
}