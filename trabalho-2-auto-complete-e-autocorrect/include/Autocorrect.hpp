#ifndef AUTOCORRECT_HPP
#define AUTOCORRECT_HPP
#include "Database.hpp"

class Autocorrect {

    private:
        Database* db; // Referência ao Banco de dados.
    
    public:
        /**
         * @brief Construtor personalizado da classe com uma referência para o Banco de Dados
         * @param db referência para o banco de dados.
         */
        Autocorrect(Database* db);

        /**
         * @brief Método que retorna a distância de edição de duas strings quaisquer.
         * @param s1 String de base para realizar ordenação.
         * @param s2 String de base para realizar ordenação.
         */
        static unsigned int editDistance(const std::string& s1, const std::string& s2);

        /**
         * @brief Traz o recorte do vetor de Word próprias para o Autocorrect do 
         * Banco de dados para a classe Autocorrect.
         * @param userInput referência para a entrada do usuário.
         * @param isTest flag para validar casos de teste.
         * @return std::vector<Word*> o recorte do vetor de Word do Banco de dados.
         */
        std::vector<Word*> getAutocorrectSet(std::string& userInput, bool isTest);
};

#endif