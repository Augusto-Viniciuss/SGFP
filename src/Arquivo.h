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
#include "HistoricoArquivo.h"

#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo de Dados inicialmente
		Arquivo();

		// Cria o arquivo Csv
		void atualizaArquivoFolha(std::vector < Funcionario *> &funcionariosVec);
		
		// Adiciona um usuario no arquivo Csv
		void atualizaArquivoFolha(Funcionario *); //armazena somente do presidente

		// Cria a base de dados csv com todos os dados do vector de funcionario
		void AtualizaBaseDadosCsv(const std::vector < Funcionario * >&funcionariosVec);
		
		// Adiciona presidente na base de dados com um ponteiro para funcionario
		void addPresidenteBaseDadosCsv(Funcionario *);
		
		// Cria a base de dados zerada
		void criaArquivoBaseDadosZerado();
		
		// Carrega todos os dados e adiciona nos vector de operadores, gerentes, diretores e para um ponteiro do tipo funcionario
		void carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente);
		
		// Retorna o historico do arquivo para que possa ser atualizado no momento certo
		HistoricoArquivo* getHistoricoArquivo();
		
	private:
		//Path para o caminho da pasta
		std::string path = "../.gitignore/Dados/"; // path de armazenamento
		// Histórico do arquivo
		HistoricoArquivo historico;


};
















#endif
