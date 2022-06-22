#ifndef TENTATIVAABRIRARQUIVO_H
#define TENTATIVAABRIRARQUIVO_H

#include <stdexcept>



/**
	* TentativaAbrirArquivo
	*  
	* Classe responsável pelo erro de abrir algum arquivo
	*/
class TentativaAbrirArquivo : public std::runtime_error {

    public:
        /**
		* TentativaAbrirArquivo()
		*  
		* Responsável por enviar o throw sobre uma tentativa de abrir o arquivo 
        * envia a string para a classe mão de runtime_error
        * \param sting-nomeArquivo recebe o nome do arquivo que não conseguiu abrir.
		*
		* \return Nada
		*/
        TentativaAbrirArquivo(const std::string& nomeArquivo)
            : std::runtime_error("Nao eh possivel localizar ou criar o arquivo " + nomeArquivo) {}
};















#endif