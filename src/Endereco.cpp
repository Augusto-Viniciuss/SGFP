#include "Endereco.h"
#include "CEPException.h"
#include <fstream>
#include <string.h>

Endereco::Endereco() {}

void Endereco::setEndereco(std::string CEP) {
    validaCEP(CEP);
}

void Endereco::setNumero(int numero){
    this->numero = numero;
}

int Endereco::validaNumero(std::string numeroStr){
    int numeroAux;

    for(int i = 0; i < numeroStr.size(); i++){
        if(numeroStr[i] < '0' || numeroStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    numeroAux = std::stoi(numeroStr);

    if(numeroAux <= 0){
        throw CadastrarFuncionarioException("Número de residência inválido\nDigite apenas números acima de 0");
    }

    return numeroAux;
}
        
std::string Endereco::getRua(){
    return rua;
}

std::string Endereco::getBairro(){
    return bairro;
}

std::string Endereco::getCidade(){
    return cidade;
}

std::string Endereco::getEstado(){
    return estado;
}

std::string Endereco::getCEP(){
    return CEP;
}

int Endereco::getNumero(){
    return numero;
}

void Endereco::validaCEP(std::string CEP){
    if(CEP.size() == 8){
        for(int i = 0; i < 8; i++){
            if(CEP[i] < '0' || CEP[i] > '9'){
                throw CEPException("Caracter inválido digitado\nDigite apenas números no padrão XXXXXXXX (8 digitos)");
            }
        }
        
        std::string comando = "wget -qO ValidaCEP.json https://viacep.com.br/ws/" + CEP + "/json";
        
        system(comando.c_str());

        std::fstream arq;
        arq.open("ValidaCEP.json", std::ios::in);

        if(arq.is_open()){
            std::string texto;
            int contador = 0, i, tamanho;
            while(!arq.eof()){
                getline(arq, texto);
                int posicao = 0;
                if(contador == 1 || contador == 2 || contador == 4 || contador == 5 || contador == 6){
                    posicao = texto.find(": \"");
                    posicao+=3;
                    tamanho = texto.size()-posicao-2;
                    switch (contador){
                        case 1:
                            i = texto.find("erro");
                            if(i != -1){
                                throw CEPException("CEP digitado inválido\nNão foi possível achar a localização");
                            }
                            for(i = 0; i < tamanho && i < 9; i++){
                                this->CEP[i] = texto[posicao++];
                            }
                            this->CEP[i] = '\0';
                            break;
                        case 2:
                            for(i = 0; i < tamanho && i < 99; i++){
                                this->rua[i] = texto[posicao++];
                            }
                            this->rua[i] = '\0';
                            break;
                        case 4:
                            for(i = 0; i < tamanho && i < 49; i++){
                                this->bairro[i] = texto[posicao++];
                            }
                            this->bairro[i] = '\0';
                            break;
                        case 5:
                            for(i = 0; i < tamanho && i < 49; i++){
                                this->cidade[i] = texto[posicao++];
                            }
                            this->cidade[i] = '\0';
                            break;
                        case 6:
                            for(i = 0; i < tamanho && i < 19; i++){
                                this->estado[i] = texto[posicao++];
                            }
                            this->estado[i] = '\0';
                            break;
                    }
                }
                contador++;
            }
        }else{
            throw CEPException("Erro ao abrir o arquivo\nVerifique sua rede");
        }

        arq.close();

        remove("ValidaCEP.json");
    }else{
        throw CEPException("Quantidade inválida de caracteres\nDigite apenas números no padrão XXXXXXXX (8 digitos)");
    }
}

std::string Endereco::getInformacao() {
    return getRua() + ", " + getBairro() + ", " + getCidade() + ", " + getEstado() + ", " + getCEP() + ", Nº " + std::to_string(getNumero());
}

bool Endereco::comparaEndereco(std::string endereco) {
    char CEPaux[10];
    strcpy(CEPaux, endereco.c_str());

    CEPaux[9] = '\0';
    for(int i = 8; i >= 5; i--){
        if(i == 5) {
            CEPaux[i] = '-';
        } else {
            CEPaux[i] = CEPaux[i-1]; 
        }
    }
    endereco = CEPaux;
    if (endereco.find(getCEP()) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

