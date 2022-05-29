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


#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo recebendo o nome dos 4 tipo de arquivos
		Arquivo(std::string, std::string, std::string, std::string);

		// A função salvarDadosFuncionario recebe os dados do funcionario e adiciona ao arquivo de dados dele
		void salvarDadosFuncionario(Funcionario &, int);
		
		// Função responsável por criar inicialmente os arquivos
		void criaArquivo(std::string, std::string, std::string, std::string);
		
		// Função responsável por excluir dados, recebe o tipo de funcionario para excluir e seu código 
		void excluiDados(int, int);
		
		void mostraDadosArquivos(int);

		void mostraHistorico(int tipoFuncionario, int codigo); 
		
			
	private:
		std::fstream arquivoFuncionarios[QUANTIA_ARQUIVOS];
		std::string nomeArquivos[QUANTIA_ARQUIVOS];
		// Histórico do arquivo
		HistoricoArquivo historico;
		


};
















#endif
