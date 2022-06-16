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
		
		for(int j = 0; j < 100; j++) {
			
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
					arquivoFuncionariosSaida[i].write((const char *) (&presidentes), sizeof(Presidente));
					break;
			}
			arquivoFuncionariosSaida[i].close();
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

	// Realiza a troca por conta da diferença
	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	
	bool funcionarioExiste = false; // variável que indica se existe ou não o funcionario

    switch(tipoFuncionario){
  
        // Coloca-se na posição referente ao código
        // Ler o que está contido
        case 3:
        	funcionario = &presidente;
            break;
  
        case 2:
            funcionario = &diretor;
            break;
  
        case 1:
            funcionario =  &gerente;
            break;
  
        case 0:
            funcionario = &operador;
            break;
  
    }
	


	/* Devemos criar uma outra stream, ppara que não haja bug no posicionamente de ponteiro, LOGO: DEVEMOS CRIAR UMA STREAM PARA LEITURA E OUTRA PARA INSERÇÃO*/
	/* Em uma determinada instancia	*/
	// Vamos primeiro posicionar o ponteiro para a localização que corresponde ao codigo do funcionario
	// Abre para entrada de dados //
	std::ifstream input;
	input.open(path + nomeArquivos[tipoFuncionario], std::ios::in);
	if(!input) {
		std::cout << "erro ao abrir" << std::endl;
	}

	input.seekg(0);
	input.seekg((dadosFuncionario.getCodigoFuncionario() - 1) * sizeof(*funcionario));

	input.read(reinterpret_cast<char*>(funcionario), sizeof(*funcionario));
	// Indica que o funcionario já existe
	if(funcionario->getCodigoFuncionario() != 0) {
		funcionarioExiste = true;	
	}
	input.close();

	// Deve-se abrir com in | out para que não haver sobreescrita
	arquivoFuncionariosSaida[tipoFuncionario].open(path + nomeArquivos[tipoFuncionario],  std::ios::in | std::ios::out);

	if(!arquivoFuncionariosSaida[tipoFuncionario].is_open()) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}

	
	// Posiciona o ponteiro de arquivo put na localização que devemos colocar o funcionario correspondente ao arquivo que estamos abrindo
	arquivoFuncionariosSaida[tipoFuncionario].seekp((dadosFuncionario.getCodigoFuncionario() - 1) * sizeof(*funcionario));

	// Escreve os dados no arquivo correspondente ao tipo de funcionário
  	arquivoFuncionariosSaida[tipoFuncionario].write(reinterpret_cast <const char *> (&dadosFuncionario), sizeof(*funcionario));
	
	
		
		
	historico.setDataModificacao(tipoFuncionario);

	// Se o funcionario existe, é porque foi realizada uma atualização
	if(funcionarioExiste) {
		historico.setModificacao(tipoFuncionario,"O usuario foi atualizado");
	}
	else {
		historico.setModificacao(tipoFuncionario,"O usuario foi cadastrado");
	}

	
	historico.setCodigo(tipoFuncionario, dadosFuncionario.getCodigoFuncionario());
	historico.setNome(tipoFuncionario, dadosFuncionario.getNome());
	historico.escreveArquivoModificacoes(tipoFuncionario);

	
	
	// Fecha o arquivo após o tratamento
	arquivoFuncionariosSaida[tipoFuncionario].close();
	

		
}



void Arquivo::mostraDadosArquivos(int tipoFuncionario){


	Presidente presidente;
	Gerente gerente;
	Diretor diretor;
	Operador operador;
	
	Funcionario *funcionario;	

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	switch(tipoFuncionario){
  
        // Coloca-se na posição referente ao código
        // Ler o que está contido
        case 3:
        	funcionario = &presidente;
            break;
  
        case 2:
            funcionario = &diretor;
            break;
  
        case 1:
            funcionario =  &gerente;
            break;
  
        case 0:
            funcionario = &operador;
            break;
  
    }

	// Abre o arquivo para entrada de dados	
	arquivoFuncionariosSaida[tipoFuncionario].open(nomeArquivos[tipoFuncionario], std::ios::in | std::ios::binary);

	if(!arquivoFuncionariosSaida[tipoFuncionario]) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}
	
	// Posiciona no local para leitura de dados
	//arquivoFuncionarios[tipoFuncionario].seekg(0);

	while(!arquivoFuncionariosSaida[tipoFuncionario].eof())
	{
		//arquivoFuncionarios[tipoFuncionario].read(reinterpret_cast < char * > (funcionario), sizeof(*funcionario));

		if(funcionario->getCodigoFuncionario() != 0) {
			std::cout << funcionario->getCodigoFuncionario() << " " << funcionario->getNome() << " " << funcionario->getCodigoFuncionario() << std::endl;
		}

	}

	arquivoFuncionariosSaida[tipoFuncionario].close();
}


