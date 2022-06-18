#include "Arquivo.h"
#include <iostream>
#include <string.h>

Arquivo::Arquivo(){

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Salva o nome de cada arquivo no vetor de nomes de arquivos
	nomeArquivos[0] = "Operador.dat";
	nomeArquivos[1] = "Gerente.dat";
	nomeArquivos[2] = "Diretor.dat";
	nomeArquivos[3] = "Presidente.dat";

	bool existe = false;

	
	for(int i = 0; i < QUANTIA_ARQUIVOS; i++) {
		
		arquivosEntradas[i].open((path + nomeArquivos[i]).c_str(), std::ios::in);

		if(!arquivosEntradas[i]) {
			existe = true;
		}
		arquivosEntradas[i].close();
	}


	// Só chamamos criaArquivo se os arquivos não existirem
	if(existe) {
		
		// Cria os arquivos para cada setor
		criaArquivo("Presidente.dat", "Diretor.dat", "Gerente.dat", "Operador.dat");
		
	}
}



void Arquivo::criaArquivo(std::string nomeArquivoPresidente, std::string nomeArquivoDiretor, std::string nomeArquivoGerente, std::string nomeArquivoOperador){

	std::string nomeArquivoErro;

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Cria o arquivo para entrada e saida de dados em formato binario para cada usuário
	for(int i = 0; i < 4; i++){

		switch(i){
			case 3:
				arquivoFuncionariosSaida[i].open(path + nomeArquivoPresidente, std::ios::out);
				break;
			case 2:
				arquivoFuncionariosSaida[i].open(path + nomeArquivoDiretor, std::ios::out);
				break;
			case 1:
				arquivoFuncionariosSaida[i].open(path + nomeArquivoGerente, std::ios::out);
				break;
			case 0:
				arquivoFuncionariosSaida[i].open(path + nomeArquivoOperador, std::ios::out);
				break;
		}
		
		// Verifica se cada arquivo foi criado corretamente
		if(!arquivoFuncionariosSaida[i]){
			
			switch(i){
				case 3:
					nomeArquivoErro = "presidente";
					break;

				case 2:
					nomeArquivoErro = "diretor";
					break;

				case 1:
					nomeArquivoErro = "gerente";
					break;
				
				case 0:
					nomeArquivoErro = "operador";
					break;
			}
			throw TentativaAbrirArquivo(nomeArquivoErro);
		}

	}
	
	// Agora, deve-se alocar inicialmente uma certa quantidade de dados em cada arquivo
	Presidente presidentes;
	Diretor diretores;
	Gerente gerentes;
	Operador operadores;

	for(int i = 0; i < 4; i++){
		/*for(int j = 0; j < 100; j++) {	
			switch(i) {
				
				case 0:
					arquivoFuncionariosSaida[i].write((const char *)(&operadores), sizeof(Operador));
					break;
				case 1:
					arquivoFuncionariosSaida[i].write((const char *) (&gerentes), sizeof(Gerente));
					break;
				case 2:
					arquivoFuncionariosSaida[i].write((const char *) (&diretores), sizeof(Diretor));
					break;
				case 3:
					arquivoFuncionariosSaida[i].write((const char*)(&presidentes), sizeof(Presidente));
					break;
			}
			
		
		}*/
		
	
		arquivoFuncionariosSaida[i].close();
		
	}
	
	

}



