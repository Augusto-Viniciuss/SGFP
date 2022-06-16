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

#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo recebendo o nome dos 4 tipo de arquivos
		Arquivo();

		// A função salvarDadosFuncionario recebe os dados do funcionario e adiciona ao arquivo de dados dele
		void salvarDadosFuncionario(Funcionario &, int);
		
		// Criar arquivo irá jogar uma exception
		// Função responsável por criar inicialmente os arquivos
		void criaArquivo(std::string, std::string, std::string, std::string);
		
		// Função responsável por excluir dados, recebe o tipo de funcionario para excluir e seu código 
		void excluiDados(Funcionario *);
		
		void mostraHistorico(int tipoFuncionario, int codigo); 

		void carregaDados(std::vector < Funcionario * > &funcionariosVec, int tipoFuncionario);

		void criaArquivoCsv(const std::vector < Funcionario *> &funcionariosVec);

		void adicionaArquivoCsv(Funcionario *); //armazena somente do presidente
			
	private:
	
		std::ofstream arquivoFuncionariosSaida[QUANTIA_ARQUIVOS];
	

		std::string nomeArquivos[QUANTIA_ARQUIVOS];
		std::ifstream arquivosEntradas[QUANTIA_ARQUIVOS];
		// Arquivos para exclusao de dados
		std::ifstream exclusaoDados[QUANTIA_ARQUIVOS];
	
		std::ofstream outputCsv; // saida de dados apenas para o arquivo csv

		// Histórico do arquivo
		HistoricoArquivo historico;
		/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/

		std::string path = "../.gitignore/Dados/"; // path de armazenamento
		


};
















#endif