void Arquivo::excluiDados(int tipoFuncionario, int codigoFuncionario)
{

	// Cria os tipos filhos previamente
	Diretor diretores[2];
	Gerente gerentes[2];
	Operador operadores[2];
	Presidente presidente;

	Funcionario *funcionarios;
	Funcionario *ptrLeitura;
	bool tentaPresidenteExcluir = false;
	// variavel que indica se houve tentativa de exclusão do presidente

	//Throw tentativa falha de excluir o presidente
	if (tipoFuncionario == 3)
	{

		throw InvalidoArgumentoArquivoExcept("Não é possível alterar o presidente.\n");

		tentaPresidenteExcluir = true;
	}

	/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/
	// Verifica o tipo de funcionario e faz o ponteiro funcionarios apontar para aquele tipo
	switch (tipoFuncionario)
	{
		
		case 3:
			ptrLeitura = &presidente;
		case 2:
			funcionarios = &diretores[0];
			ptrLeitura = &diretores[1];
			break;
		case 1:
			funcionarios = &gerentes[0];
			ptrLeitura = &gerentes[1];
			break;
		case 0:
			funcionarios = &operadores[0];
			ptrLeitura = &operadores[1];
			break;
	}
	
	arquivoFuncionariosSaida[tipoFuncionario].open(path + nomeArquivos[tipoFuncionario], std::ios::out | std::ios::in | std::ios::binary);

	if(!arquivoFuncionariosSaida[tipoFuncionario]) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}

	exclusaoDados[tipoFuncionario].open(path + nomeArquivos[tipoFuncionario], std::ios::in | std::ios::binary);

	if(!exclusaoDados[tipoFuncionario]) {
		throw TentativaAbrirArquivo(nomeArquivos[tipoFuncionario]);
	}
	// Posiciona o arquivo no local referente ao codigoFuncionario
	arquivoFuncionariosSaida[tipoFuncionario].seekp((codigoFuncionario - 1) * sizeof(*funcionarios));

	// Posiciona também o ponteiro de leitura
	exclusaoDados[tipoFuncionario].seekg((codigoFuncionario - 1) * sizeof(*funcionarios));

	// Coloca um funcionario zerado naquela posição
	arquivoFuncionariosSaida[tipoFuncionario].write(reinterpret_cast<const char *>(funcionarios), sizeof(*funcionarios));
	
	// Faz a leitura do dado
	exclusaoDados[tipoFuncionario].read(reinterpret_cast<char *>(ptrLeitura), sizeof(*ptrLeitura));

	if (tentaPresidenteExcluir)
	{

		historico.setModificacao(tipoFuncionario, "Tentaram excluir o presidente");
	}

	else
	{
		historico.setModificacao(tipoFuncionario, "O usuario foi excluido");
	}

	historico.setDataModificacao(tipoFuncionario);
	historico.setCodigo(tipoFuncionario, codigoFuncionario);
	historico.setNome(tipoFuncionario, ptrLeitura->getNome());
	historico.escreveArquivoModificacoes(tipoFuncionario);

	arquivoFuncionariosSaida[tipoFuncionario].close();
	exclusaoDados[tipoFuncionario].close();
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
			
		case 3:
			ptrFuncionarioTemp = &presidenteBuffer;
			break;

		case 2:
			ptrFuncionarioTemp = &diretorBuffer;
			break;
				
		case 1:
			ptrFuncionarioTemp =  &gerenteBuffer;
			break;
				
		case 0:
			ptrFuncionarioTemp = &operadorBuffer;
			break;
	}
	
	/* Posiciona o ponteiro no inicio	*/
	arquivosEntradas[tipoFuncionario].seekg(0);

	
	arquivosEntradas[tipoFuncionario].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), sizeof(*ptrFuncionarioTemp));
	/* Ler todos os dados até achar um usuário válido	*/
	while(!arquivosEntradas[tipoFuncionario].eof()) {
		
		if(ptrFuncionarioTemp->getCodigoFuncionario() != 0) {
			std::cout << ptrFuncionarioTemp->getNome() << std::endl;
			/* Aponta adequadamente para uma nova região de memória, dependendo de qual arquivo estamos lendo	*/
			/* Toda vez que damos new, há alocação de memória em algum local e retorna seu endereço, armazenando em funcionario	*/
			switch(tipoFuncionario) {
				case 3:
					funcionario = new Presidente();
					break;

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
			
			// Cópia de memoria
			memcpy(funcionario, ptrFuncionarioTemp, sizeof(*ptrFuncionarioTemp));
			funcionariosVec.push_back(funcionario);								
		}
		arquivosEntradas[tipoFuncionario].read(reinterpret_cast < char*  > (ptrFuncionarioTemp), sizeof(*ptrFuncionarioTemp));
		
	}
	/* Fecha o arquivo após ler os dados	*/
	arquivosEntradas[tipoFuncionario].close();
	



}


void Arquivo::criaArquivoCsv(const std::vector < Funcionario * > &funcionarioVec) {

	outputCsv.open(path + "Folha.csv", std::ios::app);

	if(!outputCsv) {
		outputCsv.open(path + "Folha.csv", std::ios::out);
		//throw TentativaAbrirArquivo("Folha.csv");
	}

	for(int i = 0; i < funcionarioVec.size(); i++) {
		outputCsv << funcionarioVec[i]->getCodigoFuncionario() << "," << funcionarioVec[i]->getDesignacaoInt()  << ", " << funcionarioVec[i]->getCPF() << ", " << funcionarioVec[i]->getNome() << "," 
		 << "," << funcionarioVec[i]->getFolhaSalarial(1)->getSalarioBase() << "," << funcionarioVec[i]->getTelefone() << "," << funcionarioVec[i]->getIdade() << ", " << funcionarioVec[i]->getDataIngresso().retornaStringData() << "\n";
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
		 << "," << presidente->getFolhaSalarial(1)->getSalarioBase() << "," << presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "\n";

}