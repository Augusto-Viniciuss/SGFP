#include "Arquivo.h"
#include <iostream>
#include <string.h>
#include <sstream>


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

	/* Criação da folha CSV somente com os titulos 	*/
	std::ofstream outputCsv((path + "Folha.csv").c_str(), std::ios::out);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Folha.csv");
	}
	outputCsv << "Codigo" << "," << "Designação," << "CPF," << "Nome," << "Telefone," << "Idade," << "Data Ingresso, " << "Rua," << "Bairro," << "Cidade, " << "Estado, " << "CEP," << "Numero, " << "Area de Supervisão, "
	<< "Area de formacao, " << "Formação máxima," << "Salario Base" << "\n";
	outputCsv.close();



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



void Arquivo::criaArquivoCsv(std::vector < Funcionario * > &funcionarioVec) {

	
	std::ofstream outputCsv((path + "Folha.csv").c_str(), std::ios::app);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	std::string areaSupervisao, areaFormacao, formacaoMaxima;
	
	for(int i = 0; i < funcionarioVec.size(); i++) {

		if(funcionarioVec[i]->getDesignacaoInt() == 0 ) {
			areaSupervisao = "Nenhuma";
			areaFormacao = "Nenhuma";
			formacaoMaxima = "Nenhuma";
		}
		else if(funcionarioVec[i]->getDesignacaoInt() == 1 ) {
			areaSupervisao =((Gerente*)funcionarioVec[i])->getAreaSupervisao();
			areaFormacao = "Nenhuma";
			formacaoMaxima = "Nenhuma";
		}
		else if(funcionarioVec[i]->getDesignacaoInt() == 2 ) {
			areaSupervisao =((Diretor*)funcionarioVec[i])->getAreaSupervisao();
			areaFormacao = ((Diretor*)funcionarioVec[i])->getAreaFormacao();
			formacaoMaxima = "Nenhuma";
		}

		
		outputCsv << funcionarioVec[i]->getCodigoFuncionario() << ","  << funcionarioVec[i]->getDesignacaoStr() << "," << funcionarioVec[i]->getCPF() << ", " << funcionarioVec[i]->getNome() << "," 
		<< funcionarioVec[i]->getTelefone() << "," << funcionarioVec[i]->getIdade() << ", " << funcionarioVec[i]->getDataIngresso().retornaStringData() << "," << funcionarioVec[i]->getEndereco()->getInformacao() << ","
		<< areaSupervisao << "," << areaFormacao << "," << formacaoMaxima << "," << funcionarioVec[i]->getFolhaSalarial(1)->getSalarioBase() << "\n";
		

	}

	outputCsv.close();
}


void Arquivo::adicionaArquivoCsv(Funcionario *presidente) {
	std::fstream outputCsv((path + "Folha.csv").c_str(), std::ios::out);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	outputCsv << presidente->getCodigoFuncionario() << ","  << presidente->getDesignacaoStr() << "," << presidente->getCPF() << ", " << presidente->getNome() << "," 
		<< presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "," << presidente->getEndereco()->getInformacao() << ","
		<< "Nenhuma" << "," << ((Presidente *)presidente)->getAreaFormacao() << "," << ((Presidente*)presidente)->getFormacaoMax() << "," << presidente->getFolhaSalarial(1)->getSalarioBase() << "\n";
		
	outputCsv.close();
}

void Arquivo::criaArquivoBaseDadosZerado() {
	
	std::ofstream outputCsv((path + "Dados.csv").c_str(), std::ios::out);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}
	outputCsv.close();
}

void Arquivo::criaBaseDadosCsv(const std::vector < Funcionario *> &funcionarioVec) {
	
	std::ofstream outputCsv;
	outputCsv.open((path + "Dados.csv"), std::ios::app);

	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	std::string areaSupervisao, areaFormacao, formacaoMaxima;
	
	for(int i = 0; i < funcionarioVec.size(); i++) {
		
		
		if(funcionarioVec[i]->getDesignacaoInt() == 0 ) {
			areaSupervisao = "Nenhuma";
			areaFormacao = "Nenhuma";
			formacaoMaxima = "Nenhuma";
		}
		else if(funcionarioVec[i]->getDesignacaoInt() == 1 ) {
			areaSupervisao =((Gerente*)funcionarioVec[i])->getAreaSupervisao();
			areaFormacao = "Nenhuma";
			formacaoMaxima = "Nenhuma";
		}
		else if(funcionarioVec[i]->getDesignacaoInt() == 2 ) {
			areaSupervisao =((Diretor*)funcionarioVec[i])->getAreaSupervisao();
			areaFormacao = ((Diretor*)funcionarioVec[i])->getAreaFormacao();
			formacaoMaxima = "Nenhuma";
		}
		outputCsv << funcionarioVec[i]->getDesignacaoInt() << "," << funcionarioVec[i]->getCodigoFuncionario() << "," << funcionarioVec[i]->getCPF() << ", " << funcionarioVec[i]->getNome() << "," 
		<< funcionarioVec[i]->getTelefone() << "," << funcionarioVec[i]->getIdade() << ", " << funcionarioVec[i]->getDataIngresso().retornaStringData() << "," << funcionarioVec[i]->getEndereco()->getCEP()<< "," <<
		funcionarioVec[i]->getEndereco()->getNumero()<< "," << areaSupervisao << "," << areaFormacao << "," << formacaoMaxima << "," << funcionarioVec[i]->getFolhaSalarial(1)->getSalarioBase() << "\n";
		

	}

	outputCsv.close();

}