void Arquivo::salvarDadosFuncionario(Funcionario *dadosFuncionario, int tipoFuncionario){


	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Salva o nome de cada arquivo no vetor de nomes de arquivos
	nomeArquivos[0] = "Operador.dat";
	nomeArquivos[1] = "Gerente.dat";
	nomeArquivos[2] = "Diretor.dat";
	nomeArquivos[3] = "Presidente.dat";
	// Vamos primeiro posicionar o ponteiro para a localização que corresponde ao codigo do funcionario
    // Tipo funcionário representa o funcionario pelo numero
    // 0 é o presidente, 1 é o diretor, 2 é o gerente e 3 é o operador
    // Sendo assim, posiciona-se o ponteiro no ponteiro para o arquivo correspondente
	// O compilador entende *funcionario como um tipo Funcionario ent ele vai ter esse tamanho, devemos criar um ponteiro para cada tipo//
   
   	size_t tamanhoDados; // Tamanho dos dados que vamos ler e escrever
	Funcionario *funcionario;
	Presidente presidente;
	Diretor diretor;
	Gerente gerente;
	Operador operador;

	// Realiza a troca por conta da diferença
	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	
	bool funcionarioExiste = false; // variável que indica se existe ou não o funcionario
	
    switch(tipoFuncionario){
  
        // Coloca-se na posição referente ao código
        // Ler o que está contido
        case 3:
        	tamanhoDados = sizeof(Presidente);
			funcionario = &presidente;
			break;
  
        case 2:
            tamanhoDados = sizeof(Diretor);
			funcionario = &diretor;
            break;
			
  
        case 1:
            tamanhoDados = sizeof(Gerente);
			funcionario = &gerente;
            break;
  
        case 0:
            tamanhoDados = sizeof(Operador);
			funcionario = &operador;
            break;
  
    }
	
	
	
	
	// Deve-se abrir com in | out para que não haver sobreescrita
	arquivoFuncionariosSaida[tipoFuncionario].open(path + nomeArquivos[tipoFuncionario],  std::ios::in | std::ios::out);

	if(!arquivoFuncionariosSaida[tipoFuncionario].is_open()) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}

	if(tipoFuncionario != 3) {
		// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario correspondente ao arquivo que estamos abrindo
		arquivoFuncionariosSaida[tipoFuncionario].seekp((dadosFuncionario->getCodigoFuncionario() - 1) * tamanhoDados);
	}
	else {
		arquivoFuncionariosSaida[tipoFuncionario].seekp(0);
	}
	// Escreve os dados no arquivo correspondente ao tipo de funcionário
  	arquivoFuncionariosSaida[tipoFuncionario].write(reinterpret_cast <const char *> (dadosFuncionario), tamanhoDados);
	
	
		
		
	historico.setDataModificacao(tipoFuncionario);

	// Se o funcionario existe, é porque foi realizada uma atualização
	if(funcionarioExiste) {
		historico.setModificacao(tipoFuncionario,"O usuario foi atualizado");
	}
	else {
		historico.setModificacao(tipoFuncionario,"O usuario foi cadastrado");
	}

	
	historico.setCodigo(tipoFuncionario, dadosFuncionario->getCodigoFuncionario());
	historico.setNome(tipoFuncionario, dadosFuncionario->getNome());
	historico.escreveArquivoModificacoes(tipoFuncionario);

	
	
	// Fecha o arquivo após o tratamento
	arquivoFuncionariosSaida[tipoFuncionario].close();
	

		
}

void Arquivo::excluiDados(Funcionario *funcionario)
{

	// Cria os tipos filhos previamente
	Diretor diretores;
	Gerente gerentes;
	Operador operadores;
	Presidente presidente;

	Funcionario *ptrFuncionarios;
	size_t tamanhodados;
	
	bool tentaPresidenteExcluir = false;
	// variavel que indica se houve tentativa de exclusão do presidente

	//Throw tentativa falha de excluir o presidente
	if (funcionario->getDesignacaoInt() == 3)
	{
		historico.setModificacao(funcionario->getDesignacaoInt(), "Tentaram excluir o presidente");
		throw InvalidoArgumentoArquivoExcept("Não é possível alterar o presidente.\n");
	}

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Verifica o tipo de funcionario e faz o ponteiro funcionarios apontar para aquele tipo
	switch (funcionario->getDesignacaoInt())
	{
		
		case 2:
			ptrFuncionarios = &diretores;
			tamanhodados = sizeof(Diretor);
			break;
		case 1:
			ptrFuncionarios = &gerentes;
			tamanhodados = sizeof(Gerente);
			break;
		case 0:
			ptrFuncionarios = &operadores;
			tamanhodados = sizeof(Operador);
			break;
	}
	
	
	arquivoFuncionariosSaida[funcionario->getDesignacaoInt()].open(path + nomeArquivos[funcionario->getDesignacaoInt()], std::ios::out | std::ios::in);

	if(!arquivoFuncionariosSaida[funcionario->getDesignacaoInt()]) {
		throw TentativaAbrirArquivo(nomeArquivos[funcionario->getDesignacaoInt()]);
	}


	// Posiciona o arquivo no local referente ao codigoFuncionario
	arquivoFuncionariosSaida[funcionario->getDesignacaoInt()].seekp((funcionario->getCodigoFuncionario() - 1) * tamanhodados);

	// Coloca um funcionario zerado naquela posição
	arquivoFuncionariosSaida[funcionario->getDesignacaoInt()].write((const char *)(ptrFuncionarios), tamanhodados);

	
	historico.setModificacao(funcionario->getDesignacaoInt(), "O usuario foi excluido");
	

	historico.setDataModificacao(funcionario->getDesignacaoInt());
	historico.setCodigo(funcionario->getDesignacaoInt(), funcionario->getCodigoFuncionario());
	historico.setNome(funcionario->getDesignacaoInt(), funcionario->getNome());
	historico.escreveArquivoModificacoes(funcionario->getDesignacaoInt());

	arquivoFuncionariosSaida[funcionario->getDesignacaoInt()].close();
}


