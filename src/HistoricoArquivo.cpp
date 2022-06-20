#include "HistoricoArquivo.h"
#include <iostream>


HistoricoArquivo::HistoricoArquivo() {
	
	saidaHistorico.open(path + "Historico.csv", std::ios::app);
	
	// Caso o arquivo não exista é necessário criar
	if(!saidaHistorico) {
		saidaHistorico.open(path + "Historico.csv", std::ios::out);
		
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
	Data objData;
	datasModificacoes[tipoFuncionario] = objData.retornaDataComputador();
}

/* A função seta o tipo de modificação que foi realizada	*/
void HistoricoArquivo::setModificacao(int tipoFuncionario,std::string modificacao){
	modificacoes[tipoFuncionario] = modificacao;
}

/* Seta o codigo	*/
void HistoricoArquivo::setCodigo(int tipoFuncionario, int codigo) {
	this->codigos[tipoFuncionario] = codigo;
}

/* Retorna o codigo	*/
int HistoricoArquivo::getCodigo(int tipoFuncionario) {
	return this->codigos[tipoFuncionario];
}

/* Seta o nome	*/
void HistoricoArquivo::setNome(int tipoFuncionario, std::string nomeValor) {
	nome[tipoFuncionario] = nomeValor;
}
/* Retorna o nome	*/
std::string HistoricoArquivo::getNome(int tipoFuncionario) {

	return this->nome[tipoFuncionario];
}


// Função responsável por escrever a modificação
void HistoricoArquivo::escreveArquivoModificacoes(int tipoFuncionario) {
	
	saidaHistorico.open(path + "Historico.csv", std::ios::app);

	if(!saidaHistorico) {
		throw TentativaAbrirArquivo("Historico.csv");
	}
	
	saidaHistorico << tipoFuncionario << "," << getCodigo(tipoFuncionario) << "," << getNome(tipoFuncionario) << "," << modificacoes[tipoFuncionario] << "," << datasModificacoes[tipoFuncionario] << '\n';
	saidaHistorico.close();

}




HistoricoArquivo::~HistoricoArquivo(){

	
}




