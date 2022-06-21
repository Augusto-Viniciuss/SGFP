#include "Arquivo.h"
#include <iostream>
#include <string.h>
#include <sstream>


Arquivo::Arquivo(){


	/* Criação da folha CSV somente com os titulos 	*/
	std::ofstream outputCsv((path + "Folha.csv").c_str(), std::ios::out);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Folha.csv");
	}
	outputCsv << "Codigo" << "," << "Designação," << "CPF," << "Nome," << "Telefone," << "Idade," << "Data Ingresso, " << "Rua," << "Bairro," << "Cidade, " << "Estado, " << "CEP," << "Numero, " << "Area de Supervisão, "
	<< "Area de formacao, " << "Formação máxima," << "Salario Base" << "\n";
	outputCsv.close(); // Fecha o arquivo



}


/***
 * atualizaArquivoFolha: Função responsável por criar o arquivo Csv
 * 
 * Parãmetros:
 * 					std::vector < Funcionario * > : vetor contendo os dados dos usuários para serem armazenados
 * 
 * 
 * Retorno:
 * 					Nenhuma
 * 
 * Função responsável por adicionar no fim do arquivo todos os dados importantes dos funcionarios
 ****/

void Arquivo::atualizaArquivoFolha(std::vector < Funcionario * > &funcionarioVec) {

	/*	Abertura do arquivo para colocar no fim 	*/	
	std::ofstream outputCsv((path + "Folha.csv").c_str(), std::ios::app);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	/*	Strings de armazenamento temporário	*/
	std::string areaSupervisao, areaFormacao, formacaoMaxima;
	
	/* Caso ele for um operário ele não tem nenhuma das trẽs strings	*/
	/* Caso ele seja Gerente tem somente areaSupervisão	*/
	/* Caso seja Diretor possui as duas áreas, área supervisão e formação */
	/* Presidente possui somente área formação e formação maxima	*/
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

		/* Realiza a escrita em outputCsv	*/
		outputCsv << funcionarioVec[i]->getCodigoFuncionario() << ","  << funcionarioVec[i]->getDesignacaoStr() << "," << funcionarioVec[i]->getCPF() << ", " << funcionarioVec[i]->getNome() << "," 
		<< funcionarioVec[i]->getTelefone() << "," << funcionarioVec[i]->getIdade() << ", " << funcionarioVec[i]->getDataIngresso().retornaStringData() << "," << funcionarioVec[i]->getEndereco()->getInformacao() << ","
		<< areaSupervisao << "," << areaFormacao << "," << formacaoMaxima << "," << funcionarioVec[i]->getFolhaSalarial(1)->getSalarioBase() << "\n";
		

	}

	/* Fecha o arquivo	*/
	outputCsv.close();
}

/***
 * atualizaArquivoFolha(): Função responsável por adicionamente somente um funcionario em arquivo
 * 
 * Parâmetros:
 * 						Funcionario * : ponteiro para o tipo funcionario, região que pega os dados para inserção
 * 
 * Retorno:
 * 						nenhum
 ****/
void Arquivo::atualizaArquivoFolha(Funcionario *presidente) {
	
	// Abertura do arquivo
	std::fstream outputCsv((path + "Folha.csv").c_str(), std::ios::app);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Folha.csv");
	}
	
	// Inserção do arquivo
	outputCsv << presidente->getCodigoFuncionario() << ","  << presidente->getDesignacaoStr() << "," << presidente->getCPF() << ", " << presidente->getNome() << "," 
		<< presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "," << presidente->getEndereco()->getInformacao() << ","
		<< "Nenhuma" << "," << ((Presidente *)presidente)->getAreaFormacao() << "," << ((Presidente*)presidente)->getFormacaoMax() << "," << presidente->getFolhaSalarial(1)->getSalarioBase() << "\n";
		
	outputCsv.close();
}

/***
 * CriaArquivoBaseDadosZerado() : Função responsável por criar a base de dados zeradas
 * 
 * 
 * Parãmetros: 				
 * 								nenhum
 * 
 * Retorno:
 * 								nenhum
 ****/
void Arquivo::criaArquivoBaseDadosZerado() {
	
	// Abre o arquivo de modo de saida e para apagar os dados
	std::ofstream outputCsv((path + "Dados.csv").c_str(), std::ios::out);
	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}
	// Fecha o arquivo
	outputCsv.close();
}



/***
 * AtualizaBaseDadosCsv(): Função responsável por criar as bases de dados no Csv
 * 
 * Parâmetros:
 * 						const std::vector < Funcionario *> : Possui os dados para cadastramando nas bases de dados
 * 
 * 
 * Retorno:
 * 						nenhum
 ****/
