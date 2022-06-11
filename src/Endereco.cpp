#include "Endereco.h"
#include "CEPException.h"
#include <fstream>

Endereco::Endereco(){

}

void Endereco::setEndereco(std::string CEP, std::string rua, std::string bairro, std::string cidade, std::string estado){
    int i;
    for(i = 0; i < CEP.size() && i < 10; i++){
        this->CEP[i] = CEP[i];
    }
    this->CEP[i] = '\0';

    for(i = 0; i < rua.size() && i < 99; i++){
        this->rua[i] = rua[i];
    }
    this->rua[i] = '\0';

    for(i = 0; i < bairro.size() && i < 49; i++){
        this->bairro[i] = bairro[i];
    }
    this->bairro[i] = '\0';

    for(i = 0; i < cidade.size() && i < 49; i++){
        this->cidade[i] = cidade[i];
    }
    this->cidade[i] = '\0';

    for(i = 0; i < estado.size() && i < 49; i++){
        this->estado[i] = estado[i];
    }
    this->estado[i] = '\0';
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

void Endereco::validaCEP(std::string CEP){
    if(CEP.size() == 8){
        for(int i = 0; i < 8; i++){
            if(CEP[i] < '0' || CEP[i] > '9'){
                throw CEPException("Caracter inválido digitado");
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
                                throw CEPException("CEP digitado inválido");
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
            throw CEPException("Erro ao abrir o arquivo");
        }

        arq.close();

        remove("ValidaCEP.json");
    }else{
        throw CEPException("Quantidade inválida de caracteres");
    }
}

void Endereco::exibeEndereco() {
    std::cout << getRua() << ", " << getBairro() << ", " << getCidade() << ", " << getEstado() << ", " << getCEP() << std::endl;
}

bool Endereco::comparaEndereco(std::string endereco) {
    if (endereco.find(getCEP()) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

