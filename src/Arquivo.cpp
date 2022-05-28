#include "Arquivo.h"
#include <iostream>
#include <string.h>

using namespace std;



Arquivo::Arquivo(std::string nomeArquivoPresidente, std::string nomeArquivoDiretor, std::string nomeArquivoGerente, std::string nomeArquivoOperador){

	// Cria os arquivos para cada setor
	criaArquivo(nomeArquivoPresidente, nomeArquivoDiretor, nomeArquivoGerente, nomeArquivoOperador);	
	// Salva o nome de cada arquivo no vetor de nomes de arquivos
	nomeArquivos[0] = nomeArquivoPresidente;
	nomeArquivos[1] = nomeArquivoDiretor;
	nomeArquivos[2] = nomeArquivoGerente;
	nomeArquivos[3] = nomeArquivoOperador;
}



void Arquivo::criaArquivo(std::string nomeArquivoPresidente, std::string nomeArquivoDiretor, std::string nomeArquivoGerente, std::string nomeArquivoOperador){

	// Cria o arquivo para entrada e saida de dados em formato binario para cada usuário
	for(int i = 0; i < 4; i++){

		switch(i){
			case 0:
				arquivoFuncionarios[i].open(nomeArquivoPresidente, std::ios::out | std::ios::binary);
				break;
			case 1:
				arquivoFuncionarios[i].open(nomeArquivoDiretor, std::ios::out | std::ios::binary);
				break;
			case 2:
				arquivoFuncionarios[i].open(nomeArquivoGerente, std::ios::out | std::ios::binary);
				break;
			case 3:
				arquivoFuncionarios[i].open(nomeArquivoOperador, std::ios::out | std::ios::binary);
				break;
		}
		
		// Verifica se cada arquivo foi criado corretamente
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

				for(int j = 0; j < 100; j++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&presidentes), sizeof(Presidente));
				}
				break;
			case 1:
				for(int j = 0; j < 100; j++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&diretores), sizeof(Diretor));
				}
				break;
			case 2:
				for(int j = 0; j < 100; j++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&gerentes), sizeof(Gerente));
				}
				break;
			case 3:
				for(int j = 0; j < 100; j++){
					arquivoFuncionarios[i].write(reinterpret_cast < const char *> (&operadores), sizeof(Operador));
				}
				break;
		}

		arquivoFuncionarios[i].close();
	}

	cout << "Digite a data de modificacao seguida por dia, mes e ano";
	int dia, mes, ano;
	cin >> dia >> mes >> ano;
	historico.setDataModificacao(dia, mes, ano);
	historico.setModificacao("Data de criacao");
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
                          break;
  
          }	// Vamos primeiro posicionar o ponteiro para a localização que corresponde ao codigo do funcionario

	// Abre o arquivo para saidas de dados e entrada
	arquivoFuncionarios[tipoFuncionario].open(nomeArquivos[tipoFuncionario], std::ios::out |std::ios::in |  std::ios::binary);
	// Posiciona na posição para dar o get e pegar os dados
	arquivoFuncionarios[tipoFuncionario].seekg((dadosFuncionario.getCodigo() - 1) * sizeof(*funcionario));
	// Ler o que está contido no arquivo correspondente
	arquivoFuncionarios[tipoFuncionario].read(reinterpret_cast < char * > (funcionario), sizeof(*funcionario));


	if(funcionario->getCodigo() == 0){

		// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario correspondente ao arquivo que estamos abrindo
		arquivoFuncionarios[tipoFuncionario].seekp((dadosFuncionario.getCodigo() - 1) * sizeof(*funcionario));

		// Escreve os dados no arquivo correspondente ao tipo de funcionário
  	    	arquivoFuncionarios[tipoFuncionario].write(reinterpret_cast <const char *> (&dadosFuncionario), sizeof(*funcionario));

		int dia, mes, ano;
		cout << "Digite o dia, mes, ano da criacao\n";

		cin >> dia >> mes >> ano;

		historico.setDataModificacao(dia, mes, ano);
		historico.setModificacao("O usuario foi cadastrado");

	}

	else{
		std::cout << "O funcionario ja existe, deseja atualiza-lo?" << std::endl;
	}
	
	// Fecha o arquivo após o tratamento
	arquivoFuncionarios[tipoFuncionario].close();	
		
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
			break;
	}

	// Abre o arquivo para entrada de dados	
	arquivoFuncionarios[tipoFuncionario].open(nomeArquivos[tipoFuncionario], std::ios::in | std::ios::binary);
	
	// Posiciona no local para leitura de dados
	arquivoFuncionarios[tipoFuncionario].seekg(0);

	while(!arquivoFuncionarios[tipoFuncionario].eof())
	{
		arquivoFuncionarios[tipoFuncionario].read(reinterpret_cast < char * > (funcionario), sizeof(*funcionario));

		std::cout << funcionario->getCodigo() << " " << funcionario->getNome() << " " << funcionario->getCPF() << std::endl;

	}

	arquivoFuncionarios[tipoFuncionario].close();
}


void Arquivo::excluiDados(int tipoFuncionario, int codigoFuncionario){

	// Cria os tipos filhos previamente	
	Diretor diretores;
	Gerente gerentes;
	Operador operadores;

	Funcionario *funcionarios;
	// Abre o arquivo 
	
	if(tipoFuncionario == 0){
		cout << "Não eh possivel excluir o presidente" << endl;
	}
	
	// Verifica o tipo de funcionario e faz o ponteiro funcionarios apontar para aquele tipo
	else{
		switch(tipoFuncionario){
			
			case 1:
				funcionarios = &diretores;
				break;
			case 2:
				funcionarios = &gerentes;
				break;
			case 3:
				funcionarios = &operadores;
				break;
		}

		arquivoFuncionarios[tipoFuncionario].open(nomeArquivos[tipoFuncionario], std::ios::out | std::ios::in |std::ios::binary);
		// Posiciona o arquivo no local referente ao codigoFuncionario
		arquivoFuncionarios[tipoFuncionario].seekp((codigoFuncionario - 1) * sizeof(*funcionarios));

		// Coloca um funcionario zerado naquela posição
		arquivoFuncionarios[tipoFuncionario].write(reinterpret_cast <const char * > (funcionarios),  sizeof(*funcionarios) );
		
		cout << "Digite o dia, mes e ano da modificacao\n";
		int dia, mes,  ano;
		
		cin >> dia >> mes >> ano;
		historico.setDataModificacao(dia, mes, ano);
		historico.setModificacao("O usuario foi excluido");

			
	}

	arquivoFuncionarios[tipoFuncionario].close();

}

