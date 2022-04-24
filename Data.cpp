#include "Data.h"
#include <iostream>


Data::Data(int dia, int mes, int ano)
{
	setMes(mes);
	setDia(dia);
	setAno(ano);
}



int Data::getQuantidadeDiaMes(int indice) const
{
	int diasMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	return diasMeses[indice - 1];
}



void Data::setDia(int dia)
{
	
	if(dia >= getQuantidadeDiaMes(getMes()) || dia <= 0)
	{
		std::cout << "Digite um dia valido " << std::endl;	
	}
	
	else
	{
		this->dia = dia;
	}

}


int Data::getDia() const
{
	return this->dia;
}


void Data::setMes(int mes)
{
	if(mes < 1 || mes > 12)
	{
		std::cout << "Digite um mes valido " << std::endl;
	}
	
	else
	{
		this->mes = mes;
	}

}



int  Data::getMes() const
{
	return this->mes;
}




void Data::setAno(int ano)
{
	this->ano = ano;
}



int Data::getAno() const
{
	return this->ano;
}

void Data::mostraData() const
{

	std::cout << getDia() << "/0" << getMes() << "/" << getAno() << std::endl;
}
