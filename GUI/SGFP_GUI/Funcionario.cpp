#include "Funcionario.h"
//#include "TelefoneException.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(){
    /* ... */
}

Funcionario::Funcionario(int codigo, std::string nome, std::string CPF, int idade, std::string endereco, std::string telefone, int *data, int designacao) {
    setCodigoFuncionario(codigo);
    //setNomeFuncionario(nome);
    setCPF(CPF);
    setIdade(idade);
    setEndereco(endereco);
    //setDataIngresso(data);
    setDesignacao(designacao);
    setTaxaAumento();
    this->folhaSalarial[12] = {-1};
}

/* Inicio dos Get */
int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigo(){
    return this->codigoFuncionario;
}

/*
int Funcionario::getIdade(){
    return this->idade;
}
*/

double Funcionario::getSalarioBase(){
    return this->salarioBase;
}

double Funcionario::getSalarioLiquido() {
    return this->salarioLiquido;
}

double Funcionario::getDescontosSalario() {
    return this->descontosSalario;
}

double Funcionario::getTaxaAumento(){
    return this->taxaAumento;
}


Endereco Funcionario::getEndereco(){
    return this->endereco;
}


/*
std::string Funcionario::getTelefone(){
    return this->telefone;
}
*/

std::string Funcionario::getDesignacaoStr(){
    switch(getDesignacaoInt()){
        case 1:
            return "Operador";
            break;
        case 2:
            return "Gerente";
            break;
        case 3:
            return "Diretor";
            break;
        case 4:
            return "Presidente";
            break;
    }

    return nullptr;
}

int Funcionario::getDesignacaoInt() {
    return this->designacao;
}
 
/*
std::string Funcionario::getNomeFuncionario(){
    return this->nomeFuncionario;
}
*/

Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}

double Funcionario::getSalarioMensal(int mes) {
    return this->folhaSalarial[mes - 1];
}
/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setSalarioBase(double salario){
    this->salarioBase = salario;
    setSalarioLiquido();
}

void Funcionario::setSalarioLiquido() {
    double salario, aux;

    salario = aux = getSalarioBase();
    
    if (salario <= 1212.00) {
        salario += salario * 0.075;
    } else if (salario >= 1212.01 and salario <= 2427.35) {
        salario += salario * 0.09;
    } else if (salario >= 2427.36 and salario <= 3641.03) {
        salario += salario * 0.12;
    } else if (salario >= 3641.04 and salario <= 7087.22) {
        salario += salario * 0.14;
    }

    if (salario >= 1903.99 and salario <= 2826.65) {
        salario += salario * 0.075;
    } else if (salario >= 2826.66 and salario <= 3751.05) {
        salario += salario * 0.15;
    } else if (salario >= 3751.06 and salario <= 4664.68) {
        salario += salario * 0.2250;
    } else if (salario > 4664.68) {
        salario += salario * 0.2750;
    }

    setDescontosSalario(aux - salario);

    this->salarioLiquido = salario;
}

void Funcionario::setDescontosSalario(double desconto) {    
    this->descontosSalario = desconto;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

/*
void Funcionario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}
*/

/*
void Funcionario::setEndereco(std::string endereco){
    Endereco aux;
    std::string numero, complemento, rua, bairro, cidade, estado, CEP;
    int j = 0;
    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        numero[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        complemento[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        rua[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        bairro[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        cidade[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        estado[i] = endereco[j++];
    }

    for(int i = 0; i < endereco.size(); i++){
        if(endereco[j] == ','){
            j++;
            break;
        }
        CEP[i] = endereco[j++];
    }

    aux.setEndereco(numero, complemento, rua, bairro, cidade, estado, CEP);
    this->endereco = aux;
}
*/

/*
void Funcionario::setTelefone(std::string telefone){
    if(telefone.size() == 11){
        for(int i = 0; i < 11; i++){
            if(telefone[i] < '0' || telefone[i] > 9){
                throw TelefoneException("Numero invalido digitado");
            }
        }
        int j = 0;
        for(int i = 0; i < 14; i++){
            if(i == 0){
                this->telefone[i] = '(';
                continue;
            }
            if(i == 3){
                this->telefone[i] = ')';
                continue;
            }
            if(i == 9){
                this->telefone[i] = '-';
                continue;
            }
            this->telefone[i] = telefone[j++];
        }
        this->telefone[14] = '\0';
        
    }else{
        throw TelefoneException("Quantidade insuficiente de caracteres");
    }
}
*/

/*
void Funcionario::setNomeFuncionario(std::string nome){
    if(nome.size() > 99){
        for(int i = 0; i < 98; i++){
            this->nomeFuncionario[i] = nome[i];
        }
        this->nomeFuncionario[99] = '\0';
    }else{
        for(int i = 0; i < nome.size(); i++){
            this->nomeFuncionario[i] = nome[i];
        }
        this->nomeFuncionario[nome.size()] = '\0';
    }
}
*/

void Funcionario::setDataIngresso(int *data){
    this->dataIngresso = Data(data[0], data[1], data[2]);
}

/*void Funcionario::setDataIngresso(std::string data){
    Data *aux;
    std::string dia, mes, ano;

    int j = 0;
    for(int i = 0; i < data.size(); i++){
        if(data[j] == '/'){
            j++;
            break;
        }
        dia[i] = data[j++];
    }

    for(int i = 0; i < data.size(); i++){
        if(data[j] == '/'){
            j++;
            break;
        }
        mes[i] = data[j++];
    }

    for(int i = 0; i < data.size(); i++){
        if(data[j] == '/'){
            j++;
            break;
        }
        ano[i] = data[j++];
    }

    aux = new Data(std::stoi(dia), std::stoi(mes), std::stoi(ano));

    this->dataIngresso = *aux;
}*/

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

void Funcionario::setTaxaAumento() {
    if(getDesignacaoInt() == 0) {
        this->taxaAumento = 0.05;
    } else if(getDesignacaoInt() == 1) {
        this->taxaAumento = 0.10;
    } else if(getDesignacaoInt() == 2) {
        this->taxaAumento = 0.20;
    } else if(getDesignacaoInt() == 3) {
        this->taxaAumento = 0.30;
    }
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}