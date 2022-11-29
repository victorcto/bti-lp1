#include "Autocomplete.hpp"
#include <algorithm>


Autocomplete::Autocomplete(Database *db){
    this->db = db;
}

void Autocomplete::sortByRelevance(std::vector<Word*>& Vcomp)
{
    std::sort(Vcomp.begin(), Vcomp.end(), [](Word* a, Word* b) {
        return a->getRelevance() > b->getRelevance();
    });
}

std::vector<Word*> Autocomplete::getAutocompleteSet(std::string& userInput)
{
  std::vector<Word*> Vcomp = db->searchWordsAutocomplete(userInput);
  sortByRelevance(Vcomp);
  return Vcomp;
}