#include "Pessoa.h"
#include "TelefoneException.h"
#include "CPFException.h"

Pessoa::Pessoa(){
    /* ... */
}

/* Usando os set para deixar os atributos de forma padronizada */
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

/* Valida o nome digitado pelo usuário */
void Pessoa::setNome(std::string nome){
    /* Nomes com menos de 3 caracteres não são validados */
    if(nome.size() < 3){
        throw CadastrarFuncionarioException("Quantidade inválida de caracteres\nDigite um nome com pelo menos 3 dígitos");
    }

    /*
        Verifica se o nome digitado tem mais de 99 caracteres.
        Caso tenha, só é lido até nome[98] e o último indice
        recebe o '\0'
    */
    if(nome.size() > 99){
        for(int i = 0; i < 98; i++){
            /* Nomes com números não são validados */
            if(nome[i] >= '0' && nome[i] <= '9'){
                throw CadastrarFuncionarioException("Caracter inválido digitado\nNão é permitido cadastrar um nome com números");
            }
            this->nome[i] = nome[i];
        }
        this->nome[99] = '\0';
    }else{
        /*
            Caso tenha menos de 99 caracteres, a string é salva por
            completo no array de char
        */
        for(int i = 0; i < nome.size(); i++){
            /* Nomes com números não são validados */
            if(nome[i] >= '0' && nome[i] <= '9'){
                throw CadastrarFuncionarioException("Caracter inválido digitado\nNão é permitido cadastrar um nome com números");
            }
            this->nome[i] = nome[i];
        }
        this->nome[nome.size()] = '\0';
    }
}

/* Valida o telefone digitado pelo usuário */
void Pessoa::setTelefone(std::string telefone){
    /*
        A string precisa ter 11 dígitos seguindo o padrão de
        (XX)XXXXX-XXXX somente com os números
    */
    if(telefone.size() == 11){
        for(int i = 0; i < 11; i++){
            /* Verifica se foi digitado somente números */
            if(telefone[i] < '0' || telefone[i] > '9'){
                throw TelefoneException("Número inválido digitado\nDigite no padrão (XX)XXXXX-XXXX somente com números\nEx: XXXXXXXXXXX (11 dígitos)");
            }
        }
        int j = 0;
        /* Transforma o número de XXXXXXXXXXX em (XX)XXXXX-XXXX*/
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
        throw TelefoneException("Quantidade inválida de caracteres\nDigite no padrão (XX)XXXXX-XXXX somente com números\nEx: XXXXXXXXXXX (11 dígitos)");
    }
}

/* Valida o CPF digitado pelo usuário */
void Pessoa::setCPF(std::string CPF){
    int cpfaux[11];
    
    /* A string precisa ter 11 dígitos */
    if(CPF.size() == 11){
        int digito1,digito2,temp = 0;

        for(int i = 0; i < 11; i++){
            /* Verifica se foi digitado apenas números */
            if(CPF[i] < '0' || CPF[i] > '9'){
                throw CPFException("Caracter inválido digitado\nDigite apenas números no padrão XXXXXXXXXXX (11 dígitos)");
            }
            /* Salva o número lido na variável auxiliar */
            cpfaux[i] = static_cast<int>(CPF[i] - 48);
        }

        /* Achando o primeiro dígito (xxx.xxx.xxx-Xx) */
        /* Multiplicando os 9 primeiros números pela sequência decrescente de 10 a 2 */
        for(char i = 0; i < 9; i++){
            temp += (cpfaux[i] * (10 - i));
        }

        /* Calculando o resto da divisão por 11*/
        temp %= 11;

        if(temp < 2){
            /* Se o resto for menor do que 2 o primero digito é 0 */
            digito1 = 0;
        }else{
            /* Caso não seja, o primeiro digito é 11 menos o resto */
            digito1 = 11 - temp;
        }

        /* Zerando 'temp' para calcular o segundo dígito (xxx.xxx.xxx-xX) */
        /* Multiplicando os 10 primeiros números pela sequência decrescente de 11 a 2 */
        temp = 0;
        for(char i = 0; i < 10; i++){
            temp += (cpfaux[i] * (11 - i));
        }

        /* Calculando o resto da divisão por 11*/
        temp %= 11;

        if(temp < 2){
            /* Se o resto for menor do que 2 o primero digito é 0 */
            digito2 = 0;
        }else{
            /* Caso não seja, o primeiro digito é 11 menos o resto */
            digito2 = 11 - temp;
        }

        /* Verifica se os 2 dígitos encontrados são iguais aos digitados */
        if(digito1 == cpfaux[9] && digito2 == cpfaux[10]){
            /* Caso seja, é salvo na variável de CPF */
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
        throw CPFException("Quantidade inválida de caracteres\nDigite apenas números no padrão XXXXXXXXXXX (11 dígitos)");
    }
    
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

/* Valida a idade digitada pelo usuário */
int Pessoa::validaIdade(std::string idadeStr){
    int idadeAux;
    /* Verifica se foi digitado apenas números */
    for(int i = 0; i < idadeStr.size(); i++){
        if(idadeStr[i] < '0' || idadeStr[i] > '9'){
            throw CadastrarFuncionarioException("Caracter inválido digitado\nDigite apenas números");
        }
    }

    idadeAux = std::stoi(idadeStr);

    /* Não é possível cadastrar funcionário menor de idade */
    if(idadeAux < 18){
        throw CadastrarFuncionarioException("Não é permitido cadastrar funcionário menor de idade");
    }

    /* Não é possível cadastrar funcionário acima de 100 anos*/
    if(idadeAux > 100){
        throw CadastrarFuncionarioException("Não é permitido cadastrar funcionário acima de 100 anos");
    }

    /* Retorna a idade que já passou pelo tratamento de erro */
    return idadeAux;
}

/* Usa o validador de CEP para instaciar o CEP digitado */
void Pessoa::setEndereco(std::string endereco) {
    this->endereco.validaCEP(endereco);
}