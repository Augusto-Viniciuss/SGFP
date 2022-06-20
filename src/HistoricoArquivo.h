#ifndef HISTORICOARQUIVO_H
#define HISTORICOARQUIVO_H


#include <fstream>
#include "Data.h"
#include <string>
#include "TentativaAbrirArquivo.h"


#define QUANTIA_ARQUIVOS 4
class HistoricoArquivo{
	
	public:
		HistoricoArquivo();
		// Recebe a data de modificaçao
		void setDataModificacao(int);
		// Responsável por setar o tipo de modificação daquele usuário
		void setModificacao(int tipoFuncionario, std::string);
		// Printa modificação recebe o indice das modificações

		/* Seta o codigo e pega codigo	*/
		void setCodigo(int tipoFuncionario, int codigo);
		int getCodigo(int);

		/* SetNome e getNome	*/
		void setNome(int tipoFuncionario, std::string nome);
		std::string getNome(int);
		
		/* EScre a modificação	*/
		void escreveArquivoModificacoes(int);

		virtual ~HistoricoArquivo();

	private:
		/* modificacoes, codigos, datas, nome, referem-se à um determinado arquivo	*/
		/* Dependendo do indice, daquela modificação atual	*/
		std::string modificacoes[QUANTIA_ARQUIVOS];
		
		int codigos[QUANTIA_ARQUIVOS]; // Armazena o codigo
		std::string  datasModificacoes[QUANTIA_ARQUIVOS]; // armazena as datas de modificações
		std::string nome[QUANTIA_ARQUIVOS]; // Arazema nome
		std::ofstream saidaHistorico; // stream para saida de dados
		std::ifstream entradaHistorico; // stream para entrada de dados
		std::string path = "../.gitignore/Dados/"; // path de armazenamento


};









#endif 
