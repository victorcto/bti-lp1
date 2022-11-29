#include "Word.hpp"

Word::Word(unsigned int relevance, std::string sentence){
    this->relevance = relevance;
    this->sentence = sentence;
}

unsigned int Word::getRelevance(){
    return this->relevance;
}

void Word::setRelevance(unsigned int relevance){
    this->relevance = relevance;
}

std::string Word::getSentence(){
    return this->sentence;
}

void Word::setSentence(std::string sentence){
    this->sentence = sentence;
}