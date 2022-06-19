#include "Funcionario.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario() {
    setCodigoFuncionario(0);
    
}

Funcionario::Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao) : Pessoa(nome, telefone, CPF, idade, CEP, numeroResidencia) {
    
    setCodigoFuncionario(codigo);
    setDataIngresso(data);
    setDesignacao(designacao);

    for(int i = 0; i < 12; i++) {
        this->folhaSalarial[i] = FolhaSalarial(designacao);
    }
    
}

Funcionario::~Funcionario() {}

/* Inicio dos Get */
int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigoFuncionario(){
    return this->codigoFuncionario;
}

std::string Funcionario::getDesignacaoStr() {
    switch(getDesignacaoInt()){
        case 0:
            return "Operador";
            break;
        case 1:
            return "Gerente";
            break;
        case 2:
            return "Diretor";
            break;
        case 3:
            return "Presidente";
            break;
    }

    return nullptr;
}

int Funcionario::getDesignacaoInt() {
    return this->designacao;
}
 
Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}

FolhaSalarial* Funcionario::getFolhaSalarial(int mes) {
    return &this->folhaSalarial[mes - 1];
}

/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

int Funcionario::validaDesignacao(std::string designacaoStr){
    int desiginacaoInt;
    for(int i = 0; i < designacaoStr.size(); i++){
        if(designacaoStr[i] < '0' || designacaoStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    desiginacaoInt = std::stoi(designacaoStr);

    if(desiginacaoInt < 0 || desiginacaoInt > 3){
        throw CadastrarFuncionarioException("Opção inválida digitada\nDigite a designação entre 0 a 3");
    }

    return desiginacaoInt;
}

void Funcionario::setDataIngresso(int *data){
    this->dataIngresso = Data(data[0], data[1], data[2]);
}

void Funcionario::validaDataIngresso(std::string dataStr, int* dataInt){
    if(dataStr.size() > 10){
        throw CadastrarFuncionarioException("Quantidade inválida de caracteres\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
    }else{
        int dataAux[3];
        int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::string dataStrAux;
        //21 05 2002
        //0123456789
        int j = 0;
        for(int i = 0; i < dataStr.size(); i++){
            if(i == 2 || i == 5){
                if(dataStr[i] != ' '){
                    throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
                }else{
                    dataAux[j++] = stoi(dataStrAux);
                    dataStrAux.clear();
                    continue;
                }
            }

            if(dataStr[i] < '0' || dataStr[i] > '9'){
                throw CadastrarFuncionarioException("Data inválida\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
            }else{
                dataStrAux.push_back(dataStr[i]);
            }
        }
        dataAux[j] = stoi(dataStrAux);

        //cout << dataAux[0] << "/" << dataAux[1] << "/" << dataAux[2] << endl;

        if(dataAux[1] < 1 || dataAux[1] > 12){
            throw CadastrarFuncionarioException("Mês digitado inválido\nDigite um mês entre 1 a 12");
        }else if(dataAux[0] > diasMeses[dataAux[1]]){
            throw CadastrarFuncionarioException("Quantidade de dias incompativeis com o mês digitado");
        }

        if(dataAux[2] < 1000 || dataAux[2] > 9999){
            throw CadastrarFuncionarioException("Ano digitado inválido\nDigite um ano com 4 digitos significativos");
        }

        dataInt[0] = dataAux[0];
        dataInt[1] = dataAux[1];
        dataInt[2] = dataAux[2];
    }
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

int Funcionario::validaCodigoFuncionario(std::string codigoStr){
    int codigoAux;

    for(int i = 0; i < codigoStr.size(); i++){
        if(codigoStr[i] < '0' || codigoStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    codigoAux = std::stoi(codigoStr);

    if(codigoAux <= 0){
        throw CadastrarFuncionarioException("Código inválido\nPermitido apenas código acima de 0");
    }

    return codigoAux;
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
