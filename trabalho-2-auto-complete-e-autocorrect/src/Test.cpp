#include "Test.hpp"
#include <iostream>
#include <fstream>
#include "vector"
#include "Word.hpp"

Test::Test(Autocomplete* autocomplete, Autocorrect* autocorrect, Interface* Interface)
{
  this->autocomplete = autocomplete;
  this->autocorrect = autocorrect;
  this->interface = interface;
}

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void Test::testApplication()
{
  std::vector<std::string> inputWords;
  std::vector<std::vector<std::string>> autocompleteExpectedResults;
  std::vector<std::vector<std::string>> autocorrectExpectedResults;

  // lendo arquivo de inputs
  std::ifstream inputFile;
  inputFile.open("../tests/testInputs.txt");
  if(!inputFile.is_open()) return;

  std::string inputLine;
  while (!inputFile.eof())
  {
    getline(inputFile, inputLine);
    inputWords.push_back(inputLine);
  }

  // lendo arquivo de resultados esperados
  std::ifstream resultsFile;
  resultsFile.open("../tests/testResults.txt");
  if(!resultsFile.is_open()) return;

  std::string resultLine;
  bool autocomplete = true;
  while(!resultsFile.eof())
  {
    std::vector<std::string> autocompleteSet;
    std::vector<std::string> autocorrectSet;

    getline(resultsFile, resultLine);
    auto line = split(resultLine, "-");

    int sideCounter = 0;
    for(auto side : line)
    {
      if(side == "Nenhuma palavra encontrada.")
      {
        if(sideCounter % 2 == 0) 
          autocompleteSet.push_back(side);
        else
          autocorrectSet.push_back(side);

        sideCounter++;
        continue;
      }

      auto words = split(side, " ");
      for(auto word : words)
      {
        if(sideCounter % 2 == 0) 
          autocompleteSet.push_back(word);
        else
          autocorrectSet.push_back(word);
      }
      sideCounter++;
    }

    autocompleteExpectedResults.push_back(autocompleteSet);
    autocorrectExpectedResults.push_back(autocorrectSet);
  }

  // validando quantidade de palavras e resultados
  if(inputWords.size() != autocorrectExpectedResults.size() || 
     inputWords.size() != autocompleteExpectedResults.size())
     {
      std::string errorMessage = "Tamanhos incompatíveis! Há diferença entre o número de resultados esperados e obtidos.";
      this->interface->validationError(errorMessage);
     }

  // validando os containers de palavras esperadas
  bool errorFlag = false;
  int inputWordsCounter = 0;
  for(auto word : inputWords)
  {
    this->interface->printValidationHeader(word);
    auto autocompleteResults = this->autocomplete->getAutocompleteSet(word);
    auto autocorrectResults = this->autocorrect->getAutocorrectSet(word, true);

    this->interface->printAutocompleteHeader();
    int autocompleteWordsCounter = 0;
    for(auto autocompleteWord : autocompleteResults)
    {
      if(autocompleteWord->getSentence() == autocompleteExpectedResults[inputWordsCounter][autocompleteWordsCounter])
      {
        std::string successMessage = "Palavra encontrada: " + autocompleteWord->getSentence();
        this->interface->validationSuccess(successMessage);
      }
      else
      {
        std::string errorMessage = "Erro, palavra não compatível: " + autocompleteWord->getSentence() + " " + autocompleteExpectedResults[inputWordsCounter][autocompleteWordsCounter];
        this->interface->validationError(errorMessage);
        errorFlag = true;
      }
      autocompleteWordsCounter++;
    }
    if(autocompleteResults.size() == 0) this->interface->printNoWordsFounded();

    this->interface->printAutocorrectHeader();
    int autocorrectWordsCounter = 0;
    for(auto autocorrectWord : autocorrectResults)
    {
      if(autocorrectWord->getSentence() == autocorrectExpectedResults[inputWordsCounter][autocorrectWordsCounter])
      {
        std::string successMessage = "Palavra encontrada: " + autocorrectWord->getSentence();
        this->interface->validationSuccess(successMessage);
      }
      else
      {
        std::string errorMessage = "Erro, palavra não compatível: " + autocorrectWord->getSentence() + " " + autocorrectExpectedResults[inputWordsCounter][autocorrectWordsCounter];
        this->interface->validationError(errorMessage);
        errorFlag = true;
      }
      autocorrectWordsCounter++;
    }
    if(autocorrectResults.size() == 0) this->interface->printNoWordsFounded();


    inputWordsCounter++;
  }

  if(errorFlag)
  {
    std::string errorMessage = "Testes falharam, verifique entradas esperadas";
    this->interface->validationError(errorMessage);
  }
  else
  {
    std::string successMessage = "Testes concluídos sem erros encontrados.";
    this->interface->validationSuccess(successMessage);
  }
}