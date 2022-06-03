#include "HistoricoArquivo.h"
#include <iostream>


HistoricoArquivo::HistoricoArquivo() {
	
	saidaHistorico.open("Historico.csv", std::ios::app);
	
	// Caso o arquivo não exista é necessário criar
	if(!saidaHistorico) {
		saidaHistorico.open("Historico.csv", std::ios::out);
		
		// Caso ele n consiga criar
		if(!saidaHistorico) {
			throw TentativaAbrirArquivo("Historico.csv");
		}
		
	}

	saidaHistorico.close();
	
}

/* SetData modificação, recebe o tipo de funcionario que está sendo modificado e então	*/
/* Cria um obj tipo Data para salvar em um vetor a data do computador que foi feita a mudança	*/
void HistoricoArquivo::setDataModificacao(int tipoFuncionario){
	Data *objData = new Data();
	datasModificacoes[tipoFuncionario] = objData->retornaDataComputador();
}

/* A função seta o tipo de modificação que foi realizada	*/
void HistoricoArquivo::setModificacao(int tipoFuncionario,std::string modificacao){
	modificacoes[tipoFuncionario] = modificacao;
}


void HistoricoArquivo::setCodigo(int tipoFuncionario, int codigo) {
	this->codigos[tipoFuncionario] = codigo;
}


int HistoricoArquivo::getCodigo(int tipoFuncionario) {
	return this->codigos[tipoFuncionario];
}


void HistoricoArquivo::setNome(int tipoFuncionario, std::string nomeValor) {
	nome[tipoFuncionario] = nomeValor;
}

std::string HistoricoArquivo::getNome(int tipoFuncionario) {

	return this->nome[tipoFuncionario];
}

/* Printa modificaçao recebe o tipoFuncionario e o codigo dele, e então abre o arquivo .csv	*/
/* E tenta procurar a linha correspondente ao tipo e codigo do usuario	*/
void HistoricoArquivo::printaModificacao(int tipoFuncionario,int codigoFuncionario){
	entradaHistorico.open("Historico.csv", std::ios::in);

	if(!entradaHistorico) {
		throw TentativaAbrirArquivo("Historico.csv");
	}

	
	int tipoEntrada, codigoEntrada;
	std::string linha;

	while(!entradaHistorico.eof()) {

		std::getline(entradaHistorico, linha);
		if(linha.find(std::to_string(tipoFuncionario)) != -1 && linha.find(std::to_string(codigoFuncionario)) != -1)
		{
			std::cout << linha << std::endl;
		}

	}

	entradaHistorico.close();

}

void HistoricoArquivo::escreveArquivoModificacoes(int tipoFuncionario) {
	
	saidaHistorico.open("Historico.csv", std::ios::app);

	if(!saidaHistorico) {
		throw TentativaAbrirArquivo("Historico.csv");
	}
	
	saidaHistorico << tipoFuncionario << "," << getCodigo(tipoFuncionario) << "," << getNome(tipoFuncionario) << "," << modificacoes[tipoFuncionario] << "," << datasModificacoes[tipoFuncionario] << '\n';
	saidaHistorico.close();

}




HistoricoArquivo::~HistoricoArquivo(){

	
}