void Arquivo::mostraHistorico(int tipoFuncionario, int codigo)
{
	historico.printaModificacao(tipoFuncionario, codigo);

}


void Arquivo::carregaDados(std::vector < Funcionario * > &funcionariosVec, int tipoFuncionario) {

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Salva o nome de cada arquivo no vetor de nomes de arquivos
	nomeArquivos[0] = "Operador.dat";
	nomeArquivos[1] = "Gerente.dat";
	nomeArquivos[2] = "Diretor.dat";
	nomeArquivos[3] = "Presidente.dat";

	/* Criação de variáveis de buffer para armazenar temporariamente o dado lido	*/
	Presidente presidenteBuffer;
	Diretor diretorBuffer;
	Gerente gerenteBuffer;
	Operador operadorBuffer;

	Funcionario *funcionario;
	Funcionario *ptrFuncionarioTemp; // Armazena o endereço temporariamente
	
	size_t tamanhoDados;
	/* Primeiramente, abra-se o arquivo e verifica se ele já foi criado ou não	*/
	/* Após isso, o ponteiro irá apontar dependendo de qual arquivo está aberto, para uma variável do tipo presidente e assim por diante	*/
	/* Essa variável, irá armazenar os dados lidos até achar um dado válido, ou seja, um dado que possui seu código diferente de 0	*/
	/* Quando for achado um usuário válido, iremos fazer o ponteiro funcionario apontar para uma nova região de memória dependedo de qual tipo de varável foi lida*/
	/* Feito isso, copiamos o conteudo de ptrFuncionarioTemp para Funcionario e então, coloca-se esse endereço no vector		*/
	

	arquivosEntradas[tipoFuncionario].open(path + nomeArquivos[tipoFuncionario], std::ios::in);

	if(!arquivosEntradas[tipoFuncionario]) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}

	/* i = 3 -> Arquivo de presidente
		i = 2 -> Arquivo de diretor
		i = 1- > Arquivo de gerente
		i = 0 -> Arquivo de operador
	Como para cada um deles, o tamanho dos dados são diferentes, o ponteiro irá apontar para cada um adequadamente
	*/
	switch(tipoFuncionario) {
		case 2:
			ptrFuncionarioTemp = new Diretor();
			tamanhoDados = sizeof(Diretor);
			break;
				
		case 1:
			ptrFuncionarioTemp = new Gerente();
			tamanhoDados = sizeof(Gerente);
			break;
				
		case 0:
			ptrFuncionarioTemp = new Operador();
			tamanhoDados = sizeof(Operador);
			break;
	}
	
	/* Posiciona o ponteiro no inicio	*/
	arquivosEntradas[tipoFuncionario].seekg(0);

	
	arquivosEntradas[tipoFuncionario].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), tamanhoDados);
	/* Ler todos os dados até achar um usuário válido	*/
	while(!arquivosEntradas[tipoFuncionario].eof()) {
		
		if(ptrFuncionarioTemp->getCodigoFuncionario() != 0) {
			std::cout << ptrFuncionarioTemp->getNome() << std::endl;
			/* Aponta adequadamente para uma nova região de memória, dependendo de qual arquivo estamos lendo	*/
			/* Toda vez que damos new, há alocação de memória em algum local e retorna seu endereço, armazenando em funcionario	*/
			switch(tipoFuncionario) {
				case 2:
					funcionario = new Diretor();
					break;
						
				case 1:
					funcionario =  new Gerente();
					break;
						
				case 0:
					funcionario = new Operador();
					break;
			}
			
			//*funcionario = *ptrFuncionarioTemp;
			// Cópia de memoria
			memcpy(funcionario, ptrFuncionarioTemp, tamanhoDados);
			funcionariosVec.push_back(funcionario);								
		}
		arquivosEntradas[tipoFuncionario].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), tamanhoDados);
		
	}
	/* Fecha o arquivo após ler os dados	*/
	arquivosEntradas[tipoFuncionario].close();
}



