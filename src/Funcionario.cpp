#include "Funcionario.h"
#include <cstdlib>
#include <ctime>

/* Para o melhor funcionamento do programa, código inicializa com 0 */
Funcionario::Funcionario() {
    setCodigoFuncionario(0);
}

Funcionario::Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string CEP, int numeroResidencia, std::string telefone, int *data, int designacao) : Pessoa(nome, telefone, CPF, idade, CEP, numeroResidencia) { 
    setCodigoFuncionario(codigo);
    setDataIngresso(data);
    setDesignacao(designacao);

    /* A folha salarial é inicializada de acordo com a designação */
    for(int i = 0; i < 12; i++) {
        this->folhaSalarial[i] = FolhaSalarial(designacao);
    }
}

Funcionario::~Funcionario() {}

int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigoFuncionario(){
    return this->codigoFuncionario;
}

/* Retorna a designação em forma de string */
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

    /* Retorna nulo caso o funcionário não tenha designação atribuída ainda */
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

void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

/* Valida a designação digitada pelo usuário */
int Funcionario::validaDesignacao(std::string designacaoStr){
    /* Recebe uma string para haver o tratamento de erro de digitação */
    int desiginacaoInt;
    for(int i = 0; i < designacaoStr.size(); i++){
        /* Verifica se foi digitado somente número */
        if(designacaoStr[i] < '0' || designacaoStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    /* Após tratar, salva em uma variável */
    desiginacaoInt = std::stoi(designacaoStr);

    /* Como as designações vão apenas de 0 a 3, faz um novo tratamento de erro */
    if(desiginacaoInt < 0 || desiginacaoInt > 3){
        throw CadastrarFuncionarioException("Opção inválida digitada\nDigite a designação entre 0 a 3");
    }

    /* Retorna a designação já tratada */
    return desiginacaoInt;
}

void Funcionario::setDataIngresso(int *data){
    this->dataIngresso = Data(data[0], data[1], data[2]);
}

/* Valida a data digitada pelo usuário */
void Funcionario::validaDataIngresso(std::string dataStr, int* dataInt){
    /* Recebe uma string para tratamento de erro caso haja erro de digitação */
    
    /* Verificação pra ver se está com 10 caracteres (XX XX XXXX)*/
    if(dataStr.size() != 10){
        throw CadastrarFuncionarioException("Quantidade inválida de caracteres\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
    }else{
        int dataAux[3];
        int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::string dataStrAux;

        int j = 0;
        for(int i = 0; i < dataStr.size(); i++){
            if(i == 2 || i == 5){
                /* Verifica se tem ' ' no local certo */
                if(dataStr[i] != ' '){
                    throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
                }else{
                    /* Ao chegar no ' ' ele salva o número lido na variável dataAux */
                    dataAux[j++] = stoi(dataStrAux);
                    /* Limpa a string para uma nova leitura */
                    dataStrAux.clear();
                    continue;
                }
            }

            /* Verifica se os outros locais tem apenas números */
            if(dataStr[i] < '0' || dataStr[i] > '9'){
                throw CadastrarFuncionarioException("Data inválida\nDigite a data no padrão XX XX XXXX (com 0 na frente dos números menores do que 10)");
            }else{
                /* Adiciona o número lido na string */
                dataStrAux.push_back(dataStr[i]);
            }
        }
        dataAux[j] = stoi(dataStrAux);

        /* Verifica se o mês digitado está correto */
        if(dataAux[1] < 1 || dataAux[1] > 12){
            throw CadastrarFuncionarioException("Mês digitado inválido\nDigite um mês entre 1 a 12");
        }else if(dataAux[0] > diasMeses[dataAux[1]]){
            /* Verifica se o dia digitado está de acordo com o mês */
            throw CadastrarFuncionarioException("Quantidade de dias incompativeis com o mês digitado");
        }

        /* Verifica se o ano digitado tem 4 dígitos */
        if(dataAux[2] < 1000 || dataAux[2] > 9999){
            throw CadastrarFuncionarioException("Ano digitado inválido\nDigite um ano com 4 digitos significativos");
        }

        /* Após fazer todos os tratamento, salva nas variáveis corretas */
        dataInt[0] = dataAux[0];
        dataInt[1] = dataAux[1];
        dataInt[2] = dataAux[2];
    }
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

/* Valida o código digitado pelo funcionário */
int Funcionario::validaCodigoFuncionario(std::string codigoStr){
    int codigoAux;

    /* Verifica se tem apenas números */
    for(int i = 0; i < codigoStr.size(); i++){
        if(codigoStr[i] < '0' || codigoStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    codigoAux = std::stoi(codigoStr);

    /* Não é permitido um código nulo ou negativo */
    if(codigoAux <= 0){
        throw CadastrarFuncionarioException("Código inválido\nPermitido apenas código acima de 0");
    }

    /* Após fazer os tratamentos de erro, retorna o código correto */
    return codigoAux;
}

/* Gera um número aleatório dentro do intervalo passado */
int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
