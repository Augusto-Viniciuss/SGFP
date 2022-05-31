#ifndef HISTORICOARQUIVO_H
#define HISTORICOARQUIVO_H


#include <fstream>
#include "Data.h"
#include <string>


#define QUANTIA_ARQUIVOS 4
class HistoricoArquivo{
	
	public:
		HistoricoArquivo();
		// Recebe a data de modificaçao
		void setDataModificacao(int);
		// Responsável por setar o tipo de modificação daquele usuário
		void setModificacao(int tipoFuncionario, std::string);
		// Printa modificação recebe o indice das modificações

		void setCodigo(int tipoFuncionario, int codigo);
		int getCodigo(int);

		void setNome(int tipoFuncionario, std::string nome);
		std::string getNome(int);

		void printaModificacao(int ,int);
		
		void escreveArquivoModificacoes(int);
		virtual ~HistoricoArquivo();

	private:
		std::string modificacoes[QUANTIA_ARQUIVOS];
		int codigos[QUANTIA_ARQUIVOS];
		std::string  datasModificacoes[QUANTIA_ARQUIVOS];
		std::string nome[QUANTIA_ARQUIVOS];
		std::ofstream saidaHistorico;
		std::ifstream entradaHistorico;


};









#endif 
