#include "Data.h"
#include <iostream>

Data::Data(){}

Data::Data(int dia, int mes, int ano) {
	setMes(mes);
	setDia(dia);
	setAno(ano);
}

int Data::getQuantidadeDiaMes(int mes) {
	int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	return diasMeses[mes - 1];
}

void Data::setDia(int dia) {	
	if(dia >= getQuantidadeDiaMes(getMes()) || dia <= 0) {
		std::cout << "Digite um dia valido " << std::endl;	
	} else {
		this->dia = dia;
	}
}

int Data::getDia() {
	return this->dia;
}

void Data::setMes(int mes) {
	if(mes < 1 || mes > 12) {
		std::cout << "Digite um mes valido " << std::endl;
	} else {
		this->mes = mes;
	}
}

int  Data::getMes() {
	return this->mes;
}

void Data::setAno(int ano) {
	this->ano = ano;
}

int Data::getAno() {
	return this->ano;
}

void Data::exibeData() {
	std::cout << getDia() << "/0" << getMes() << "/" << getAno() << std::endl;
}


bool Data::comparaDatas(int *data){
	if((getDia() == data[0]) && (getAno() == data[2]) && (getMes() == data[1])){
		return true;
	}
	else{
		return false;
	}
}
