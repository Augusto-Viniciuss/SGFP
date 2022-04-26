#ifndef DATA_H
#define DATA_H

class Data {
	public:
		Data();
		Data(int, int, int);
		
		/* GET */
		int getDia() const;
		int getMes() const;
		int getAno() const;
		
		/* SET */
		void setMes(int);
		void setDia(int);
		void setAno(int);
		
		/* ESPECIFICAÇÕES */ 
		int getQuantidadeDiaMes(int) const;
		void exibeData() const;

	private:
		int dia;
		int mes;
		int ano;
};

#endif
