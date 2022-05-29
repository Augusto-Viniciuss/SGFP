#include "HistoricoArquivo.h"
#include <iostream>


HistoricoArquivo::HistoricoArquivo() {
	
	saidaHistorico.open("Historico.csv", std::ios::app);
	
	// Caso o arquivo não exista é necessário criar
	if(!saidaHistorico) {
		saidaHistorico.open("Historico.csv", std::ios::out);
		
	
	}

	saidaHistorico.close();
	
}


void HistoricoArquivo::setDataModificacao(int tipoFuncionario){
	Data *objData = new Data();
	datasModificacoes[tipoFuncionario] = objData->retornaDataComputador();
}


void HistoricoArquivo::setModificacao(int tipoFuncionario,std::string modificacao){
	modificacoes[tipoFuncionario] = modificacao;
}


void HistoricoArquivo::setCodigo(int tipoFuncionario, int codigo)
{
	this->codigos[tipoFuncionario] = codigo;
}


int HistoricoArquivo::getCodigo(int tipoFuncionario)
{
	return this->codigos[tipoFuncionario];
}


void HistoricoArquivo::printaModificacao(int tipoFuncionario,int codigoFuncionario){
	entradaHistorico.open("Historico.csv", std::ios::in);

	if(!entradaHistorico) {
		std::cout << "Arquivo não existe." << std::endl;
	}

	
	int tipoEntrada, codigoEntrada;
	std::string linha;

	while(!entradaHistorico.eof()) {

		std::getline(entradaHistorico, linha);
		if(linha.find(std::to_string(tipoFuncionario)) != -1 && linha.find(std::to_string(codigoFuncionario)) != -1)
		{
			break;
		}

	}

	std::cout << linha << std::endl;

	entradaHistorico.close();

}

void HistoricoArquivo::escreveArquivoModificacoes(int tipoFuncionario) {
	
	saidaHistorico.open("Historico.csv", std::ios::app);

	saidaHistorico << tipoFuncionario << "," << getCodigo(tipoFuncionario) << "," << modificacoes[tipoFuncionario] << "," << datasModificacoes[tipoFuncionario] << '\n';

	saidaHistorico.close();

}




HistoricoArquivo::~HistoricoArquivo(){

	
}




