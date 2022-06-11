#ifndef TENTATIVAABRIRARQUIVO_H
#define TENTATIVAABRIRARQUIVO_H

#include <stdexcept>



/* Foi atribuido um erro de execução, pois caso um arquivo não exista ou não consiga ser criado, o constutor da classe recebe o nome do arquivo*/
/* E então envia para o constutor de runtime_error a mensagem apropriada para o .what() */
class TentativaAbrirArquivo : public std::runtime_error {

    public:
        TentativaAbrirArquivo(const std::string& nomeArquivo)
            : std::runtime_error("Nao eh possivel localizar ou criar o arquivo " + nomeArquivo) {}
};















#endif