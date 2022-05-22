#include "Pessoa.h"
#include "TelefoneException.h"

Pessoa::Pessoa(){
    /* ... */
}

Pessoa::Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, Endereco endereco){
    setNome(nome);
    setTelefone(telefone);
    setCPF(CPF);
    setIdade(idade);
    setEndereco(endereco);
}

Pessoa::Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string endereco){
    setNome(nome);
    setTelefone(telefone);
    setCPF(CPF);
    setIdade(idade);
    setEndereco(endereco);
}

Pessoa::~Pessoa(){
 /* ... */
}

/* Get */
std::string Pessoa::getNome(){
    return nome;
}

std::string Pessoa::getTelefone(){
    return telefone;
}

std::string Pessoa::getCPF(){
    return CPF;
}

int Pessoa::getIdade(){
    return idade;
}

Endereco Pessoa::getEndereco_toObject(){
    return endereco;
}

std::string Pessoa::getEndereco_toString(){ // numero, complemento, rua, bairro, cidade, estado, CEP;
    std::string texto = endereco.getNumero() + "," + endereco.getComplemento() + "," + endereco.getRua() + "," + endereco.getBairro() + "," + endereco.getCidade() + "," + endereco.getEstado() + "," + endereco.getCEP();
    return texto;
}

/* Set */
void Pessoa::setNome(std::string nome){
    if(nome.size() > 99){
        for(int i = 0; i < 98; i++){
            this->nome[i] = nome[i];
        }
        this->nome[99] = '\0';
    }else{
        for(int i = 0; i < nome.size(); i++){
            this->nome[i] = nome[i];
        }
        this->nome[nome.size()] = '\0';
    }
}

void Pessoa::setTelefone(std::string telefone){
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

void Pessoa::setCPF(std::string CPF){

}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

void Pessoa::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Pessoa::setEndereco(std::string endereco){
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