void Arquivo::AtualizaBaseDadosCsv(const std::vector < Funcionario *> &funcionarioVec) {
	
	// Abre o arquivo para adicionar no fim dele	*/
	std::ofstream outputCsv;
	outputCsv.open((path + "Dados.csv"), std::ios::app);

	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	// Strings para trẽs áreas de supervisã
	std::string areaSupervisao, areaFormacao, formacaoMaxima;
	
	//Percorre cada  vector e insere no final do arquiv
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

		for(int meses = 1; meses < 13; meses++) {
			outputCsv << funcionarioVec[i]->getHorasTrabalhadas(meses) << std::endl;
		}
	}

	outputCsv.close();

}

/***
 * addPresidenteBaseDadosCsv(): Função responsável por adicionar somente o presidente na base de dados
 * 
 * Parâmetros:
 * 						Funcionario * : Possui os dados para cadastramando nas bases de dados
 * 
 * 
 * Retorno:
 * 						nenhum
 ****/
void Arquivo::addPresidenteBaseDadosCsv(Funcionario *presidente) {

	// Abre  o arquivo para colocar no fim do arquivo
	std::ofstream outputCsv;
	outputCsv.open((path + "Dados.csv"), std::ios::app);

	if(!outputCsv) {
		throw TentativaAbrirArquivo("Dados.csv");
	}

	/* Inserção de todos os dados como designação, codigo, cpf, nome, telefone, idade, data de ingresso, cep, numero, area de supervisão, formação e formação máxima	*/
	outputCsv << presidente->getDesignacaoInt() << "," << presidente->getCodigoFuncionario() << "," << presidente->getCPF() << ", " << presidente->getNome() << "," 
	<< presidente->getTelefone() << "," << presidente->getIdade() << ", " << presidente->getDataIngresso().retornaStringData() << "," << presidente->getEndereco()->getCEP()<< "," <<
	presidente->getEndereco()->getNumero()<< "," << "Nenhuma" << "," <<((Presidente *)presidente)->getAreaFormacao() << "," << ((Presidente*)presidente)->getFormacaoMax() << "," << presidente->getFolhaSalarial(1)->getSalarioBase() << "\n";
	
	for(int meses = 1; meses < 13; meses++) {
		outputCsv << presidente->getHorasTrabalhadas(meses) << std::endl;
	}
	// Fechamento do arquivo
	outputCsv.close();
}

/***
 * carregaDadosCsv: Carrega os dados do csv
 * 
 * 
 * Parâmetros:
 * 				std::vector < Funcionario * >& : 3 vector para a inserção de dados que recebe como referencia
 * 				Funcionario **: aponta para uma variavel do tipo funcionario
 ***/

