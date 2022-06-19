#include "Pessoa.h"
#include "TelefoneException.h"
#include "CPFException.h"

Pessoa::Pessoa(){
    /* ... */
}

Pessoa::Pessoa(std::string nome, std::string telefone, std::string CPF, int idade, std::string CEP, int numeroResidencia){
    setNome(nome);
    setTelefone(telefone);
    setCPF(CPF);
    setIdade(idade);
    setEndereco(CEP);
    getEndereco()->setNumero(numeroResidencia);
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

Endereco *Pessoa::getEndereco(){
    return &endereco;
}

/* Set */
void Pessoa::setNome(std::string nome){
    if(nome.size() > 99){
        for(int i = 0; i < 98; i++){
            if(nome[i] >= '0' && nome[i] <= '9'){
                throw CadastrarFuncionarioException("Caracter inválido digitado");
            }
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
            if(telefone[i] < '0' || telefone[i] > '9'){
                throw TelefoneException("Número inválido digitado");
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
        throw TelefoneException("Quantidade inválida de caracteres");
    }
}

void Pessoa::setCPF(std::string CPF){
    int cpfaux[11];
    
    if(CPF.size() == 11){
        int digito1,digito2,temp = 0;

        for(int i = 0; i < 11; i++){
            if(CPF[i] < '0' || CPF[i] > '9'){
                throw CPFException("Caracter inválido digitado");
            }
            cpfaux[i] = static_cast<int>(CPF[i] - 48);
        }

        for(char i = 0; i < 9; i++){
            temp += (cpfaux[i] * (10 - i));
        }

        temp %= 11;

        if(temp < 2){
            digito1 = 0;
        }else{
            digito1 = 11 - temp;
        }

        temp = 0;
        for(char i = 0; i < 10; i++){
            temp += (cpfaux[i] * (11 - i));
        }

        temp %= 11;

        if(temp < 2){
            digito2 = 0;
        }else{
            digito2 = 11 - temp;
        }

        if(digito1 == cpfaux[9] && digito2 == cpfaux[10]){
            int j = 0;
            for(int i = 0; i < 14; i++){
                if(i == 3 || i == 7){
                    this->CPF[i] = '.';
                    continue;
                }
                if(i == 11){
                    this->CPF[i] = '-';
                    continue;
                }
                this->CPF[i] = (cpfaux[j++] + '0');
            }
            this->CPF[14] = '\0';
        }else{
            throw CPFException("CPF inválido");
        }
    }else{
        throw CPFException("Quantidade inválida de caracteres");
    }
    
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

int Pessoa::validaIdade(std::string idadeStr){
    int idadeAux;
    for(int i = 0; i < idadeStr.size(); i++){
        if(idadeStr[i] < '0' || idadeStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado");
        }
    }

    idadeAux = std::stoi(idadeStr);

    if(idadeAux < 18){
        throw CadastrarFuncionarioException("Não é permitido cadastrar funcionário menor de idade");
    }

    if(idadeAux > 100){
        throw CadastrarFuncionarioException("Não é permitido cadastrar funcionário acima de 100 anos");
    }

    return idadeAux;
}

void Pessoa::setEndereco(std::string endereco) {
    this->endereco.validaCEP(endereco);
}