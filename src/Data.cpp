#include "Data.h"
#include <iostream>

#include <chrono> // biblioteca para pegar a data do computador




Data::Data(){}

/* Seta o dia, mes e ano	*/
Data::Data(int dia, int mes, int ano) {
	setMes(mes);
	setDia(dia);
	setAno(ano);
}

/* Retorna a quantidade de meses do ano	*/
int Data::getQuantidadeDiaMes(int mes) {
	int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	return diasMeses[mes - 1];
}

/* Seta o dia 	*/
void Data::setDia(int dia) {	
	this->dia = dia;
}

/* Retorna o dia	*/
int Data::getDia() {
	return this->dia;
}

/* Seta o mes	*/
void Data::setMes(int mes) {
	
	this->mes = mes;
}

/* Retorna o mes	*/
int  Data::getMes() {
	return this->mes;
}

/* Seta o ano	*/
void Data::setAno(int ano) {
	this->ano = ano;
}

/* Retorna o ano	*/
int Data::getAno() {
	return this->ano;
}

/* Exibe a data */
void Data::exibeData() {
	std::cout << getDia() << "/0" << getMes() << "/" << getAno() << std::endl;
}

/* Compara as datas	*/
bool Data::comparaDatas(int *data){
	if((getDia() == data[0]) && (getAno() == data[2]) && (getMes() == data[1])){
		return true;
	}
	else{
		return false;
	}
}

/* Retorna a data no formato de string	*/
std::string Data::retornaStringData() {
	std::string data;
	/* Caso o dia e mes forem menos que zero, precisa do 0 na frente do valor	*/
	/* Caso somente o dia precisa do zero no valor e assim para o mes também 	*/
	if(getDia() < 10 and getMes() < 10) {
		data = "0" + std::to_string(getDia()) + "/0" + std::to_string(getMes()) + "/" + std::to_string(getAno());
	} else if(getDia() < 10) {
		data = "0" + std::to_string(getDia()) + "/" + std::to_string(getMes()) + "/" + std::to_string(getAno());
	} else if(getMes() < 10) {
		data = std::to_string(getDia()) + "/0" + std::to_string(getMes()) + "/" + std::to_string(getAno());
	} else {
		data = std::to_string(getDia()) + "/" + std::to_string(getMes()) + "/" + std::to_string(getAno());
	}

	/* Retorna a string	*/
	return data;
}

/* Retorna a data do computador	*/
std::string Data::retornaDataComputador() {
	/* system_clock::now() retorna a data do computador atual	*/
	auto now = std::chrono::system_clock::now();
	/* transforma ela numa variável do tipo t, que representa tempo	*/
   	time_t time = std::chrono::system_clock::to_time_t(now); // variavel do tipo time_t, o qual possui as informações do time do computador
		
	std::string dataString;
	/* Caso o mes seja menor que zero, deve ter o 0 na frente	*/
	/* local(&t) possui todos os dados de dia mes e ano	*/
	if(localtime(&time)->tm_mon + 1 < 10) {
		dataString = std::to_string(localtime(&time)->tm_mday) + "/0" + std::to_string(localtime(&time)->tm_mon + 1) + "/" + std::to_string(localtime(&time)->tm_year + 1900);
	}
	else {
		dataString = std::to_string(localtime(&time)->tm_mday) + "/" + std::to_string(localtime(&time)->tm_mon + 1) + "/" + std::to_string(localtime(&time)->tm_year + 1900);
	}
		
	
	// Retorna o valor
	return dataString;


}
