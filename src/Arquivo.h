#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <fstream>
#include "Funcionario.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"
#include "Diretor.h"

#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo
		Arquivo(std::string, std::string, std::string, std::string);
		// A função salvarDadosFuncionario recebe os dados do funcionario e adiciona ao arquivo de dados dele
		void salvarDadosFuncionario(Funcionario &, int);
		
		void criaArquivo(std::string, std::string, std::string, std::string);


		void mostraDadosArquivos(int);
	
		
	private:
		std::fstream arquivoFuncionarios[QUANTIA_ARQUIVOS];
		std::string nomeArquivos[QUANTIA_ARQUIVOS];
	
		


};
















#endif
