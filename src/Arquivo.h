#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <fstream>
#include "Funcionario.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"
#include "Diretor.h"


#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo
		Arquivo(const char *, const char *, const char *, const char *);
		// A função salvarDadosFuncionario recebe os dados do funcionario e adiciona ao arquivo de dados dele
		void salvarDadosFuncionario(Funcionario &, int);
		
		void criaArquivo(const char *, const char *, const char *, const char *);


		void mostraDadosArquivos(int);
	
		
	private:
		std::fstream arquivoFuncionarios[4];


};
















#endif
