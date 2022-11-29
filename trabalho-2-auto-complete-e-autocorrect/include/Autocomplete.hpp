#ifndef AUTOCOMPLETE_HPP
#define AUTOCOMPLETE_HPP
#include "Database.hpp"

class Autocomplete {

  private:
    Database *db; // Referência ao Banco de dados.

  public:
    /**
     * @brief Construtor personalizado da classe com uma referência para o Banco de Dados
     * @param db referência para o banco de dados.
     */
    Autocomplete(Database *db);

    /**
     * @brief Oderna o vetor das Word pelo peso.
     * @param Vcomp referência ao vetor recortado das Word apropriadas para autocomplete.
     */
    void sortByRelevance(std::vector<Word*>& Vcomp);

    /**
     * @brief Traz o recorte do vetor de Word próprias para o autocomplete do 
     * Banco de dados para a classe Autocomplete.
     * @param userInput referência para a entrada do usuário.
     * @return std::vector<Word*> o recorte do vetor de Word do Banco de dados.
     */
    std::vector<Word*> getAutocompleteSet(std::string& userInput);

};

#endif