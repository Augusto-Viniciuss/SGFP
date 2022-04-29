#include "Arquivo.h"
#include <iostream>




Arquivo::Arquivo(const char *nomeArquivo){

	criaArquivo(nomeArquivo);
	
}



void Arquivo::criaArquivo(const char *nomeArquivo){

	// Cria o arquivo para entrada e saida de dados em formato binario
	arquivoFuncionario.open(nomeArquivo, std::ios::out | std::ios::in | std::ios::binary);

	if(!arquivoFuncionario){

		std::cerr << "Nao foi possivel criar o arquivo" << std::endl;
		exit(1);
	}

	Funcionario funcionario;

	// Inicializa uma certa quantidade, para poder organizar os if e else, devemos mudar o valor 100 para o tamanho do vetor de funcionarios
	for(int i = 0; i < 100; i++)
	{
		arquivoFuncionario.write(reinterpret_cast < const char *> (&funcionario), sizeof(Funcionario));
	}



}


void Arquivo::salvarDadosFuncionario(Funcionario &dadosFuncionario){



	// Vamos primeiro posicionar o ponteiro para a localização que corresponde ao codigo do funcionario
	arquivoFuncionario.seekg((dadosFuncionario.getCodigo() - 1) * sizeof(Funcionario));

	Funcionario funcionario;
	
	// Vamos ler o que está contido
	arquivoFuncionario.read(reinterpret_cast < char * > (&funcionario), sizeof(Funcionario));	



	if(funcionario.getCodigo() == 0){

		// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario
		arquivoFuncionario.seekp((dadosFuncionario.getCodigo() - 1) * sizeof(Funcionario));

      	 	arquivoFuncionario.write(reinterpret_cast <const char *> (&dadosFuncionario), sizeof(Funcionario));


	}

	else{
		std::cout << "O funcionario ja existe, deseja atualiza-lo?" << std::endl;
	}
	
		
	



}



void Arquivo::mostraDadosArquivos(){


	Funcionario funcionario;
	
	arquivoFuncionario.seekg(0);

	while(!arquivoFuncionario.eof()){

		arquivoFuncionario.read(reinterpret_cast < char * > (&funcionario), sizeof(Funcionario));

		std::cout << funcionario.getCodigo() << " " << funcionario.nome << " " << funcionario.CPF << std::endl;

	}
}

