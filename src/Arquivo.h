#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <fstream>
#include "Funcionario.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"
#include "Diretor.h"
#include "HistoricoArquivo.h"
#include <vector>
#include "TentativaAbrirArquivo.h"
#include "InvalidoArgumentoArquivoException.h"
#include "HistoricoArquivo.h"

#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		/**
		* Construtor()
		* 
		*	Responsável por carregar o arquivo de folha.csv
		*/
		Arquivo();

		/**
		* atualizaArquivoFolha
		* 
		* \param lista lista de funcionários
		* 
		* Responsável por atualizar o arquivo de folha.csv
		* \return Nada
		*/
		void atualizaArquivoFolha(std::vector < Funcionario *> &funcionariosVec);
		
		/**
		* atualizaArquivoFolha
		* 
		* \param ponteiro para um tipo de funcionário
		* 
		* Responsável por atualizar o arquivo de folha.csv com apenas um funcionário
		* \return Nada
		*/
		void atualizaArquivoFolha(Funcionario *); 


		/**
		* atualizaBaseDadosCsv
		* 
		* \param lista lista de funcionários para salvar na base de dados
		* 
		* Responsável por atualizar a base de dados
		* \return Nada
		*/
		void AtualizaBaseDadosCsv(const std::vector < Funcionario * >&funcionariosVec);
		
		/**
		* addPresidenteBaseDadosCsv
		* 
		* \param ponteiro para um tipo de funcionário
		* 
		* Responsável por atualizar o arquivo de base de dados com apenas um funcionario
		* \return Nada
		*/
		void addPresidenteBaseDadosCsv(Funcionario *);
		

		/**
		* criaArquivoBaseDadosZerado
		*  
		* Responsável por criar o arquivo zerado
		*
		* \return Nada
		*/
		void criaArquivoBaseDadosZerado();
		

		/**
		* CarregaDadosCsv
		* 
		* \param lista de operadores
		* \param lista de gerentes
		* \param lista de diretores
		* \param ponteiro para um tipo de funcionário
		* 
		* Responsável por carregar os dados e inicializar nas listas
		* \return Nada
		*/
		void carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente);
		
		/**
		* getHistoricoArquivo
		*  
		* Responsável por retornar o endereço de um objeto do tipo Historico
		*
		* \return endereço de um objeto historicoArquivo
		*/
		HistoricoArquivo* getHistoricoArquivo();
		
	private:
		
		std::string path = "../.gitignore/Dados/"; /*!< Path para o armazenamento de dados */
		HistoricoArquivo historico; /*!< Objeto de composição com o classe Historico Arquivo */


};
















#endif
