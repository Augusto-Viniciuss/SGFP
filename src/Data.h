#ifndef DATA_H
#define DATA_H


class Data
{
	public:
		Data(int, int, int);
		
		void setDia(int);
		int getDia() const;
		
		void setMes(int);
		int getMes() const;

		void setAno(int);
		int getAno() const;

		int getQuantidadeDiaMes(int) const;

		void mostraData() const;

	private:
		int dia;
		int mes;
		int ano;
};


#endif
