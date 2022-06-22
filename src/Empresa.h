#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include <string>
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Data.h"
#include "FuncionarioJaCadastradoExcept.h"
#include "FuncionarioNaoEstaCadastradoExcept.h"
#include "Arquivo.h"


#define OPERADOR 0
#define GERENTE 1
#define DIRETOR 2
#define PRESIDENTE 3
#define BUSCAR_POR_NOME 5
#define BUSCAR_POR_ENDERECO 6
#define QTD_DE_TIPOS 4

class Empresa {
    public:
        /* Construtor padrão sem argumento */
        Empresa();

        /* Destrutor */
        virtual ~Empresa();

        /**
		* Métodos Get
		* \param getQtdFuncionarios Retorna a quantidade de funcionários dependendo da designação. 
		* \return Retorna um inteiro.
		*/
        int getQtdFuncionarios(int tipoFuncionario);
        
        /* Especificações */
        /**
		* addFuncionario()
		* 
		* Adiciona um ponteiro de funcionário ao vector de sua designação, ou no caso do presidente faz ele apontar para o funcionário, e as quantidades dos funcionários de cada tipo é atualizada.
		* \param ponteiro Para um tipo de funcionário.
		* \return Void.
		*/ 
        void addFuncionario(Funcionario *funcionario, int tipoFuncionario);
        
        /**
		* modificarFuncionario()
		* 
		* Modifica um atributo string do funcionário solicitado através do código 
		* \param int Código do funcionário a ser modificado.
        * \param int Opção de qual atributo vai ser modificado.
        * \param string O novo valor para o atributo string.
		* \return Void.
		*/ 
        void modificarFuncionario(int codigo, int opcao, std::string valor);
        
        /**
		* modificarFuncionario()
		* 
		* Modifica um atributo int do funcionário solicitado através do código. 
		* \param int Código do funcionário a ser modificado.
        * \param int Opção de qual atributo vai ser modificado.
        * \param int O novo valor para o atributo int.
		* \return Void.
		*/ 
        void modificarFuncionario(int codigo, int opcao, int valor);
        
        /**
		* modificarFuncionario()
		* 
		* Modifica a data de ingresso do funcionário solicitado através do código.
		* \param int Código do funcionário a ser modificado.
        * \param ponteiro Aponta para um array que está armazenando a nova data.
		* \return Void.
		*/ 
        void modificarFuncionario(int codigo, int *valor);
        
        /**
		* excluirFuncionario()
		* 
		* Exclui o funcionário do codigo solicitado do seu vector, e depois libera a memória alocada para ele.
		* \param int Código do funcionário a ser excluido.
		* \return Void.
		*/ 
        void excluirFuncionario(int codigo);

        /**
		* exibirFuncionario()
		* 
        * Exibe os atributos do funcionário correspondente ao código solicitado.
		* \param int Código do funcionário a ser exibido.
		* \return Void.
		*/ 
        void exibirFuncionario(int codigo);

        /**
		* exibirTodosFuncionarios()
		* 
		* Exibe todos os funcionários que já foram cadastrados
		* \return Void.
		*/ 
        void exibirTodosFuncionarios();

        /**
		* exibirFuncionariosPorTipo()
		* 
		* Exibe todos os funcionários do tipo de designação solicitado que já foram cadastrados.
		* \param int Tipo de designação.
		* \return Void.
		*/ 
        void exibirFuncionariosPorTipo(int tipoFuncionario);

        /**
		* concederAumentoSalarial()
		* 
		* Concede aumento a todos os funcionários já cadastrados, as taxas de aumento são fixas para cada designação.
		* \return Void.
		*/ 
        void concederAumentoSalarial();

        /**
		* calcularFolhaSalarial()
		* 
		* Calcula a folha salarial do mês solicitado para os funcionários já cadastrados, mas só se não tiver sido calculada anteriormente.
		* \param int Mês a se calculado a folha salarial.
		* \return Void.
		*/ 
        void calcularFolhaSalarial(int mes);

        /**
		* imprimirFolhaSalarialFuncionario()
		* 
		* Imprimi a folha salarial dos meses já calculados do funcionário correspondente ao código solicitado.
		* \param int Código do funcionário a ser impresso a folha salarial.
		* \return Void.
		*/ 
        void imprimirFolhaSalarialFuncionario(int codigo);
        
        /**
		* imprimirFolhaSalarialFuncionario()
		* 
		* Imprimi a folha salarial dos meses já calculados do funcionário correspondente ao nome solicitado.
		* \param string Nome do funcionário a ser impresso a folha salarial.
		* \return Void.
		*/ 
        void imprimirFolhaSalarialFuncionario(std::string nome);
        
        /**
		* imprimirFolhaSalarialEmpresa()
		* 
		* Dependendo da opção imprimi a folha salarial da empresa para o ano ou para um mês especifico.
		* \param int Opção de impressão da folha salarial da empresa.
		* \return Void.
		*/ 
        void imprimirFolhaSalarialEmpresa(int opcao);

        /**
		* buscarFuncionario()
		* 
		* Busca um funcionário utilizando o código solicitado.
		* \param int Código do funcionário a ser buscado.
		* \return Retorna um ponteiro para o funcionário encontrado.
		*/ 
        Funcionario* buscarFuncionario(int codigo);

        
        /**
		* buscarFuncionario()
		* 
		* Busca um funcionário utilizando o código solicitado.
		* \param int Código do funcionário a ser buscado.
        * \param ponteiro Ponteiro para apontar para o indice do funcionário encontrado no vector.
        * \param ponteiro Ponteiro para apontar para a designação do funcionário encontrado
		* \return Retorna um ponteiro para o funcionário encontrado.
		*/ 
        Funcionario* buscarFuncionario(int codigo, int *indice, int *designacao);

        /**
		* buscarFuncionariosIntervaloTempo()
		* 
		* Busca e exibe funcionários que possuem a data de ingresso no intervalo de tempo solicitado.
		* \param ponteiro Aponta para o array que armazena a data inicial do intervalo a se buscado.
        * \param ponteiro Aponta para o array que armazena a data final do intervalo a se buscado.
		* \return Void.
		*/ 
        void buscarFuncionariosIntervaloTempo(int *dataInicial, int *dataFinal);
        
        
        /**
		* buscarFuncionariosParcial()
		* 
		* Busca e exibe funcionários que possuem o nome ou o endereço correspondentes a informação solicitada para buscar.
		* \param string Informação usada para buscar funcionários.
        * \param int A opção se a busca parcial vai ser pelo nome ou endereço.
		* \return Void.
		*/ 
        void buscarFuncionariosParcial(std::string informacao, int opcao);
        
    private:
        int qtdFuncionarios[4] = {0}; /*!< Array que armazena a quantidade de funcionários para cada tipo de designação */
        std::vector<Funcionario*> operadores; /*!< Vector que armazena ponteiros para os funcionários do tipo operador */
        std::vector<Funcionario*> gerentes; /*!< Vector que armazena ponteiros para os funcionários do tipo gerente */
        std::vector<Funcionario*> diretores; /*!< Vector que armazena ponteiros para os funcionários do tipo diretor */
        Funcionario *presidente = nullptr; /*!< Ponteiro para armazena o funcionário do tipo presidente */
        
        Arquivo dadosArquivos; /*!< Banco de dados da empresa */
};

#endif