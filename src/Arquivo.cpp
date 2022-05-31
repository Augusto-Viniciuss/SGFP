#include "Arquivo.h"
#include <iostream>
#include <string.h>





Arquivo::Arquivo(std::string nomeArquivoPresidente, std::string nomeArquivoDiretor, std::string nomeArquivoGerente, std::string nomeArquivoOperador){

	// Salva o nome de cada arquivo no vetor de nomes de arquivos
	nomeArquivos[0] = "Presidente.dat";
	nomeArquivos[1] = "Diretor.dat";
	nomeArquivos[2] = "Gerente.dat";
	nomeArquivos[3] = "Operador.dat";

	bool existe = true;

	for(int i = 0; i < QUANTIA_ARQUIVOS; i++) {
		
		arquivosEntradas[i].open(nomeArquivos[i], std::ios::in);

		if(!arquivosEntradas[i]) {
			existe = false;
		}
		arquivosEntradas[i].close();
	}


	// Só chamamos criaArquivo se os arquivos não existirem
	if(!existe) {
	
		// Cria os arquivos para cada setor
		criaArquivo("Presidente.dat", "Diretor.dat", "Gerente.dat", "Operador.dat");
	}
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


	
	// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario correspondente ao arquivo que estamos abrindo
	arquivoFuncionarios[tipoFuncionario].seekp((dadosFuncionario.getCodigo() - 1) * sizeof(*funcionario));

	// Escreve os dados no arquivo correspondente ao tipo de funcionário
  	arquivoFuncionarios[tipoFuncionario].write(reinterpret_cast <const char *> (&dadosFuncionario), sizeof(*funcionario));
		
		
	historico.setDataModificacao(tipoFuncionario);
	historico.setModificacao(tipoFuncionario,"O usuario foi cadastrado");
	historico.setCodigo(tipoFuncionario, dadosFuncionario.getCodigo());
	historico.escreveArquivoModificacoes(tipoFuncionario);

	

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

		if(funcionario->getCodigo() != 0) {
			std::cout << funcionario->getCodigo() << " " << funcionario->getNome() << " " << funcionario->getCodigo() << std::endl;
		}

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
		std::cout << "Não eh possivel excluir o presidente" << std::endl;
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
		
		historico.setDataModificacao(tipoFuncionario);
		historico.setModificacao(tipoFuncionario,"O usuario foi excluido");
		historico.setCodigo(tipoFuncionario, codigoFuncionario);
		historico.escreveArquivoModificacoes(tipoFuncionario);

			
	}

	arquivoFuncionarios[tipoFuncionario].close();

}


void Arquivo::mostraHistorico(int tipoFuncionario, int codigo)
{
	historico.printaModificacao(tipoFuncionario, codigo);

}


void Arquivo::carregaDados(std::vector < Funcionario * > &funcionariosVec) {

	nomeArquivos[0] = "Presidente.dat";
	nomeArquivos[1] = "Diretor.dat";
	nomeArquivos[2] = "Gerente.dat";
	nomeArquivos[3] = "Operador.dat";

	/* Criação de variáveis de buffer para armazenar temporariamente o dado lido	*/
	Presidente presidenteBuffer;
	Diretor diretorBuffer;
	Gerente gerenteBuffer;
	Operador operadorBuffer;

	Funcionario *funcionario;
	Funcionario *ptrFuncionarioTemp; // Armazena o endereço temporariamente
	

	/* Primeiramente, abra-se o arquivo e verifica se ele já foi criado ou não	*/
	/* Após isso, o ponteiro irá apontar dependendo de qual arquivo está aberto, para uma variável do tipo presidente e assim por diante	*/
	/* Essa variável, irá armazenar os dados lidos até achar um dado válido, ou seja, um dado que possui seu código diferente de 0	*/
	/* Quando for achado um usuário válido, iremos fazer o ponteiro funcionario apontar para uma nova região de memória dependedo de qual tipo de varável foi lida*/
	/* Feito isso, copiamos o conteudo de ptrFuncionarioTemp para Funcionario e então, coloca-se esse endereço no vector		*/
	for(int i = 0; i < QUANTIA_ARQUIVOS; i++) {

		arquivosEntradas[i].open(nomeArquivos[i], std::ios::in | std::ios::binary);

		if(!arquivosEntradas[i]) {
			std::cout << "Nada para atualizar em " <<  nomeArquivos[i] << std::endl;
		}

		/* i = 0 -> Arquivo de presidente
		   i = 1 -> Arquivo de diretor
		   i = 2- > Arquivo de gerente
		   i = 3 -> Arquivo de operador
		Como para cada um deles, o tamanho dos dados são diferentes, o ponteiro irá apontar para cada um adequadamente
		*/
		switch(i) {
				
			case 0:
				ptrFuncionarioTemp = &presidenteBuffer;
				break;

			case 1:
				ptrFuncionarioTemp = &diretorBuffer;
				break;
					
			case 2:
				ptrFuncionarioTemp =  &gerenteBuffer;
				break;
					
			case 3:
				ptrFuncionarioTemp = &operadorBuffer;
				break;
		}
		
		/* Posiciona o ponteiro no inicio	*/
		arquivosEntradas[i].seekg(0);

		/* Ler todos os dados até achar um usuário válido	*/
		while(!arquivosEntradas[i].eof()) {
				
			arquivosEntradas[i].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), sizeof(*ptrFuncionarioTemp));
			
			if(ptrFuncionarioTemp->getCodigo() != 0) {
				
				/* Aponta adequadamente para uma nova região de memória, dependendo de qual arquivo estamos lendo	*/
				/* Toda vez que damos new, há alocação de memória em algum local e retorna seu endereço, armazenando em funcionario	*/
				switch(i) {
					case 0:
						funcionario = new Presidente();
						break;

					case 1:
						funcionario = new Diretor();
						break;
							
					case 2:
						funcionario =  new Gerente();
						break;
							
					case 3:
						funcionario = new Operador();
						break;
				}
				
				// Cópia de memoria
				memcpy(funcionario, ptrFuncionarioTemp, sizeof(*ptrFuncionarioTemp));
				funcionariosVec.push_back(funcionario);
												
			}
			
				
		}
		/* Fecha o arquivo após ler os dados	*/
		arquivosEntradas[i].close();
	}

}
