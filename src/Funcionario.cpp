#include "Funcionario.h"
//#include "TelefoneException.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(){
    /* ... */
}

Funcionario::~Funcionario(){
    /* ... */
}

Funcionario::Funcionario(int designacao, double taxa)/*:Empresa(nome, CNPJ, data)*/{
    this->designacao = designacao;
    this->taxaAumento = taxa;
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

double Funcionario::getSalario(){
    return this->salario;
}

double Funcionario::getTaxaAumento(){
    return this->taxaAumento;
}

/*
Endereco Funcionario::getEndereco(){
    return this->endereco;
}
*/

/*
std::string Funcionario::getTelefone(){
    return this->telefone;
}
*/

std::string Funcionario::getDesignacao(){
    switch(this->designacao){
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
}

/*
std::string Funcionario::getNomeFuncionario(){
    return this->nomeFuncionario;
}
*/

Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}
/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setSalario(double salario){
    this->salario = salario;
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

void Funcionario::setDataIngresso(Data data){
    this->dataIngresso = data;
}

void Funcionario::setDataIngresso(std::string data){
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
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
