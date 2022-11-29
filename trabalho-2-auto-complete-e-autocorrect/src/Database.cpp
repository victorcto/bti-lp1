#include "Database.hpp"
#include "Autocorrect.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Database::Database(std::string fileName){
    this->fileName = fileName;
}

bool Database::readFile(){
    std::ifstream file;

    file.open(this->fileName);
    if(!file.is_open())
        return false;

    std::string line;

    while(!file.eof()){
        getline(file,line);

        if(line == "\0") continue;

        std::string relevance, sentence;
        for(unsigned int i=0; i<line.length(); i++){
            if(line[i] == '\t'){
                relevance = line.substr(0,i);
                sentence = line.substr(i+1,line.length()-1);
                break;
            }
        }

        this->words.push_back(new Word(std::stoul(relevance,nullptr,0),sentence));
    } 

    return true;
}

std::vector<Word*> Database::searchWordsAutocomplete(std::string& userInput){
    std::vector<Word*> Vcomp = this->words;
    Word* word = new Word(0, userInput);

    std::sort(Vcomp.begin(), Vcomp.end(), [](Word* a, Word* b) {
        return a->getSentence() < b->getSentence();
    });

    auto firstWord = std::lower_bound(Vcomp.begin(), Vcomp.end(), word, [](Word* a, Word* b) {
        return a->getSentence() < b->getSentence();
    });

    auto lastWord = std::upper_bound(Vcomp.begin(), Vcomp.end(), word, [](Word* a, Word* b) {
        return a->getSentence() < b->getSentence().substr(0, a->getSentence().length());
    });
    
    Vcomp.clear();

    int wordsLimit = 10, wordsCounter = 0;
    for(auto w = firstWord; w != lastWord; w++){
        if(wordsCounter == wordsLimit) break;
        
        Vcomp.push_back(*w);
        wordsCounter++;
    }
    
    delete word;
    
    return Vcomp;
}

int Database::calculateN(){
  return words.size() * 0.15;
}

bool Database::validateWords(Word* userInput, Word* databaseWords){
  if(userInput->getSentence().length() == databaseWords->getSentence().length())
    return true;
  else if (databaseWords->getSentence().length() - userInput->getSentence().length() == 1)
    return true;

  return false;
}

std::vector<Word*> Database::searchWordsAutocorrect(Word* userInput, bool isTest){
    std::vector<Word*> nWords, validWords, Vcorr;

    // processa palavras para rodar em tempo aceitável. N
    int condition = isTest ? this->words.size() : calculateN();
    for(unsigned int i = 0; i < condition ; i++){ 
      nWords.push_back(words[i]);
    }

    // encontra palavras de tamanho S e S+1
    for(auto w : nWords){
        if(validateWords(userInput,w))
            validWords.push_back(w);
    }

    // cria um vector com pair contém a Palavra e edit_distance.
    std::vector<std::pair<Word*,int>> wordsWithEditDistance;
    for(auto v : validWords){
        int editDistanceEdit = Autocorrect::editDistance(userInput->getSentence(), v->getSentence());
        wordsWithEditDistance.push_back(std::make_pair(v,editDistanceEdit));
    }

    // ordena o vetor primeiro por distância de edição, depois por peso da palavra
    std::sort(wordsWithEditDistance.begin(), wordsWithEditDistance.end(), 
              [](std::pair<Word*, int> a, std::pair<Word*,int> b) {
                if(a.second != b.second) return a.second < b.second;
                return a.first->getRelevance() > b.first->getRelevance();
            });

    // alimenta o vetor de recorte final
    int wordsLimit = 10, wordsCounter = 0;
    for(auto word : wordsWithEditDistance){
        if(wordsCounter == wordsLimit) break;
        
        Vcorr.push_back(word.first);
        wordsCounter++;
    }
    
    return Vcorr;
}