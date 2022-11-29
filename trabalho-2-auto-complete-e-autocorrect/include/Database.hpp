#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "Word.hpp"
#include <vector>

class Database{
    private:
        std::string fileName; // Nome do arquivo contendo as sentenças e seus respectivos pesos.
        std::vector<Word*> words; // Vetor com Word (peso e sentença).

    public:
    
        /**
         * Construtor da classe.
         * @param fileName o nome do arquivo contendo as sentenças e seus respectivos pesos.
         */
        Database(std::string fileName);

        /**
         * @brief Faz a leitura do arquivo contendo as sentenças e seus respectivos pesos
         * já preenchendo o container words.
         * @return true caso o arquivo seja executado corretamente, false caso o arquivo não exista 
         * ou apresente algum erro.
         */
        bool readFile();

        /**
         * @brief Faz um recorte das palavras que serão utilizadas no Autocomplete.
         * @param userInput entrada digitada pelo usuário.
         * @return std::vector<Word*> retorna um vetor contendo um recorte de Words. 
         */
        std::vector<Word*> searchWordsAutocomplete(std::string& userInput);

        /**
         * @brief Faz um recorte das palavras que serão utilizadas no Autocorrect.
         * @param userInput entrada digitada pelo usuário.
         * @param isTest flag para validar casos de teste.
         * @return std::vector<Word*> retorna um vetor contendo um recorte de Words. 
         */
        std::vector<Word*> searchWordsAutocorrect(Word* userInput, bool isTest);

        /**
         * @brief Faz a validação de duas palavras com base no tamanho.
         * @param userInput entrada digitada pelo usuário.
         * @param databaseWords palavra do banco de dados a ser comparada.
         * @return  true caso as palavras tenham mesmo tamanho ou diferença máxima de 1 caracter, false
         * caso contrário.
         */
        bool validateWords(Word* userInput, Word* databaseWords);

        /**
         * @brief Calcula um número inteiro N baseada numa taxa de 15% do total de palavras.
         * @return inteiro N correspondente a 15% do total de palavras.
         */
        int calculateN();
};

#endif