void Arquivo::carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente) {
	// Abre os arquivos para entrada de dados
	std::ifstream inputCsv((path + "Dados.csv").c_str(), std::ios::in);

	// Verifica se o arquivo existia, caso não avisa ao usuario e cria o arquivo do zero
	if(!inputCsv) {
		std::cout << "Arquivos zerados. Nenhum funcionário cadastrado" << std::endl;
		std::ifstream inputCsv((path + "Dados.csv").c_str(), std::ios::app);
		inputCsv.close();

		throw TentativaAbrirArquivo("Dados.csv");
	}

	std::string linha, buffer;	// linha é responsável por ler a linha de dadosCsv e bufffer responsável por armazenar cada palavra entre vírgulas
	std::vector < std::string > palavras; // Contém um vector de palavras que são as palavras entre cada vírgulas
	std::string dataBuffer;				// Responsável por armazenar o buffer do tratamento de data
	char *doubleBuffer;					// Armazena o buffer da leitura de um valor double
	
	
	Funcionario *funcionario;	// Ponteiro que inicializar a memória do tipo
	int data[3];				// Array que contém a data de inserção do usuario

	std::string nome, cpf, telefone, cep, areaSupervisao, areaFormacao, formacaMaxima; // Dados responsáveis para inicialização dos funcionarios
	
	/* Outros dados do funcionario	*/
	double salarioBase;
	int codigo, idade, numero;
	bool existePresida = false; // Variavel que indica se o presidente existe ou não
	
	int horasTrabalhadas[12];
	std::string horas;
	// Loop responsável pela leitura do arquivo
	while(1) {
		
		// Pega-se a linha
		getline(inputCsv, linha);

		for(int i = 0; i < 12; i++) {
			getline(inputCsv, horas);
			horasTrabalhadas[i] = stoi(horas);
		}
		
		// Verifica se já chegou no fim do arquivo
		if(inputCsv.eof()) {
			break;
		}
		// Armazena a linha em uma stream de string
		std::stringstream dados(linha);
		
		// Toda vez que eu achar uma "," armazena em buffer e por fim adiciona a palavra no vector de strings
		while(getline(dados, buffer,',')) {
			palavras.push_back(buffer);
			
		}

		
		
		int indice = 0; // Indice do array de data

		
		std::string cpfBuffer; // Armazena o cpf temporariamente
		std::string cepBuffer; // Armazena o cep temporariamente

		
		
		// Agora percorre o vector, que contém todas as palavras daquela linha

		//Vamos verificar seu tipo e percorrer os dados na seguinte ordem
		//Codigo, cpf, nome, telefone, idade, data de entrada, cep, numero
		//Area de supervisao, area de formacao, formacao maxima e salario base 
		for(int i = 1; i < palavras.size(); i++) {
			
			switch(i) {
				
				case 1:
					codigo = stoi(palavras[i]); // Converte o nome
					break;
				case 2:

					// Temos o seguindo cpf: 118.196.924-77
					cpfBuffer.clear(); // Limpa o buffer

					// Percorre o cpf e tudo que for diferente de "." e "-" adiciona ao cpf
					for(int j = 0; j < palavras[i].size(); j++) {
						
						if(palavras[i][j] != '.' && palavras[i][j] != '-') {
							cpfBuffer.push_back(palavras[i][j]);
						}
					}
					cpf = cpfBuffer;
					break;
				case 3:
					
					
					nome = palavras[i];

					// Caso a palavra possuia o caractere " " antes do nome, aqui ele será retirada
					// Percorre a string até achar uma letra e exclui tudo do nome até essa posição de letra
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
					// Função responsável por trata (83) no telefone
					telefone = palavras[i];
					
					telefone.erase(telefone.begin(), telefone.begin() + 1);
					
					telefone.erase(telefone.begin() + 2, telefone.begin() + 3);
					// Necessita retirar - da string telefone
					telefone.erase(telefone.begin() + 7, telefone.begin() + 8);
					break;
				case 5:
					idade = stoi(palavras[i]);
					break;
				case 6:

					dataBuffer.clear(); // Limpa o buffer de data
					
					// Função responsável por ler a data no formato 27/04/2002
					// E retirar o dia, mes e ano certos
					// Tudo que ler e for diferente de / é um numero
					// e para o ultimo numero utiliza-se a posição de j para indicar que pegamos todo o valor
					for(int j = 0; j < palavras[i].size(); j++) {
						
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
							dataBuffer.clear();
						}
					}
					break;

				case 7:
					// Temos 58052-310
					cep = palavras[i];
					// Necessário retirar o - utilizando erase
					cep.erase(cep.begin() + 5, cep.begin() + 6);
					break;
				
				case 8:
					/* Conversão da palavra em inteiro	*/
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
					/* Conversão da palavra em double e joga no buffer	*/
					salarioBase = strtod(palavras[i].c_str(), &doubleBuffer);
					break;
			}
		}

		
		/* Inicialização dependendo do tipo e armazena no vetor	*/
		if(stoi(palavras[0]) == 0) {
			funcionario = new Operador(codigo, nome, cpf, idade, cep, numero, telefone, data, 0);
			operadores.push_back(funcionario);

			for(int mes = 1; mes < 13; mes++) {
				funcionario->setHorasTrabalhadas(mes, horasTrabalhadas[mes - 1]);
			}
		}

		else if(stoi(palavras[0]) == 1) {
			funcionario = new Gerente(codigo, nome, cpf, idade, cep, numero, telefone, data, 1, areaSupervisao);
			gerentes.push_back(funcionario);

			for(int mes = 1; mes < 13; mes++) {
				funcionario->setHorasTrabalhadas(mes, horasTrabalhadas[mes - 1]);
			}
		}

		else if(stoi(palavras[0]) == 2) {
			funcionario = new Diretor(codigo , nome, cpf, idade, cep, numero, telefone, data, 2, areaSupervisao, areaFormacao);
			diretores.push_back(funcionario);

			for(int mes = 1; mes < 13; mes++) {
				funcionario->setHorasTrabalhadas(mes, horasTrabalhadas[mes - 1]);
			}
		}
		else if(stoi(palavras[0]) == 3){
			*presidente = new Presidente(codigo, nome, cpf, idade, cep, numero, telefone, data, 3, areaFormacao, formacaMaxima);
			existePresida = true;

			for(int mes = 1; mes < 13; mes++) {
				(*presidente)->setHorasTrabalhadas(mes, horasTrabalhadas[mes - 1]);
			}
		}
		palavras.clear();

	}
	// Caso o presidente não existe, atribui nullptr a ele
	if(!existePresida) {
		*presidente = nullptr;
	}
}

HistoricoArquivo* Arquivo::getHistoricoArquivo(){
	return &this->historico;
}
