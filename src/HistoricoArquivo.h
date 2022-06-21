#ifndef HISTORICOARQUIVO_H
#define HISTORICOARQUIVO_H


#include <fstream>
#include "Data.h"
#include <string>
#include "TentativaAbrirArquivo.h"


#define QUANTIA_ARQUIVOS 4

class HistoricoArquivo{
	
	public:

		/**
		* Construtor
		* 
		* Inicializa o arquivo de historico
		*/
		HistoricoArquivo();


		/**
		* setDataModificacao()
		*
		* \param int Tipo de funcionário
		* 
		* Armazena a data de modificações dependendo do tipo de funcionário
		*/
		void setDataModificacao(int);


		/**
		* setModificacao()
		*
		* \param int Tipo de funcionário
		* \param string Modificao realizada no funcionário
		* Armazena a modificação referente ao tipo do funcionário
		*/
		void setModificacao(int tipoFuncionario, std::string);
		

		/**
		* setCodigo()
		*
		* \param int Tipo de funcionário
		* \param int Codigo do funcionário
		* Armazena o codigo do funcionário que foi realizada a modificação
		*/
		void setCodigo(int tipoFuncionario, int codigo);

		/**
		* getCodigo()
		*
		* \param int tipo de funcionário
		* 
		* \return retorna o codigo do tipo de funcionário que foi modificado
		*/
		int getCodigo(int);

		/**
		* setNome()
		*
		* \param int Tipo de funcionário
		* \param string Nome do funcionário
		* Armazena a data de modificações dependendo do tipo de funcionário
		*/
		void setNome(int tipoFuncionario, std::string nome);

		/**
		* getNome()
		*
		* \param int tipo de funcionário
		* 
		* \return retorna o nome do funcionário
		*/
		std::string getNome(int);
		
		/**
		* escreveArquivoModificacoes()
		*
		* \param int tipo de funcionário
		* 
		* Escreve as modificações referente ao tipo de funcionário
		*/
		void escreveArquivoModificacoes(int);

		virtual ~HistoricoArquivo();

	private:
		
		std::string modificacoes[QUANTIA_ARQUIVOS]; /*!< Array contendo as modificações dependendo do tipo de funcionário*/
		
		int codigos[QUANTIA_ARQUIVOS]; /*!< Array de codigos dependendo do tipo de funcionário */
		std::string  datasModificacoes[QUANTIA_ARQUIVOS]; /*!< Armazena as datas de modificações referente ao tipo de funcionário */
		std::string nome[QUANTIA_ARQUIVOS]; /*!< Armazena o nome dependendo do tipo de funcionário*/
		std::ofstream saidaHistorico; /*!< stream para saida de dados no arquivo*/
		std::ifstream entradaHistorico; /*!< stream para entrada de dados no arquivo */
		std::string path = "../.gitignore/Dados/"; /*!< path de armazenamento*/


};









#endif 
