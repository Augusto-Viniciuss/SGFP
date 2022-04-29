#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <fstream>
#include "Funcionario.h"


#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo
		Arquivo(const char *);
		// A função salvarDadosFuncionario recebe os dados do funcionario e adiciona ao arquivo de dados dele
		void salvarDadosFuncionario(Funcionario &);
		
		void criaArquivo(const char *);


		void mostraDadosArquivos();
	
		
	private:
		std::fstream arquivoFuncionario;


};
















#endif
