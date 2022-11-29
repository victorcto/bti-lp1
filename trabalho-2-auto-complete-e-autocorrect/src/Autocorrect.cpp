#include "Autocorrect.hpp"

Autocorrect::Autocorrect(Database* db)
{
  this->db = db;
}

int min(int x, int y){
  return std::min(x, y); 
}

unsigned int Autocorrect::editDistance(const std::string& s1, const std::string& s2) 
{
  int m = s1.length();
  int n = s2.length();

  int ** dp = new int * [s1.length() + 1];

  for (int i = 0; i < s1.length() + 1; i++)
    dp[i] = new int[s2.length() + 1];

  dp[0][0] = 0;

  for (int i = 1; i < m + 1; i++)
    dp[i][0] = i;

  for (int i = 1; i < n + 1; i++)
    dp[0][i] = i;

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (s1[m - i] == s2[n - j])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
    }
  }

  return dp[m][n];
}

std::vector<Word*> Autocorrect::getAutocorrectSet(std::string& userInput, bool isTest)
{
  std::vector<Word*> Vcorr = db->searchWordsAutocorrect(new Word(0, userInput), isTest);
  return Vcorr;
}

