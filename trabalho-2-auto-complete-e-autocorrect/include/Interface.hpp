#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <string>
#include <vector>
#include "Word.hpp"

class Interface{
  private:
    std::string programName; // nome do programa
    std::string fileName; // nome do arquivo
    std::string userInput; // entrada do usuário

  public:

    /**
     * @brief Construtor padrão da classe.
     */
    Interface();

    /**
     * @brief Pega a entrada do usuário.
     * @return std::string entrada do usuário.
     */
    std::string getUserInput();

    /**
     * @brief Define a entrada do usuário.
     * @param userInput valor a ser atribuído à entrada do usuário.
     */
    void setUserInput(std::string& userInput);

    /**
     * @brief Pega o nome do arquivo.
     * @return std::string nome do arquivo.
     */
    std::string getFileName();

    /**
     * @brief Define o nome do arquivo.
     * @param userInput valor a ser atribuído ao nome do arquivo.
     */
    void setFileName(std::string& fileName);

    /**
     * @brief Define o nome do programa.
     * @param userInput valor a ser atribuído ao nome do programa.
     */
    void setProgramName(std::string& programName);

    /**
     * @brief Exibe mensagem de erro ao ler o arquivo.
     */
    void printFileReadingErrorMessage();
    
    /**
     * @brief Exibe a lista de palavras do autocomplete e do autocorrect.
     * @param Vcomp container contendo as sentenças do autocomplete.
     * @param Vcorr container contendo as sentenças do autocorrect.
     */
    void printWordsContainer(std::vector<Word*>& Vcomp, std::vector<Word*>& Vcorr);

    /**
     * @brief Recebe a entrada do usuário validando-a.
     * @return true se a entrada do usuário não contém erro, false se a entrada do usuário contém erro.
     */
    bool askForUserInput();

    /**
     * @brief Exibe mensagem de uso do programa caso haja erro no argumento passado.
     */
    void argumentError();

    /**
     * @brief Retorna o tamannho da maior palavra do container.
     * @param Vcomp container contendo as palavras.
     * @return int maior palavra do container.
     */
    int biggestWordSize(std::vector<Word*>& Vcomp);

    /**
     * @brief Exibe uma mensagem de erro personalizada na interface de usuário.
     * @param errorMessage Mensagem personalizada para erro específico.
     */
    void validationError(std::string& errorMessage);

    /**
     * @brief Exibe uma mensagem de sucesso personalizada na interface de usuário.
     * @param successMessage Mensagem personalizada para caso de sucesso específico.
     */
    void validationSuccess(std::string& successMessage);

    /**
     * @brief Exibe uma mensagem de validação especificando o input que será validado.
     * @param header Input a ser validado.
     */
    void printValidationHeader(std::string& header);

    /**
     * @brief Exibe o cabeçalho de validação para o autocomplete.
     */
    void printAutocompleteHeader();

    /**
     * @brief Exibe o cabeçalho de validação para o autocorrect.
     */
    void printAutocorrectHeader();

    /**
     * @brief Exibe mensagem de nenhuma palavra encontrada.
     */
    void printNoWordsFounded();
};

#endif