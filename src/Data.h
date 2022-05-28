#ifndef DATA_H
#define DATA_H

class Data {
	public:
		/* CONSTRUTORES */
		Data();
		Data(int dia, int mes, int ano);
		
		/* GET */
		int getDia();
		int getMes();
		int getAno();
		
		/* SET */
		void setMes(int mes);
		void setDia(int dia);
		void setAno(int ano);
		
		/* ESPECIFICAÇÕES */ 
		int getQuantidadeDiaMes(int mes);
		void exibeData();

		/* Função comparaDatas */

		bool comparaDatas(int *data);
	private:
		int dia;
		int mes;
		int ano;
};

#endif
