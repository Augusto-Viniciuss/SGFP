#ifndef HISTORICOARQUIVO_H
#define HISTORICOARQUIVO_H



#include "Data.h"
#include <string>
#include <vector>

class HistoricoArquivo{
	
	public:
		HistoricoArquivo();
		// Recebe a data de modificaçao
		void setDataModificacao(int, int, int);
		// Responsável por setar o tipo de modificação daquele usuário
		void setModificacao(std::string);
		// Printa modificação recebe o indice das modificações
		void printaModificacao(int);

		virtual ~HistoricoArquivo();

	private:
		std::vector < std::string> modificacoes;
		std::vector < Data * > datasModificacoes;


};









#endif 
