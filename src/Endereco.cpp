#include "Endereco.h"
#include "CEPException.h"
#include <fstream>
#include <string.h>

Endereco::Endereco() {}

/* Usa a função de validar o CEP para instanciar o endereço completo */
void Endereco::setEndereco(std::string CEP) {
    validaCEP(CEP);
}

void Endereco::setNumero(int numero){
    this->numero = numero;
}

/*
    Função para validar o número digitado pelo usuário
    Ela recebe uma string como forma de tratamento de erro,
    para caso ocorra do usuário digitar o número de forma
    incorreta
*/
int Endereco::validaNumero(std::string numeroStr){
    int numeroAux;

    /* Verifica se foi digitado algo que não seja um número inteiro */
    for(int i = 0; i < numeroStr.size(); i++){
        if(numeroStr[i] < '0' || numeroStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    /* Após passar pelo primeiro tratamento de erro, o número é salvo */
    numeroAux = std::stoi(numeroStr);

    /* Verifica se o número é menor ou igual a 0 */
    if(numeroAux <= 0){
        throw CadastrarFuncionarioException("Número de residência inválido\nDigite apenas números acima de 0");
    }

    /* Retorna o número já tratado */
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
    /* Verifica se o CEP foi digitado no formato XXXXXXXX */
    if(CEP.size() == 8){
        for(int i = 0; i < 8; i++){
            /* Verifica se foi digitado apenas números */
            if(CEP[i] < '0' || CEP[i] > '9'){
                throw CEPException("Caracter inválido digitado\nDigite apenas números no padrão XXXXXXXX (8 digitos)");
            }
        }
        
        /*
            O comando wget baixa uma página da web. O 'q' deixa o download
            "secreto" por parte do usuário, enquanto o "O" permite escolher
            o nome do arquivo
            O CEP é baixado através do site viacep na extensão json
        */
        std::string comando = "wget -qO ValidaCEP.json https://viacep.com.br/ws/" + CEP + "/json";
        
        system(comando.c_str());

        /* Comando para leitura do arquivo json de CEP */
        std::fstream arq;
        arq.open("ValidaCEP.json", std::ios::in);

        if(arq.is_open()){
            std::string texto;
            int contador = 0, i, tamanho;
            while(!arq.eof()){
                getline(arq, texto);
                int posicao = 0;
                /* As únicas partes do arquivo json relevantes são a de índice 1, 2, 4, 5 e 6*/
                if(contador == 1 || contador == 2 || contador == 4 || contador == 5 || contador == 6){
                    posicao = texto.find(": \"");
                    posicao+=3;
                    tamanho = texto.size()-posicao-2;
                    switch (contador){
                        case 1:
                            /*
                                Quando é digitado um CEP inválido no site do
                                viacep é baixo um arquivo json com a mensagem
                                de "erro" nele
                            */
                            i = texto.find("erro");
                            if(i != -1){
                                /* Mensagem para informar o usuário do CEP inválido */
                                throw CEPException("CEP digitado inválido\nNão foi possível achar a localização");
                            }
                            for(i = 0; i < tamanho && i < 9; i++){
                                /* O item na posição de índice 1 do arquivo json é o CEP */
                                this->CEP[i] = texto[posicao++];
                            }
                            this->CEP[i] = '\0';
                            break;
                        case 2:
                            for(i = 0; i < tamanho && i < 99; i++){
                                /* O item na posição de índice 2 do arquivo json é a rua */
                                this->rua[i] = texto[posicao++];
                            }
                            this->rua[i] = '\0';
                            break;
                        case 4:
                            for(i = 0; i < tamanho && i < 49; i++){
                                /* O item na posição de índice 4 do arquivo json é o bairro */
                                this->bairro[i] = texto[posicao++];
                            }
                            this->bairro[i] = '\0';
                            break;
                        case 5:
                            for(i = 0; i < tamanho && i < 49; i++){
                                /* O item na posição de índice 5 do arquivo json é a cidade */
                                this->cidade[i] = texto[posicao++];
                            }
                            this->cidade[i] = '\0';
                            break;
                        case 6:
                            for(i = 0; i < tamanho && i < 19; i++){
                                /* O item na posição de índice 6 do arquivo json é o estado */
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
        /*
            Apago o arquivo para na próxima leitura de CEP, caso
            tenha algum problema no arquivo json, não ocorra um
            salvamento de dados de forma incorreta
        */
        remove("ValidaCEP.json");
    }else{
        throw CEPException("Quantidade inválida de caracteres\nDigite apenas números no padrão XXXXXXXX (8 digitos)");
    }
}

/* Retorno o endereço completo em uma string */
std::string Endereco::getInformacao() {
    return getRua() + ", " + getBairro() + ", " + getCidade() + ", " + getEstado() + ", " + getCEP() + ", Nº " + std::to_string(getNumero());
}

bool Endereco::comparaEndereco(std::string endereco) {
    char CEPaux[10];
    /* Salvo o CEP passado em um array de char para facilitar a verificação */
    strcpy(CEPaux, endereco.c_str());

    /* Pego o CEP no formato XXXXXXXX e transformo em XXXXX-XXX */
    CEPaux[9] = '\0';
    for(int i = 8; i >= 5; i--){
        if(i == 5) {
            CEPaux[i] = '-';
        } else {
            CEPaux[i] = CEPaux[i-1]; 
        }
    }
    endereco = CEPaux;

    /* Verifico se o CEP digitado é igual ao CEP do funcionário */
    if (endereco.find(getCEP()) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}