Funcionario *Arquivo::carregaPresidente() {
	

	/* Criação de variáveis de buffer para armazenar temporariamente o dado lido	*/
	Presidente presidenteBuffer;

	Funcionario *funcionario;
	Funcionario *ptrFuncionarioTemp; // Armazena o endereço temporariamente
	
	nomeArquivos[3] = "Presidente.dat";
	/* Primeiramente, abra-se o arquivo e verifica se ele já foi criado ou não	*/
	/* Após isso, o ponteiro irá apontar dependendo de qual arquivo está aberto, para uma variável do tipo presidente e assim por diante	*/
	/* Essa variável, irá armazenar os dados lidos até achar um dado válido, ou seja, um dado que possui seu código diferente de 0	*/
	/* Quando for achado um usuário válido, iremos fazer o ponteiro funcionario apontar para uma nova região de memória dependedo de qual tipo de varável foi lida*/
	/* Feito isso, copiamos o conteudo de ptrFuncionarioTemp para Funcionario e então, coloca-se esse endereço no vector		*/
	

	arquivosEntradas[3].open(path + nomeArquivos[3], std::ios::in);

	if(!arquivosEntradas[3]) {
		throw TentativaAbrirArquivo(nomeArquivos[3]);
	}

	
	ptrFuncionarioTemp = &presidenteBuffer;
			
	
	/* Posiciona o ponteiro no inicio	*/
	arquivosEntradas[3].seekg(0);

	
	arquivosEntradas[3].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), sizeof(Presidente));
	/* Ler todos os dados até achar um usuário válido	*/
	
	while(!arquivosEntradas[3].eof()) {	
		if(ptrFuncionarioTemp->getCodigoFuncionario() != 0) {
			std::cout << ptrFuncionarioTemp->getNome() << std::endl;
				
			funcionario = new Presidente();
			
			// Cópia de memoria
			memcpy(funcionario,ptrFuncionarioTemp, sizeof(Presidente));
			arquivosEntradas[3].close();
			return funcionario;							
		}
		arquivosEntradas[3].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), sizeof(Presidente));
	}
	
		
	
	/* Fecha o arquivo após ler os dados	*/
	arquivosEntradas[3].close();
	return nullptr;
	
}


void Arquivo::criaArquivoCsv(const std::vector < Funcionario * > &funcionarioVec) {

	outputCsv.open(path + "Folha.csv", std::ios::app);

	if(!outputCsv) {
		outputCsv.open(path + "Folha.csv", std::ios::out);
		//throw TentativaAbrirArquivo("Folha.csv");
	}

	for(int i = 0; i < funcionarioVec.size(); i++) {
		outputCsv << funcionarioVec[i]->getCodigoFuncionario() << "," << funcionarioVec[i]->getDesignacaoInt() << "," << funcionarioVec[i]->getDesignacaoStr() << ", " << funcionarioVec[i]->getCPF() << ", " << funcionarioVec[i]->getNome() << "," 
		<< funcionarioVec[i]->getTelefone() << "," << funcionarioVec[i]->getIdade() << ", " << funcionarioVec[i]->getDataIngresso().retornaStringData() << "\n";
	}

	outputCsv.close();
}


void Arquivo::adicionaArquivoCsv(Funcionario *presidente) {
	outputCsv.open(path + "Folha.csv", std::ios::app);

	if(!outputCsv) {
		outputCsv.open(path + "Folha.csv", std::ios::out);
		throw TentativaAbrirArquivo("Folha.csv");
	}

	outputCsv << presidente->getCodigoFuncionario() << "," << presidente->getDesignacaoInt()  << ", " << presidente->getCPF() << ", " << presidente->getNome() << "," 
		<< "," << presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "\n";

}

