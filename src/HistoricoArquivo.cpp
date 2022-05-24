#include "HistoricoArquivo.h"
#include <iostream>

void HistoricoArquivo::setDataModificacao(int dia, int mes, int ano){
	Data *objData = new Data(dia, mes, ano);
	datasModificacoes.push_back(objData);
}


void HistoricoArquivo::setModificacao(std::string modificacao){
	modificacoes.push_back(modificacao);
}

void HistoricoArquivo::printaModificacao(int indiceModificacao){
	std::cout << "Data: ";
      	datasModificacoes[indiceModificacao]->exibeData();
	std::cout << std::endl;

	std::cout << "Modificacao realizada: " << modificacoes[indiceModificacao] << std::endl;
}


HistoricoArquivo::~HistoricoArquivo(){

	for(int i = 0; i < datasModificacoes.size(); i++) {

		delete datasModificacoes[i];
	}
}




