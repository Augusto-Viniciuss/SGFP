#ifndef DATA_H
#define DATA_H
#include <string>

class Data {
	public:
		/* CONSTRUTORES */
		Data();

		/**
		* Construtor
		* 
		* Inicializa o dia, mês  e ano de uma data.
		* \param int dia do ano
		* \param int mes do ano
		* \param int refere-se ao ano da data 
		*/
		Data(int dia, int mes, int ano);
		

		/**
		* Métodos Get
		* \param getDia retorna o dia
		* \param getMes retorna o mes
		* \param getAno retorna o ano 
		* \return um inteiro
		*/
		int getDia();
		int getMes();
		int getAno();
		
		/**
		* Métodos Set
		* \param setDia armazena o dia
		* \param setMes armazena o mes
		* \param setAno armazena o ano 
		* \return void
		*/
		void setMes(int mes);
		void setDia(int dia);
		void setAno(int ano);
		
		/**
		* getQuantidadeDiaMes
		* 
		* Retorna a quantidade de dia do mes
		* \param mes recebe mes do ano
		* \return inteiro
		*/ 
		int getQuantidadeDiaMes(int mes);
		
		/**
		* 
		*	Exibe a data armazenada
		*/
		void exibeData();

		/**
		* retornaStringData()
		* \return retorna o formato string da data armazenada, na forma xx/xx/xxxx
		*/
		std::string retornaStringData();

		/**
		* retornaDataComputador()
		*
		*\return Retorna o formato string da data atual do computador
		*/
		std::string retornaDataComputador();

		/**
		* comparaDatas()
		* \param data lista de uma data, contendo dia, mes e ano.
		* Compara a data armazenada com aquela que recebe como parâmetro.
		* \return valor bool que indica se são iguais ou não.
		*/
		bool comparaDatas(int *data);
	private:
		
		int dia; /*!< Dia da data */
		int mes; /*!< Mes da data */
		int ano; /*!< Ano da data */
};

#endif