void Arquivo::addPresidenteBaseDadosCsv(Funcionario *presidente) {
	std::ofstream outputCsv;
	outputCsv.open((path + "Dados.csv"), std::ios::app);

	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	
	outputCsv << presidente->getDesignacaoInt() << "," << presidente->getCodigoFuncionario() << "," << presidente->getCPF() << ", " << presidente->getNome() << "," 
	<< presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "," << presidente->getEndereco()->getCEP()<< "," <<
	presidente->getEndereco()->getNumero()<< "," << "Nenhuma" << "," <<((Presidente *)presidente)->getAreaFormacao() << "," << ((Presidente*)presidente)->getFormacaoMax() << "," << presidente->getFolhaSalarial(1)->getSalarioBase() << "\n";
		

	

	outputCsv.close();
}

void Arquivo::carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente) {
	std::ifstream inputCsv((path + "Dados.csv").c_str(), std::ios::in);

	if(!inputCsv) {
		std::cout << "O arquivo será criado sem nenhum dado, por favor rode o porgrama novamente" << std::endl;
		std::ifstream inputCsv((path + "Dados.csv").c_str(), std::ios::app);
		inputCsv.close();

		throw TentativaAbrirArquivo("Dados.csv");
	}

	std::string linha, buffer;
	std::vector < std::string > palavras;
	std::string dataBuffer;
	char *doubleBuffer;
	
	
	Funcionario *funcionario;
	int data[3];

	std::string nome, cpf, telefone, cep, areaSupervisao, areaFormacao, formacaMaxima;
	double salarioBase;
	int codigo, idade, numero;
	bool existePresida = false;
	
	
	while(1) {
		
		getline(inputCsv, linha);
		if(inputCsv.eof()) {
			break;
		}

		std::stringstream dados(linha);

		while(getline(dados, buffer,',')) {
			palavras.push_back(buffer);
			std::cout << buffer << " ";
			
		}

		// Vamos verificar seu tipo e percorrer os dados na seguinte ordem
		//Codigo, cpf, nome, telefone, idade, data de entrada, cep, numero
		//Area de supervisao, area de formacao, formacao maxima e salario base 
		int indice = 0;

		for(int i = 0; i < palavras[i].size(); i++) {
			std::cout << palavras[i] << " ";
		}
		
		std::string cpfBuffer;
		std::string cepBuffer;
		int primeiraLetraNome = 0;
		for(int i = 1; i < palavras.size(); i++) {

			switch(i) {
				
				case 1:
					codigo = stoi(palavras[i]);
					break;
				case 2:
					// Temos o seguindo cpf: 118.196.924-77
					cpfBuffer.clear();

					for(int j = 0; j < palavras[i].size(); j++) {
						
						if(palavras[i][j] != '.' && palavras[i][j] != '-') {
							cpfBuffer.push_back(palavras[i][j]);
						}
					}
					cpf = cpfBuffer;
					break;
				case 3:
					
					
					nome = palavras[i];
					// Caso eu tenha 4 espaços e leandro devo apagar tudo até leandro
					for(int j = 0; j < palavras[i].size(); j++) {
						if(palavras[i][j] != ' ') {
							if(j != 0) {
								nome.erase(nome.begin(), nome.begin() + j);
							}
							
							break;
						}
						
					}
					break;
				case 4:
					telefone = palavras[i];
					//Temos (83)
					telefone.erase(telefone.begin(), telefone.begin() + 1);
					// Temos 83)
					telefone.erase(telefone.begin() + 2, telefone.begin() + 3);
					// temos 8398790-
					telefone.erase(telefone.begin() + 7, telefone.begin() + 8);
					break;
				case 5:
					idade = stoi(palavras[i]);
					break;
				case 6:

					dataBuffer.clear();
					
					for(int j = 0; j < palavras[i].size(); j++) {
						//27/04/2002
						
						if(palavras[i][j] != '/') {
							dataBuffer.push_back(palavras[i][j]);
							
						}
						if(j == palavras[i].size() - 1) {
							data[indice] = stoi(dataBuffer);
							dataBuffer.clear();
						}

						else if (palavras[i][j] == '/'){
							data[indice] = stoi(dataBuffer);
							indice++;
							std::cout << dataBuffer << std::endl;
							dataBuffer.clear();
						}
					}
					break;

				case 7:
					// Temos 58052-310
					cep = palavras[i];
					cep.erase(cep.begin() + 5, cep.begin() + 6);
					break;
				
				case 8:
					numero = stoi(palavras[i]);
					break;
				case 9:
					areaSupervisao = palavras[i];
					break;
				case 10:
					areaFormacao = palavras[i];
					break;
				case 11:
					formacaMaxima = palavras[i];
					break;
				case 12:
					salarioBase = strtod(palavras[i].c_str(), &doubleBuffer);
					break;
			}
		}
		

		if(stoi(palavras[0]) == 0) {
			funcionario = new Operador(codigo, nome, cpf, idade, cep, numero, telefone, data, 0);
			operadores.push_back(funcionario);
		}

		else if(stoi(palavras[0]) == 1) {
			funcionario = new Gerente(codigo, nome, cpf, idade, cep, numero, telefone, data, 1, areaSupervisao);
			gerentes.push_back(funcionario);
		}

		else if(stoi(palavras[0]) == 2) {
			funcionario = new Diretor(codigo , nome, cpf, idade, cep, numero, telefone, data, 2, areaSupervisao, areaFormacao);
			diretores.push_back(funcionario);
		}
		else if(stoi(palavras[0]) == 3){
			*presidente = new Presidente(codigo, nome, cpf, idade, cep, numero, telefone, data, 3, areaFormacao, formacaMaxima);
			existePresida = true;
		}
		palavras.clear();

	}
	if(!existePresida) {
		presidente = nullptr;
	}

}
