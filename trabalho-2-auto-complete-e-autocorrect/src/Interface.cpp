#include "Interface.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Interface::Interface() {}

std::string Interface::getUserInput(){
  return this->userInput;
}

std::string Interface::getFileName(){
  return this->fileName;
}

void Interface::setFileName(std::string& fileName){
  this->fileName = fileName;
}

void Interface::setProgramName(std::string& programName){
  this->programName = programName;
}

void Interface::setUserInput(std::string& userInput){
  this->userInput = userInput;
}

void Interface::printWordsContainer(std::vector<Word*>& Vcomp, std::vector<Word*>& Vcorr){
  if(Vcomp.size() == 0)
    Vcomp.push_back(new Word(0, "Nenhuma palavra encontrada."));
  
  if(Vcorr.size() == 0)
    Vcorr.push_back(new Word(0, "Nenhuma palavra encontrada."));
    
  int biggestVectorSize = Vcomp.size() > Vcorr.size() ? Vcomp.size() : Vcorr.size();
  int maxWordLength = Vcomp.size();
  
  if(maxWordLength > 0){
    if(biggestWordSize(Vcomp) < 12) maxWordLength = 12;
    else maxWordLength = biggestWordSize(Vcomp);
  } else maxWordLength = 27;

  std::cout << ">>> Matches são:" << std::endl;
  
  std::cout << "Autocomplete";
  for(int i = 0; i <= abs(maxWordLength - 12); i++) std::cout << " ";
  std::cout << "| Autocorrect" << std::endl;

  int currentAutocorrectIndex = 0;
  for(int i = 0; i < biggestVectorSize; i++){

    if(i < Vcomp.size()){
      std::cout << Vcomp[i]->getSentence();
      for(int j = 0; j <= maxWordLength - Vcomp[i]->getSentence().size(); j++) std::cout << " ";
      std::cout << "| ";
    } else{
      for(int j = 0; j <= maxWordLength; j++) std::cout << " ";
      std::cout << "| ";
    }

    if(currentAutocorrectIndex < Vcorr.size()){
      std::cout << Vcorr[currentAutocorrectIndex]->getSentence();
      currentAutocorrectIndex++;
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Interface::printFileReadingErrorMessage(){
  std::cout << "Erro na leitura do arquivo '" + fileName << "'." << std::endl;
}

bool Interface::askForUserInput(){
  std::string userInput;

  std::cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";
  std::cin >> userInput;
  
  if(userInput.length() < 3){
    std::cout << "Palavra deve ter ao menos 3 caracteres, tente novamente." << std::endl;
    return false;
  }

  std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
  setUserInput(userInput);

  return true;
}

int Interface::biggestWordSize(std::vector<Word*>& Vcomp){
    int max = Vcomp[0]->getSentence().length();
    
    for(auto w : Vcomp){
        if(w->getSentence().length() > max){
            max = w->getSentence().length();
        }
    }

    return max;
}

void Interface::argumentError(){
  std::cout << "Usage: words_complete_correct <database_file>\n\t" <<
  "onde <database_file> é a base de dados contendo os pesos e as palavras a serem consideradas.\n";
}

void Interface::validationError(std::string& errorMessage)
{
  std::cout << "\033[31m" << errorMessage << "\033[0m" << std::endl;
}

void Interface::validationSuccess(std::string& successMessage)
{
  std::cout << "\033[32m" << successMessage << "\033[0m" << std::endl;
}

void Interface::printValidationHeader(std::string& header)
{
  std::cout << "\n[Validando Input]: " << header << std::endl;
}

void Interface::printAutocompleteHeader()
{
  std::cout << "\n================= AUTOCOMPLETE =================\n" << std::endl;
}

void Interface::printAutocorrectHeader()
{
  std::cout << "\n================= AUTOCORRECT =================\n" << std::endl;

}

void Interface::printNoWordsFounded()
{
  std::cout << "\033[32m" << "Nenhuma palavra encontrada." << "\033[0m" << std::endl;
}