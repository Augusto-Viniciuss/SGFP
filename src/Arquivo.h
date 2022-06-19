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
		
		// O construtor irá inicializar o arquivo de Dados inicialmente
		Arquivo();

		// Cria o arquivo Csv
		void criaArquivoCsv(std::vector < Funcionario *> &funcionariosVec);
		
		// Adiciona um usuario no arquivo Csv
		void adicionaArquivoCsv(Funcionario *); //armazena somente do presidente

		// Cria a base de dados csv com todos os dados do vector de funcionario
		void criaBaseDadosCsv(const std::vector < Funcionario * >&funcionariosVec);
		
		// Adiciona presidente na base de dados com um ponteiro para funcionario
		void addPresidenteBaseDadosCsv(Funcionario *);
		
		// Cria a base de dados zerada
		void criaArquivoBaseDadosZerado();
		
		// Carrega todos os dados e adiciona nos vector de operadores, gerentes, diretores e para um ponteiro do tipo funcionario
		void carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente);
			
	private:
		/* Arquivos para saida de dados	*/
		std::ofstream arquivoFuncionariosSaida[QUANTIA_ARQUIVOS];
	
		/* Contém os nomes dos arquivos	*/
		std::string nomeArquivos[QUANTIA_ARQUIVOS];
		/* Arquivos para entrada de dados	*/
		std::ifstream arquivosEntradas[QUANTIA_ARQUIVOS];
	

		
		/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/

		std::string path = "../.gitignore/Dados/"; // path de armazenamento
		


};
















#endif
