#include "Arquivo.h"
#include <iostream>
#include <string.h>



Arquivo::Arquivo(const char *nomeArquivoPresidente, const char * nomeArquivoDiretor, const char * nomeArquivoGerente, const char *nomeArquivoOperador){

	criaArquivo(nomeArquivoPresidente, nomeArquivoDiretor, nomeArquivoGerente, nomeArquivoOperador);
	
}



void Arquivo::criaArquivo(const char *nomeArquivoPresidente, const char * nomeArquivoDiretor, const char * nomeArquivoGerente, const char *nomeArquivoOperador){

	char *nomeArquivo;
	// Cria o arquivo para entrada e saida de dados em formato binario para cada usuário
	for(int i = 0; i < 4; i++){

		switch(i){
			case 0:
				strcpy(nomeArquivo, nomeArquivoPresidente);
				arquivoFuncionarios[i].open(nomeArquivo, std::ios::out | std::ios::in | std::ios::binary);
				break;
			case 1:
				strcpy(nomeArquivo, nomeArquivoDiretor);
				arquivoFuncionarios[i].open(nomeArquivo, std::ios::out | std::ios::in | std::ios::binary);
				break;
			case 2:
				strcpy(nomeArquivo, nomeArquivoGerente);
				arquivoFuncionarios[i].open(nomeArquivo, std::ios::out | std::ios::in | std::ios::binary);
				break;
			case 3:
				strcpy(nomeArquivo, nomeArquivoOperador);
				arquivoFuncionarios[i].open(nomeArquivo, std::ios::out | std::ios::in | std::ios::binary);
				break;
		}
		
		
		if(!arquivoFuncionarios[i]){
			
			switch(i){
				case 0:
					std::cerr << "Nao foi possivel criar o arquivo presidente" << std::endl;
					break;

				case 1:
					std::cerr << "Nao foi possivel criar o arquivo diretor" << std::endl;
					break;

				case 2:
					std::cerr << "Nao foi possivel criar o arquivo gerente" << std::endl;
					break;
				
				case 3:
					std::cerr << "Nao foi possivel criar o arquivo operador" << std::endl;
					break;
			}
			exit(1);
		}

	}
	


	// Agora, deve-se alocar inicialmente uma certa quantidade de dados em cada arquivo
	Presidente presidentes;
	Diretor diretores;
	Gerente gerentes;
	Operador operadores;
	

	for(int i = 0; i < 4; i++){
		
		switch(i){

			case 0:
				for(int i = 0; i < 100; i++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&presidentes), sizeof(Presidente));
				}
				break;
			case 1:
				for(int i = 0; i < 100; i++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&diretores), sizeof(Diretor));
				}
				break;
			case 2:
				for(int i = 0; i < 100; i++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&gerentes), sizeof(Gerente));
				}
				break;
			case 3:
				for(int i = 0; i < 100; i++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&operadores), sizeof(Operador));
				}
				break;
		}
	}

}


void Arquivo::salvarDadosFuncionario(Funcionario &dadosFuncionario, int tipoFuncionario){


	// Vamos primeiro posicionar o ponteiro para a localização que corresponde ao codigo do funcionario
	// Tipo funcionário representa o funcionario pelo numero
	// 0 é o presidente, 1 é o diretor, 2 é o gerente e 3 é o operador
	// Sendo assim, posiciona-se o ponteiro no ponteiro para o arquivo correspondente
	Presidente presidente;
	Gerente gerente;
	Diretor diretor;
	Operador operador;
	
	Funcionario *funcionario;	

	switch(tipoFuncionario){

		// Coloca-se na posição referente ao código
		// Ler o que está contido
		case 0:
			funcionario = &presidente;
			break;

		case 1:
			funcionario = &gerente;
			break;
		
		case 2:
			funcionario =  &diretor;
			break;
		
		case 3:
			funcionario = &operador;

	}
	// Posiciona na posição para dar o get e pegar os dados
	arquivoFuncionarios[tipoFuncionario].seekg((dadosFuncionario.getCodigo() - 1) * sizeof(*funcionario));
	// Ler o que está contido no arquivo correspondente
	arquivoFuncionarios[tipoFuncionario].read(reinterpret_cast < char * > (funcionario), sizeof(*funcionario));


	if(funcionario->getCodigo() == 0){

		// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario correspondente ao arquivo que estamos abrindo
		arquivoFuncionarios[tipoFuncionario].seekp((dadosFuncionario.getCodigo() - 1) * sizeof(*funcionario));

		// Escreve os dados no arquivo correspondente ao tipo de funcionário
      	arquivoFuncionarios[tipoFuncionario].write(reinterpret_cast <const char *> (&dadosFuncionario), sizeof(*funcionario));


	}

	else{
		std::cout << "O funcionario ja existe, deseja atualiza-lo?" << std::endl;
	}
	
		
}



void Arquivo::mostraDadosArquivos(int tipoFuncionario){


	Presidente presidente;
	Gerente gerente;
	Diretor diretor;
	Operador operador;
	
	Funcionario *funcionario;	

	switch(tipoFuncionario){

		// Coloca-se na posição referente ao código
		// Ler o que está contido
		case 0:
			funcionario = &presidente;
			break;

		case 1:
			funcionario = &gerente;
			break;
		
		case 2:
			funcionario =  &diretor;
			break;
		
		case 3:
			funcionario = &operador;

	}
	
	arquivoFuncionarios[tipoFuncionario].seekg(0);

	while(!arquivoFuncionarios[tipoFuncionario].eof())
	{
		arquivoFuncionarios[tipoFuncionario].read(reinterpret_cast < char * > (funcionario), sizeof(*funcionario));

		std::cout << funcionario->getCodigo() << " " << funcionario->getNomeFuncionario() << " " << funcionario->CPF << std::endl;

	}
}

