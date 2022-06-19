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
	outputCsv.close();



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
